#include "platform/system/debug.h"
#include "ERAG.h"
#include <bsp_can.h>
#include <Platform_Types.h>
#include "I_DIAG_DAS.h"

bool g_fNMEA = false;
struct CanFrame g_f = {.id = 0, .data = ""};
uint32_t g_last_id = 0;
bool g_start = 0;
char g_nmea_mes[SIZE] = "";

float ERAG_Latitude = 0.0;
float ERAG_Longitude = 0.0;
//struct Date_time g_t = {.year = 0, .month = 0, .day = 0, .hours = 0, .min = 0, .sec = 0};
unsigned short ERAG_Year = 0;
unsigned char ERAG_Month = 0;
unsigned char ERAG_Day = 0;
unsigned char ERAG_Hours = 0;
unsigned char ERAG_Minutes = 0;
unsigned char ERAG_Seconds = 0;
float ERAG_Speed = 0.;
float ERAG_Course = 0.;
unsigned char g_trust_status = 1;
unsigned char ERAG_Longitude_degrees;
unsigned char ERAG_Longitude_min;
unsigned int ERAG_Longitude_min_fract;
unsigned char ERAG_Longitude_sign;      // 'W' = 1 (negative), 'E' = 0 (positive)
unsigned char ERAG_Latitude_degrees;
unsigned char ERAG_Latitude_min;
unsigned int ERAG_Latitude_min_fract;
unsigned char ERAG_Latitude_sign;       // 'S' = 1 (negative), 'N' = 0 (positive)



int handlerMes()
{
    g_fNMEA = 0;

    if (strncmp (g_f.data, "", 8))
    {
        if (check_id() == 0)
        {
            if ((g_start == 0) && (strlen(g_nmea_mes) > 0))
            {
            	//////**Printf("NMEA message:  %s\n", g_nmea_mes);
                checksum_check ();
                if (g_trust_status == 1)
                    {
                        //////**printf("checksum don't match\n");
                        return -1;
                    }
                if (!strncmp (g_nmea_mes, "$GPGGA ", 6))
                {
                	//////**Printf("processed $GPGGA message\n");
                    if (comma_count() != 14)
                    {
                    	//////**Printf("commas don't match in $GPGGA\n");
                        return -1;
                    }
                    else
                    {
/*
                        nmea_parser_gpgga();
                        if (g_trust_status == 1)
                        {
                            //////**printf("we didn't get an important parameter\n");
                            return -1;
                        }
*/
                        return 0;
                    }
                }
                else if (!strncmp (g_nmea_mes, "$GPRMC", 6))
                {
                	//////**Printf("processed $GPRMC message\n");
                    if (comma_count() != 12)
                    {
                    	//////**Printf("commas don't match in $GPRMC\n\n");
                        return -1;
                    }
                    else
                    {
                        nmea_parser_gprmc();
                        if (g_trust_status == 1)
                        {
                            //////**printf("we didn't get an important parameter\n");
                            return -1;
                        }
                        return 0;
                    }
                }
                else
                {
                	//////**Printf("start of g_nmea_mes - not $GPGGA and not $GPRMC string\n\n");
                    return -1;
                }
            }
        } //end of checking that everything arrived in order
        else
        {
        	//////**Printf("function check_id return error\n");
            return -1;
        }

        return 0;
    } //end check for empty string
    else
    {
    	return -1;
    }
}

void append_to_g_nmea_mes (const char *str)
{
    // g_nmea_mes long (before the first '\0')
    int g_nmea_mes_len = strlen (g_nmea_mes);

    if ((g_nmea_mes_len + 8) >= SIZE)
    {
        //////**Printf("not enough space in g_nmea_mes\n");
        return;
    }
    strncat (g_nmea_mes, str, 8);
}

int check_id ()
{
    if ((g_last_id == 0) || ((g_f.id - g_last_id) == 2) || ((g_last_id - g_f.id) == 10))
    {
        g_last_id = g_f.id;
        if ((!strncmp (g_f.data, "$GPGGA", 6)) || (!strncmp (g_f.data, "$GPRMC", 6))) //start of message
        {
            if (!g_start)
            {
                memset(g_nmea_mes, 0, SIZE);
                g_start = 1;
                append_to_g_nmea_mes(g_f.data);
                return 0;
            }
            else
            {
                //////**Printf("it's start of message, but g_start == true already\n");
                memset(g_nmea_mes, 0, SIZE);
                g_last_id = 0;
                g_start = 0;
            	return -1;
            }
        }
        else if ((strrchr(g_f.data, '\n') != NULL) && (g_start == 1)) //end of message
        {
            append_to_g_nmea_mes(g_f.data);
            g_start = 0;
        }
        else if (g_start == 1)
        {
        	append_to_g_nmea_mes(g_f.data);
        }
        else if (g_start == 0)
        {}
        ////////**Printf("start flag: %d\n", g_start);
        ////////**Printf("NMEA message: %d\n",  g_nmea_mes);
    }
    else
    {
        //////**Printf("Something got lost somewhere!\n");
        memset(g_nmea_mes, 0, SIZE);
        g_last_id = 0;
        g_start = 0;
        return -1;
    }
    return 0;
}

