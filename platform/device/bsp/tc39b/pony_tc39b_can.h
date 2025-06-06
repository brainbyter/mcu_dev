// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_TC39B_PONY_TC39B_CAN_H_
#define PLATFORM_TC39B_PONY_TC39B_CAN_H_

// CAN node mapping table
// Because there are 3 MCMCAN for TC397. Each MCMCAN has 4 CAN nodes. We map these 12 CAN nodes to
// 12 CAN devices.
// NOTE: CanClose will close a MCMCAN for a target CAN node, which means will also close other nodes
// under this MCMCAN. So please reopen all the CAN nodes under this MCMCAN.
// | MCMCAN0 NODE0 | CAN0  |
// | MCMCAN0 NODE1 | CAN1  |
// | MCMCAN0 NODE2 | CAN2  |
// | MCMCAN0 NODE3 | CAN3  |
// | MCMCAN1 NODE0 | CAN4  |
// | MCMCAN1 NODE1 | CAN5  |
// | MCMCAN1 NODE2 | CAN6  |
// | MCMCAN1 NODE3 | CAN7  |
// | MCMCAN2 NODE0 | CAN8  |
// | MCMCAN2 NODE1 | CAN9  |
// | MCMCAN2 NODE2 | CAN10 |
// | MCMCAN2 NODE3 | CAN11 |

#endif  // PLATFORM_TC39B_PONY_TC39B_CAN_H_
