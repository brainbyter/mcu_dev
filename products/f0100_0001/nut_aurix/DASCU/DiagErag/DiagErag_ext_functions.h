#include <Platform_Types.h>
#include <stdint.h>
#include "Diag_typedefs.h"
#include "DiagErag_typedefs.h"


extern void configEragSos();
extern void manageEragRequest();
extern void udsExitSos();
extern void prepareEragServChangeSession(unsigned char *data, unsigned char subFunc);
extern void prepareEragServSecurutyAccess(unsigned char *data, unsigned char subFunc, unsigned int param, TypeSecureAccess_t TypeSecureAccess);
extern void prepareEragServRoutineControl(unsigned char *data, unsigned short len, unsigned char subFunc, unsigned short did);
extern void prepareEragServTesterPresent(unsigned char *data, unsigned char subFunc);

extern void eragDiagState();
extern void requestEragCoords();
extern void prepareEragServReadDataById(unsigned char *data, unsigned short did);

