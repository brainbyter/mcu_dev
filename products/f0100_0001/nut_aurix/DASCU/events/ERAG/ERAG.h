#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 100

struct CanFrame
{
    uint32_t id;
    char data[9];
};

extern unsigned char ERAG_Longitude_degrees;
extern unsigned char ERAG_Longitude_min;
extern unsigned int ERAG_Longitude_min_fract;
extern unsigned char ERAG_Longitude_sign;      // 'W' = 1 (negative), 'E' = 0 (positive)
extern unsigned char ERAG_Latitude_degrees;
extern unsigned char ERAG_Latitude_min;
extern unsigned int ERAG_Latitude_min_fract;
extern unsigned char ERAG_Latitude_sign;       // 'S' = 1 (negative), 'N' = 0 (positive)
extern unsigned char g_trust_status;           // message trust flag (0 = trust, 1 = can't trust)
extern float ERAG_Speed;
extern float ERAG_Course;

// Global var (g_ = global)
extern struct CanFrame g_f;
extern bool g_fNMEA;                    // flag message with correct id
extern uint32_t g_last_id;              // id of the previous message to track the order
extern bool g_start;
extern char g_nmea_mes[SIZE];
extern float ERAG_Latitude;
extern float ERAG_Longitude;
extern unsigned short ERAG_Year;
extern unsigned char ERAG_Month;
extern unsigned char ERAG_Day;
extern unsigned char ERAG_Hours;
extern unsigned char ERAG_Minutes;
extern unsigned char ERAG_Seconds;

//functions prototypes
extern int handlerMes();
extern int check_id ();                           	// compare id last mess and id current mess
extern void append_to_g_nmea_mes (const char *str); // compose unified NMEA mes
extern void checksum_check ();
extern int comma_count ();                        	// count ',' in NMEA mes
extern void availability_check  (int i);
extern void nmea_parser_gpgga ();
extern void nmea_parser_gprmc ();
extern float get_coord (int i);
extern void get_coord_for_perc (int i, unsigned char* degrees, unsigned char* min, unsigned int* min_fract, unsigned char* sign);
extern void get_time (int i);
extern void get_date (int i);
float get_speed (int i);
float get_course (int i);

extern unsigned int t_gga_input;
extern unsigned int t_gga_output;
extern unsigned int t_rmc_input;
extern unsigned int t_rmc_output;

