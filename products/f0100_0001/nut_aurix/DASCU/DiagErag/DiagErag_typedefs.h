#ifndef _DIAGERAG_TYPEDEFS_H_
#define _DIAGERAG_TYPEDEFS_H_

#include <stdint.h>
#include <Platform_Types.h>
#include "Diag_typedefs.h"

typedef enum {
	EragNoService_0x00=0x00,
	EragDiagnosticSessionControlService_0x10=0x10,
	EragSecurityAccessService_0x27=0x27,
	EragTesterPresentService_0x3E=0x3E,
	EragRoutineControlService_0x31=0x31,
	EragReadDataById_0x22=0x22
} Erag_supported_services_t;

typedef enum {
	EragnoError = 0x00,
	EragSubFunctionNotSupported_0x12 = 0x12,
	EragincorrectMessaheLenghtOrInvalidFormat_0x13=0x13,
	EragconditionsNotCorrect=0x22,
	EragrequestOutOfRange = 0x31
} Erag_NRC_Codes_t;


typedef enum
{
	SOS_Call = 0x18E6
} Erag_did_list_t;


typedef enum {SOS_Idle, SOS_AwaitResp, SOS_SendExtSess, SOS_SendRND, SOS_SendKey, SOS_SendRoutineSos, SOS_Await_Result, SOS_SendDefSess, SOS_WAIT_DEBUG} SOS_State_t;
typedef struct
{
	uint32 lastTimeIncMessage;
	uint8 countTryRequest;
	SOS_State_t SOS_State;
	SOS_State_t last_SOS_State;
	unsigned char TesterPresetServEn;
	unsigned int TesterPresetServLastTimeMessage;
	unsigned int startTimeAwaitEragStatus;
} ERAG_SOS_FSM_t;


#endif
