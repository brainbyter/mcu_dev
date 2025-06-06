#include <stdint.h>
#include <string.h>
#include <UDP_IC_Handlers.h>
#include <../MCMCAN/Generated/CAN.h>

#include <CAN_Mapping.h>


void UDP_IC_Visual_Handler(uint8* data)
{
	memcpy(&data[0], &VisEgoZone, 1);
	memcpy(&data[1], &VisObj1DistLong, 4);
	memcpy(&data[5], &VisObj1Zone, 1);
	memcpy(&data[6], &VisObj1Orient, 1);
	memcpy(&data[7], &VisObj1_Type, 1);
	memcpy(&data[8], &VisObjDynam1ID, 1);
	memcpy(&data[9], &VisObj2DistLong, 4);
	memcpy(&data[13], &VisObj2Zone, 1);
	memcpy(&data[14], &VisObj2Orient, 1);
	memcpy(&data[15], &VisObj2_Type, 1);
	memcpy(&data[16], &VisObjDynam2ID, 1);
	memcpy(&data[17], &VisObj3DistLong, 4);
	memcpy(&data[21], &VisObj3Zone, 1);
	memcpy(&data[22], &VisObj3Orient, 1);
	memcpy(&data[23], &VisObj3_Type, 1);
	memcpy(&data[24], &VisObjDynam3ID, 1);
	memcpy(&data[25], &VisObj4DistLong, 4);
	memcpy(&data[29], &VisObj4Zone, 1);
	memcpy(&data[30], &VisObj4Orient, 1);
	memcpy(&data[31], &VisObj4_Type, 1);
	memcpy(&data[32], &VisObjDynam4ID, 1);
	memcpy(&data[33], &VisObj5DistLong, 4);
	memcpy(&data[37], &VisObj5Zone, 1);
	memcpy(&data[38], &VisObj5Orient, 1);
	memcpy(&data[39], &VisObj5_Type, 1);
	memcpy(&data[40], &VisObjDynam5ID, 1);
	memcpy(&data[41], &VisObj6DistLong, 4);
	memcpy(&data[45], &VisObj6Zone, 1);
	memcpy(&data[46], &VisObj6Orient, 1);
	memcpy(&data[47], &VisObj6_Type, 1);
	memcpy(&data[48], &VisObjDynam6ID, 1);
	memcpy(&data[49], &VisObj7DistLong, 4);
	memcpy(&data[53], &VisObj7Zone, 1);
	memcpy(&data[54], &VisObj7Orient, 1);
	memcpy(&data[55], &VisObj7_Type, 1);
	memcpy(&data[56], &VisObjDynam7ID, 1);
	memcpy(&data[57], &VisObj8DistLong, 4);
	memcpy(&data[61], &VisObj8Zone, 1);
	memcpy(&data[62], &VisObj8Orient, 1);
	memcpy(&data[63], &VisObj8_Type, 1);
	memcpy(&data[64], &VisObjDynam8ID, 1);
	memcpy(&data[65], &VisObj9DistLong, 4);
	memcpy(&data[69], &VisObj9Zone, 1);
	memcpy(&data[70], &VisObj9Orient, 1);
	memcpy(&data[71], &VisObj9_Type, 1);
	memcpy(&data[72], &VisObjDynam9ID, 1);
	memcpy(&data[73], &VisLaneLType, 1);
	memcpy(&data[74], &VisLaneRType, 1);
	memcpy(&data[75], &VisLaneLLType, 1);
	memcpy(&data[76], &VisLaneRRType, 1);
	memcpy(&data[77], &VisRoadAngleLvl, 1);
}
