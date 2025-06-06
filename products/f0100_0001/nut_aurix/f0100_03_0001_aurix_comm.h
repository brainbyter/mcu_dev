// Copyright @2023 Pony AI Inc. All rights reserved.

#ifndef PRODUCTS_F0100_0001_NUT_AURIX_COMM_H_
#define PRODUCTS_F0100_0001_NUT_AURIX_COMM_H_

#define PONY_LOCAL_DEVICE_ID kIdAdcMcu

#ifdef AB_LOADER_FIRMWARE_LOADER

#define PONY_INTERFACE_TABLE \
  { {false, kInterfaceUart, 0}, \
    {true, kInterfaceCan, 0}, }

#define PONY_ROUTE_TABLE \
  { {kIdOnboard, kInterfaceUart, 0}, \
    {kIdUpdater, kInterfaceCan, 0},}

#else

#define PONY_INTERFACE_TABLE \
  { {false, kInterfaceUart, 0}, \
    {true, kInterfaceCan, 0}, \
    {true, kInterfaceLwipTcpSever, 0}, \
    {true, kInterfaceLwipTcpSever, 2}, }

#define PONY_ROUTE_TABLE \
  { {kIdOnboard, kInterfaceUart, 0}, \
    {kIdAdcOrinUpdater, kInterfaceLwipTcpSever, 0}, \
    {kIdAdcMcu2, kInterfaceLwipTcpSever, 2}, \
    {kIdUpdater, kInterfaceCan, 0}, }

#endif

#endif  // PRODUCTS_F0100_0001_NUT_AURIX_COMM_H_