void checksum_check ()
{
    int summ = 0x0;
    int i = 0;
    do 
    {
        if (g_nmea_mes[i] != '$')
            summ = summ ^ g_nmea_mes[i];
        i++; 
    } while (g_nmea_mes[i] != '*');

    int temp = 0;
    temp = strtol(g_nmea_mes + i + 1, NULL, 16);

    if (temp != summ)
        g_trust_status = 1;
    else g_trust_status = 0;
}

int comma_count ()
{
    int n = 0; //comma counter

    for (int i = 0; i < SIZE; i++)
    {
        if (g_nmea_mes[i] == ',')
        {
            n++;
        }
    }
    return n;
}

// get double, example 3732.64250
// we need 37 + (32.64250 / 60), move 32.64250 in tmp
// i - number first coordinate symbol
float get_coord (int i)
{
    char * end = strchr((g_nmea_mes + i + 1), ',');
    char * point = strchr((g_nmea_mes + i + 1), '.');
    uint8_t tmp_len = (uint64)end - (uint64)(point - 2);

    char str[15] = "";
    strncpy(str, (point - 2), tmp_len);
    float tmp = atof(str);

    memset(str, 0, 15);
    strncpy(str, (g_nmea_mes + i + 1), (point - 3 - g_nmea_mes - i)); //degrees
    float coord = atof(str) + tmp / 60;  // like 37 + (32.64250 / 60)

    if (g_nmea_mes[end - g_nmea_mes + 1] == 'S' || g_nmea_mes[end - g_nmea_mes + 1] == 'W') {
        coord = coord * (-1); //single
    }

    return coord;
}

// get coordinate for perception 
// we have 3732.64250 , we need degree = 37, min = 32, min_fract = 64250
void get_coord_for_perc (int i, unsigned char* degrees, unsigned char* min, unsigned int* min_fract, unsigned char* sign)
{
    char * end = strchr((g_nmea_mes + i + 1), ','); 
    char * point = strchr((g_nmea_mes + i + 1), '.');

    char str[10] = "";
    // char *strncpy(char *dest, const char *source, size_t count)
    *degrees = atoi(strncpy(str, (g_nmea_mes + i + 1), (point - 3 - g_nmea_mes - i)));
    memset(str, 0, 10);
    *min = atoi(strncpy(str, (point - 2), 2));
    memset(str, 0, 10);
    *min_fract = atoi(strncpy(str, (point + 1), ((uint64)end - (uint64)point)));

    if (g_nmea_mes[end - g_nmea_mes + 1] == 'S' || g_nmea_mes[end - g_nmea_mes + 1] == 'W') {
        *sign = 1;
    } else if (g_nmea_mes[end - g_nmea_mes + 1] == 'N' || g_nmea_mes[end - g_nmea_mes + 1] == 'E') {
        *sign = 0;
    }
}

void get_time (int i)
{
    char time_str[3] = ""; // hhmmss

    //g_t.hours = atoi(strncpy(time_str, &g_nmea_mes[i+1], 2));
    ERAG_Hours = (unsigned char)atoi(strncpy(time_str, &g_nmea_mes[i+1], 2));
    memset(time_str, 0, 3);
    //g_t.min = atoi(strncpy(time_str, &g_nmea_mes[i+3], 2));
    ERAG_Minutes = (unsigned char)atoi(strncpy(time_str, &g_nmea_mes[i+3], 2));
	memset(time_str, 0, 3);
    //g_t.sec = atoi(strncpy(time_str, &g_nmea_mes[i+5], 2));
	ERAG_Seconds = (unsigned char)atoi(strncpy(time_str, &g_nmea_mes[i+5], 2));
	DfEragHours = ERAG_Hours;
	DfEragMinutes = ERAG_Minutes;
	DfEragSeconds = ERAG_Seconds;
}

