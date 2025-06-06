#include "Diag_typedefs.h"
#include "../MCMCAN/Generated/ADASCANFD/ADASCANFD_MessageObjects.h"
#include "../MCMCAN/CAN_Private.h"
#include "dids.h"

dids_dascu_list_t dids_dascu_list[10] = {
        {.did = DASCU_DID_F1F1, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=TRUE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=FALSE, .prepare_data_handler=DASCU_DID_F1F1_Prepare, .dataLenghtInBytes=4},
        {.did = DASCU_DID_F1F2, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=FALSE, .prepare_data_handler=DASCU_DID_F1F2_Prepare,.dataLenghtInBytes=4},
        {.did = DASCU_DID_F1F3, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=TRUE, .prepare_data_handler=DASCU_DID_F1F3_Prepare,.dataLenghtInBytes=2},
        {.did = DASCU_DID_F1F4, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=FALSE, .prepare_data_handler=DASCU_DID_F1F4_Prepare,.dataLenghtInBytes=5},
        {.did = DASCU_DID_F1F5, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=TRUE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = TRUE, .supp_sess.flags.writeExtendedSession=TRUE, .prepare_data_handler=DASCU_DID_F1F5_Prepare,.dataLenghtInBytes=8},
        {.did = DASCU_DID_F1F6, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=TRUE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = TRUE, .supp_sess.flags.writeExtendedSession=TRUE, .prepare_data_handler=DASCU_DID_F1F6_Prepare,.dataLenghtInBytes=8},
        {.did = DASCU_DID_F1F7, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=TRUE, .prepare_data_handler=DASCU_DID_F1F7_Prepare,.dataLenghtInBytes=8},
        {.did = DASCU_DID_F1F8, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=FALSE, .prepare_data_handler=DASCU_DID_F1F8_Prepare,.dataLenghtInBytes=8},
        {.did = DASCU_DID_F1F9, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=FALSE, .prepare_data_handler=DASCU_DID_F1F9_Prepare, .dataLenghtInBytes=8},
        {.did = DASCU_DID_F1FA, .supp_sess.flags.readDefaultSession = TRUE, .supp_sess.flags.readProgrammingSession=FALSE, .supp_sess.flags.readExtendedSession=TRUE, .supp_sess.flags.writeDefaultSession=FALSE, .supp_sess.flags.writeProgrammingSession = FALSE, .supp_sess.flags.writeExtendedSession=FALSE, .prepare_data_handler=DASCU_DID_F1FA_Prepare, .dataLenghtInBytes=8},
};

unsigned short checkDataLenghtDid(unsigned short target_did, unsigned char* data)
{
    int i;
    uint16 retLenght = 0;
    target_did = (target_did&0xFF00)>>8 | (target_did&0x00FF)<<8;   /* SWAP DID !!!*/

    for (i=0; i < 10; i++)
    {
        if (target_did == dids_dascu_list[i].did)
        {
            retLenght = dids_dascu_list[i].dataLenghtInBytes;
            memcpy(data, &target_did, 2);
            dids_dascu_list[i].prepare_data_handler(&data[2]);
            break;
        }
    }

    return retLenght;
}



void DASCU_DID_F1F1_Prepare(unsigned char *data)
{
    uint32 d;
    float l_AccelPedalPos = 1.5;
    d = *(unsigned int*)&l_AccelPedalPos; // for example
    memcpy(data, &d, 4);
    data += 4;
}

void DASCU_DID_F1F2_Prepare(unsigned char *data)
{
    uint32 d;
    float l_VehicleSpd = 15.0;
    d = *(unsigned int*)&l_VehicleSpd; // for example
    memcpy(data, &d, 4);
    data +=4;
}

void DASCU_DID_F1F3_Prepare(unsigned char *data)
{

}

void DASCU_DID_F1F4_Prepare(unsigned char *data)
{

}

void DASCU_DID_F1F5_Prepare(unsigned char *data)
{

}

void DASCU_DID_F1F6_Prepare(unsigned char *data)
{

}

void DASCU_DID_F1F7_Prepare(unsigned char *data)
{

}

void DASCU_DID_F1F8_Prepare(unsigned char *data)
{

}

void DASCU_DID_F1F9_Prepare(unsigned char *data)
{

}

void DASCU_DID_F1FA_Prepare(unsigned char *data)
{

}
