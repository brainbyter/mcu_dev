#ifndef _DIAG_TYPEDEFS_H_
#define _DIAG_TYPEDEFS_H_
#include "stdint.h"
#include <string.h>
#include <Platform_Types.h>
#include "bsp_can.h"

#include "..\ext_vars.h"

#define PRC_0x40 0x40
#define NRC_0x7F 0x7F

#define SID_COUNT 26
#define NRC_COUNT 16

typedef enum {UDS_SEED, UDS_KEY} TypeSecureAccess_t;

typedef enum 
{
	DiagnosticSessionControl_0x10 = 0x10,
	ECUReset_0x11 = 0x11,
	SecurityAccess_0x27 = 0x27,
	CommunicationControl_0x28 = 0x28,
	TesterPresent_0x3E = 0x3E,
	AccessTimingParameter_0x83 = 0x83,
	SecuredDataTransmission_0x84 = 0x84,
	ControlDTCSetting_0x85 = 0x85,
	ResponceOnEvent_0x86 = 0x86,
	LinkControl_0x87 = 0x87,
	ReadDataByIdentifier_0x22 = 0x22,
	ReadMemoryByAddress_0x23 = 0x23,
	ReadScalingDataByIdentifier_0x24 = 0x24,
	ReadDataByPeriodicIdentifier_0x2A = 0x2A,
	DynamicallyDefineDataIdentifier_0x2C = 0x2C,
	WriteDataByIdentifier_0x2E = 0x2E,
	WriteMemoryByAddress_0x3D = 0x3D,
	ClearDiagnosticInformation_0x14 = 0x14,
	ReadDTCInformation_0x19 = 0x19,
	IOControlByIdentidier_0x2F = 0x2F,
	RoutineControl_0x31 = 0x31,
	RequestDownload_0x34 = 0x34,
	RequestUpload_0x35 = 0x35,
	TransferData_0x36 = 0x36,
	RequestTransferExit_0x37 = 0x37,
	RequestFileTransfer_0x38 = 0x38
} supported_sid_t;

typedef enum 
{
	positiveResponse = 0x00,
	serviceNotSupported_0x11 = 0x11,
	subFunctionNotSupported_0x12 = 0x12,
	incorrectMessageLengthOrInvalidFormat_0x13 = 0x13,
	responseTooLong_0x14 = 0x14,
	conditionsNotCorrect_0x22 = 0x22,
	requestSequenceError_0x24 = 0x24,
	requestOutOfRange_0x31 = 0x31,
	securityAccessDenied_0x33 = 0x33,
	invalidKey_0x35 = 0x35,
	exceedNumberOfAttempts_0x36 = 0x36,
	requiredTimeDelayNotExpired_0x37 = 0x37,
	uploadDownloadNotAccepted_0x70 = 0x70,
	transferDataSuspended_0x71 = 0x71,
	generalProgrammingFailure_0x72 = 0x72,
	wrongBlockSequenceCounter_0x73 = 0x73,
	voltageTooHigh_0x92 = 0x92,
	voltageTooLow_0x93 = 0x93
} NRC_list_t;

typedef enum {
    SINGLE_FRAME = 0x00,
    FIRST_FRAME = 0x01,
    CONSECUTIVE_FRAME = 0x02,
    FLOW_CONTROL_FRAME = 0x03,
} frame_t;

typedef enum {
    DefaultSession = 0x01,
    ProgrammingSession = 0x02,
    ExtendedSession = 0x03
} session_t;

typedef enum {
    isIdle = 0x00,
    isRequest,
    isDidNotFound
} flg_request_t;

typedef struct
{
	uint16_t LEN;
	uint8_t SID;
	uint16_t DID;
	uint8_t PRC;
    NRC_list_t NRC;
    uint8_t subfunc_code;
    flg_request_t flg_request;
	uint8 useDid;
    uint8 useMultiDids;
    uint8 DidsCount;
	uint8_t FC_reqEn;
	uint8 FC_FLAG;
	uint8 FC_BS;
	uint8 FC_ST;
	uint16_t *MultiDIDs;
	uint8 useRoutine;
} frame_state_t;

typedef struct
{
	session_t session_type;
	frame_t frame_type;
	frame_state_t frame_status;
	uint32 lastMessageTime;
	uint8 Flag;				
	uint8 BS;
	uint16 ST;
	uint16 targetLen;
	sint32 reminderLen;
	uint16 frameCounter;
	uint8 frameNumber;
	uint8 *p_next_data;
	uint8 reqDid;
	uint8 flgSendImage;
	uint8 flgConsecFrSended;
} uds_state_t;

