/* if defined HW_DEBUG then all block used for debugger will be enable */
#define HW_DEBUG

/* Choose a car for compile version */
#define SW_AURUS
//#define SW_HAVAL


// if PWR_MAN_EN defined then using T15 for running GPU

#define PWR_MAN_EN

extern uint8 fPrepareToFirmware;
#ifdef HW_DEBUG
extern unsigned char rdyToConnectXcp;
extern unsigned int dtConnectXcp;
extern unsigned char rdyToConnectDebug;
extern unsigned int dtConnectDebug;
#endif
extern unsigned char rdyToConnectAdas;
extern unsigned int dtConnectAdas;