void get_date (int i)
{
    char date_str[3] = ""; // ddmmyy

    //g_t.day = atoi(strncpy(date_str, &g_nmea_mes[i+1], 2));
    ERAG_Day = (unsigned char)atoi(strncpy(date_str, &g_nmea_mes[i+1], 2));
    memset(date_str, 0, 3);
    //g_t.month = atoi(strncpy(date_str, &g_nmea_mes[i+3], 2));
    ERAG_Month = (unsigned char)atoi(strncpy(date_str, &g_nmea_mes[i+3], 2));
    memset(date_str, 0, 3);
    //g_t.year = atoi(strncpy(date_str, &g_nmea_mes[i+5], 2));
    ERAG_Year = (unsigned short)atoi(strncpy(date_str, &g_nmea_mes[i+5], 2));
    DfEragYear = (unsigned char)ERAG_Year;
    DfEragMonth = ERAG_Month;
    DfEragDay = ERAG_Day;
}

float get_speed (int i)
{
    char speed_str[10] = "";     // x.x speed in knots
    char * end = strchr((g_nmea_mes + i + 1), ',');
    float speed = atof(strncpy(speed_str, g_nmea_mes + i + 1, (int)(end - g_nmea_mes - i)));
    ////////**printf("speed in knots = %f\n", speed);
    return speed * 1.852;
}

float get_course (int i)
{
    char course_str[10] = "";     // x.x course in degrees
    char * end = strchr((g_nmea_mes + i + 1), ',');
    float course = atof(strncpy(course_str, g_nmea_mes + i + 1, (int)(end - g_nmea_mes - i - 2)));
    ////////**printf("course in degrees = %f\n", course);
    return course;
}

void availability_check (int i)
{
    char * end = strchr((g_nmea_mes + i + 1), ',');
    if ((uint64)end == (uint64)(g_nmea_mes + i + 1))        // expected did't come (not good)
        g_trust_status = 1;         
    else if ((uint64)end != (uint64)(g_nmea_mes + i + 1))   // expected come (good)
        g_trust_status = 0;
}

void nmea_parser_gpgga ()
{
    int n = 0; //comma counter

    for (int i = 0; i < SIZE; i++)
    {
        if (g_nmea_mes[i] == ',')
        {
            n++;
            switch (n)
            {
                case 1:		//time
                    availability_check  (i);
                    if (g_trust_status == 1)
                        return;
                    get_time (i);
                    break;
                case 2:		//latitude
                    availability_check  (i);
                    if (g_trust_status == 1)
                        return;
                    ERAG_Latitude = get_coord (i);
                    get_coord_for_perc (i, &ERAG_Latitude_degrees, &ERAG_Latitude_min, &ERAG_Latitude_min_fract, &ERAG_Latitude_sign);
                    break;
                case 4:		//longitude
                    availability_check  (i);
                    if (g_trust_status == 1)
                        return;
                	ERAG_Longitude = get_coord (i);
                    get_coord_for_perc (i, &ERAG_Longitude_degrees, &ERAG_Longitude_min, &ERAG_Longitude_min_fract, &ERAG_Longitude_sign);
                    break;
                default:	//everything else
                    {}
            }
        }
    }
}

void nmea_parser_gprmc ()
{
    int n = 0; //comma counter

    for (int i = 0; i < SIZE; i++)
    {
        if (g_nmea_mes[i] == ',')
        {
            n++;
            switch (n)
            {
                case 1:		//time
                    availability_check  (i);
                    if (g_trust_status == 1)
                        return;
                    get_time (i);

                    break;
                case 3:		//latitude
                    availability_check  (i);
                    if (g_trust_status == 1)
                        return;
                	ERAG_Latitude = get_coord (i);
                    get_coord_for_perc (i, &ERAG_Latitude_degrees, &ERAG_Latitude_min, &ERAG_Latitude_min_fract, &ERAG_Latitude_sign);
                    break;
                case 5:		//longitude
                    availability_check  (i);
                    if (g_trust_status == 1)
                        return;
                	ERAG_Longitude = get_coord (i);
                    get_coord_for_perc (i, &ERAG_Longitude_degrees, &ERAG_Longitude_min, &ERAG_Longitude_min_fract, &ERAG_Longitude_sign);
                    break;
                case 7:
					availability_check  (i);
					if (g_trust_status == 1)
						return;
					ERAG_Speed = get_speed (i);
					break;
				case 8:
					availability_check  (i);
					if (g_trust_status == 1)
						return;
					ERAG_Course = get_course (i);
					break;
				case 9:		//date
					availability_check  (i);
					if (g_trust_status == 1)
						return;
					get_date (i);
					break;
                default:	//everything else
                    {}
            }
        }
    }
}