typedef struct{
	supported_sid_t sid;
	NRC_list_t NRC_list[16];
    void (*sid_handler)(uds_state_t *, unsigned char*, frame_t);
} SID_desc_t;

typedef enum
{
    DASCU_DID_F1F1 = 0xF1F1,
    DASCU_DID_F1F2 = 0xF1F2,
    DASCU_DID_F1F3 = 0xF1F3,
    DASCU_DID_F1F4 = 0xF1F4,
    DASCU_DID_F1F5 = 0xF1F5,
    DASCU_DID_F1F6 = 0xF1F6,
    DASCU_DID_F1F7 = 0xF1F7,
    DASCU_DID_F1F8 = 0xF1F8,
    DASCU_DID_F1F9 = 0xF1F9,
    DASCU_DID_F1FA = 0xF1FA,
} did_dascu_list_t;

typedef union _un
{
    unsigned char session_support;
    struct
    {
        unsigned char readDefaultSession: 1;
        unsigned char readProgrammingSession: 1;
        unsigned char readExtendedSession: 1;
        unsigned char writeDefaultSession: 1;
        unsigned char writeProgrammingSession: 1;
        unsigned char writeExtendedSession: 1;
        unsigned char :2;
    } flags;
} did_support_session_t;

typedef struct
{
    unsigned short did;
    did_support_session_t supp_sess;
    void (*prepare_data_handler)(unsigned char*);
    uint16 dataLenghtInBytes;
} dids_dascu_list_t;

/* EXTERN VARIABLES */
extern SID_desc_t SID_desc[16];
extern uds_state_t uds_state_dascu;

/* FUNCTIONS */
extern void Diag_dascu_process_receive(uds_state_t *uds_state, can_msg_t *rx_msg);
extern void Single_Frame_Handler(uds_state_t *uds_state, uint8* data);
extern void First_Frame_Handler(uds_state_t *uds_state, uint8* data);
extern void Consecutive_Frame_Handler(uds_state_t *uds_state, uint8* data);
extern void FlowControl_Frame_Handler(uds_state_t *uds_state, uint8* data);

extern void answerFrame(uds_state_t *uds_state);
extern void checkServiceId(uds_state_t *uds_state, uint8 sid, uint8* data, frame_t frame_type);
extern unsigned short checkDataLenghtDid(unsigned short target_did, unsigned char* data);

extern void prepareSingleFrame(uds_state_t *uds_state, uint8* data);
extern void prepareFirstFrame(uds_state_t *uds_state, uint8* data);
extern void prepareConsecutiveFrame(uds_state_t *uds_state, uint8* data);
extern void prepareFlowControlFrame(uds_state_t *uds_state, uint8* data);
extern void prepareNRCFrame(uds_state_t *uds_state, uint8* data);

void DiagnosticSessionControl_0x10_handler(uds_state_t *uds_state, unsigned char *data, frame_t frame);
void ECUReset_0x11_handler(uds_state_t *uds_state, unsigned char *data, frame_t frame);
void ReadDataByIdentifier_0x22_handler(uds_state_t *uds_state, unsigned char *data, frame_t frame);
void WriteDataByIdentifier_0x2E_handler(uds_state_t *uds_state, unsigned char *data, frame_t frame);
void SecurityAccess_0x27_handler();
void CommunicationControl_0x28_handler();
void TesterPresent_0x3E_handler();
void AccessTimingParameter_0x83_handler();
void SecuredDataTransmission_0x84_handler();
void ControlDTCSetting_0x85_handler();
void ResponceOnEvent_0x86_handler();
void LinkControl_0x87_handler();
void ReadMemoryByAddress_0x23_handler();
void ReadScalingDataByIdentifier_0x24_handler();
void ReadDataByPeriodicIdentifier_0x2A_handler();
void DynamicallyDefineDataIdentifier_0x2C_handler();
void WriteMemoryByAddress_0x3D_handler();
void ClearDiagnosticInformation_0x14_handler();
void ReadDTCInformation_0x19_handler();
void IOControlByIdentidier_0x2F_handler();
void RoutineControl_0x31_handler();
void RequestDownload_0x34_handler();
void RequestUpload_0x35_handler();
void TransferData_0x36_handler();
void RequestTransferExit_0x37_handler();
void RequestFileTransfer_0x38_handler();

extern void manageRequestDascu();
extern void prepareUdsImg(unsigned char *data, unsigned short len);
extern void routineSendImage(uds_state_t *uds_state);
extern unsigned char* prepareServWriteDataDascu(unsigned char *txData, unsigned char *buff, unsigned short len, unsigned short did, frame_t frame);

#endif
