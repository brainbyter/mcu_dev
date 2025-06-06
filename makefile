### Template required start
PROJECT = f0100-08-0000-sdk
PROJECT_DIR = f0100-08-0000-sdk 

LINK_FILE = 




ifeq ($(slot_type), SLOT_A)
PROJECT := ${PROJECT}_SLOT_A
LINK_FILE := products/f0100_0001/nut_aurix/app_a_config.lsl

SLOT_CFLAGS = -DAB_LOADER_FIRMWARE_SLOT_A \

endif



ifeq ($(slot_type), SLOT_B)
PROJECT := ${PROJECT}_SLOT_B
LINK_FILE := products/f0100_0001/nut_aurix/app_b_config.lsl

SLOT_CFLAGS = -DAB_LOADER_FIRMWARE_SLOT_B \

endif

INCLUDE_PATH = ./ \
INCLUDE_PATH = ./ \
./common/driver/bootchain \
./common/driver/eeprom \
./common/driver/flash \
./common/driver/marvell \
./common/driver/maxim \
./common/driver/micro_chip \
./common/driver/mps \
./common/driver/nxp \
./common/driver/phy \
./common/driver/rtc \
./common/driver/ti \
./common/mcu/system \
./common/mcu/utils \
./common/third_party/md5 \
./common/utilities \
./external/aurix_tc39b_illd/. \
./external/aurix_tc39b_illd/Infra/Platform \
./external/aurix_tc39b_illd/Infra/Platform/Tricore/Compilers \
./external/aurix_tc39b_illd/Infra/Sfr/TC39B/_Reg \
./external/aurix_tc39b_illd/Infra/Ssw/TC39B/Tricore \
./external/aurix_tc39b_illd/Service \
./external/aurix_tc39b_illd/Service/CpuGeneric \
./external/aurix_tc39b_illd/Service/CpuGeneric/If \
./external/aurix_tc39b_illd/Service/CpuGeneric/If/Ccu6If \
./external/aurix_tc39b_illd/Service/CpuGeneric/StdIf \
./external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Bsp \
./external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Comm \
./external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/General \
./external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math \
./external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Time \
./external/aurix_tc39b_illd/Service/CpuGeneric/_Utilities \
./external/aurix_tc39b_illd/config \
./external/aurix_tc39b_illd/config/Debug \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Asclin/Asc \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Asclin/Lin \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Asclin/Spi \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Asclin/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Can/Can \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Can/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ccu6/Icu \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ccu6/PwmBc \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ccu6/PwmHl \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ccu6/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ccu6/TPwm \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ccu6/Timer \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ccu6/TimerWithTrigger \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Convctrl/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Cpu/Irq \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Cpu/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Cpu/Trap \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Dma/Dma \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Dma/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Dts/Dts \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Dts/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ebu/BFlashSpansion \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ebu/BFlashSt \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ebu/Dram \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ebu/Sram \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ebu/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Edsadc/Edsadc \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Edsadc/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Emem/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Eray/Eray \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Eray/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Evadc/Adc \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Evadc/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Fce/Crc \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Fce/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Flash/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Geth/Eth \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Geth/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gpt12/IncrEnc \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gpt12/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Atom/Dtm_PwmHl \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Atom/Pwm \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Atom/PwmHl \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Atom/Timer \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Tim/In \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Tim/Timer \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Tom/Dtm_PwmHl \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Tom/Pwm \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Tom/PwmHl \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Tom/Timer \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Trig \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Hspdm/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Hssl/Hssl \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Hssl/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/I2c/I2c \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/I2c/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Iom/Driver \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Iom/Iom \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Iom/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Msc/Msc \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Msc/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Mtu/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Pms/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Port/Io \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Port/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Psi5/Psi5 \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Psi5/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Psi5s/Psi5s \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Psi5s/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Qspi/SpiMaster \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Qspi/SpiSlave \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Qspi/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Rif/Rif \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Rif/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Scu/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Sdmmc/Emmc \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Sdmmc/Sd \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Sdmmc/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Sent/Sent \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Sent/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Smu/Smu \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Smu/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Spu/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Src/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Stm/Std \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Stm/Timer \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Lib/DataHandling \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Lib/InternalMux \
./external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap \
./external/lwip/src/api \
./external/lwip/src/apps/lwiperf \
./external/lwip/src/core \
./external/lwip/src/core/ipv4 \
./external/lwip/src/include \
./external/lwip/src/include/lwip \
./external/lwip/src/include/lwip/apps \
./external/lwip/src/include/lwip/priv \
./external/lwip/src/include/lwip/prot \
./external/lwip/src/include/netif \
./external/lwip/src/include/netif/ppp \
./external/lwip/src/netif \
./external/nanopb \
./external/nanopb/. \
./external/tasking/ctc/include \
./external/tasking/ctc/include/ \
./external/tasking/ctc/lib/src \
./external/umsd_v5/dev/ \
./external/umsd_v5/dev/oak/include \
./external/umsd_v5/dev/oak/include/ \
./external/umsd_v5/dev/oak/include/api \
./external/umsd_v5/dev/oak/include/api/ \
./external/umsd_v5/dev/oak/include/driver \
./external/umsd_v5/dev/oak/src/api \
./external/umsd_v5/dev/oak/src/driver \
./external/umsd_v5/dev/spruce/include \
./external/umsd_v5/dev/spruce/include/ \
./external/umsd_v5/dev/spruce/include/api \
./external/umsd_v5/dev/spruce/include/driver \
./external/umsd_v5/dev/spruce/src/api \
./external/umsd_v5/dev/spruce/src/driver \
./external/umsd_v5/include \
./external/umsd_v5/include/ \
./external/umsd_v5/include/api \
./external/umsd_v5/include/api/ \
./external/umsd_v5/include/driver \
./external/umsd_v5/include/platform \
./external/umsd_v5/include/utils \
./external/umsd_v5/src/api \
./external/umsd_v5/src/driver \
./external/umsd_v5/src/platform \
./external/umsd_v5/src/utils \
./platform/component \
./platform/device/bsp \
./platform/device/bsp/. \
./platform/device/bsp/./tc39b \
./platform/device/bsp/tc39b \
./platform/device/driver \
./platform/device/driver/bootchain \
./platform/device/driver/bootloader \
./platform/device/driver/eeprom \
./platform/device/driver/ethernet_manager \
./platform/device/driver/infineon \
./platform/device/driver/lwip/. \
./platform/device/driver/lwip/./arch \
./platform/device/driver/lwip/arch \
./platform/device/driver/lwip/lwip_utils \
./platform/device/driver/lwip/netif \
./platform/device/driver/maxim \
./platform/device/driver/micro_chip \
./platform/device/driver/mps \
./platform/device/driver/nxp/tja1145 \
./platform/device/driver/phy \
./platform/device/driver/phy/marvell \
./platform/device/driver/rtc \
./platform/device/driver/storage_flash \
./platform/device/driver/switch \
./platform/device/driver/ti \
./platform/device/service \
./platform/device/utils \
./platform/product/common \
./platform/protocol \
./platform/system \
./products/f0100_0001/aurix_a/app \
./products/f0100_0001/aurix_a/sdk \
./products/f0100_0001/nut_aurix \
./products/f0100_0001/nut_aurix/app \
./products/f0100_0001/nut_aurix/DASCU/DiagMrr \
./products/f0100_0001/nut_aurix/DASCU/DiagErag \
./products/f0100_0001/nut_aurix/DASCU/Diagnostic \
./products/f0100_0001/nut_aurix/DASCU/MCMCAN \
./products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated \
./products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/ADASCANFD \
./products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/MRRX_DIAG \
./products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/TEST_FD \
./products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/MRRX_DATA \
./products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/HAVAL \
./products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/XCPCAN \
./products/f0100_0001/nut_aurix/DASCU/simulink/ADAS \
./products/f0100_0001/nut_aurix/DASCU/simulink/shared \
./products/f0100_0001/nut_aurix/DASCU/simulink/vlc \
./products/f0100_0001/nut_aurix/DASCU/UDP \
./products/f0100_0001/nut_aurix/DASCU/UDP/Generated \
./products/f0100_0001/nut_aurix/DASCU/UDP/inc \
./products/f0100_0001/nut_aurix/DASCU/UDP/IC \
./products/f0100_0001/nut_aurix/DASCU/XCP \
./products/f0100_0001/nut_aurix/DASCU/events/ERAG \
./products/f0100_0001/nut_aurix/DASCU/events/TurnIndForming \
./products/f0100_0001/nut_aurix/DASCU/events/MRRX_UDP \
./products/f0100_0001/nut_aurix/DASCU/events/AATest \
./products/f0100_0001/nut_aurix/DASCU/events/PWR_MNGMNT \
./products/f0100_0001/nut_aurix/DASCU/events/MEM \

EXT_LIBRARIES = \
-L common/driver/bootchain/libbootchain.a \
-L common/driver/eeprom/libm24cxx.a \
-L common/driver/flash/libis25lp032d.a \
-L common/driver/marvell/libswitch_common.a \
-L common/driver/maxim/libmax20087.a \
-L common/driver/micro_chip/libpac1954.a \
-L common/driver/mps/libmpq8875.a \
-L common/driver/nxp/libtja1145.a \
-L common/driver/phy/libphy_88q2112.a \
-L common/driver/rtc/libpca2131.a \
-L common/driver/ti/libtmp451.a \
-L common/mcu/system/libinit.a \
-L common/mcu/utils/libconfig_manager.a \
-L common/mcu/utils/libhexdump.a \
-L common/third_party/md5/libmd5.a \
-L common/utilities/libhwprotocol.a \
-L external/nanopb/libnanopb.a \
-L external/tasking/libstartup.a \
-L external/umsd_v5/libumsd_v5.a \
-L platform/component/libcrc.a \
-L platform/component/liblist.a \
-L platform/component/libringbuffer.a \
-L platform/device/driver/bootloader/libab_loader_main.a \
-L platform/device/driver/bootloader/libboot_control_ab.a \
-L platform/device/driver/bootloader/libfw_checker.a \
-L platform/device/driver/eeprom/libm24cxx.a \
-L platform/device/driver/ethernet_manager/libcommon.a \
-L platform/device/driver/ethernet_manager/libutils.a \
-L platform/device/driver/ethernet_manager/proto/libcommon_proto.a \
-L platform/device/driver/ethernet_manager/proto/libhw_info_proto.a \
-L platform/device/driver/ethernet_manager/proto/mcu/libgeneral_cfg_proto.a \
-L platform/device/driver/ethernet_manager/proto/phy/libgeneral_cfg_proto.a \
-L platform/device/driver/ethernet_manager/proto/switch/libport_cfg_proto.a \
-L platform/device/driver/ethernet_manager/proto/switch/libport_vlan_cfg_proto.a \
-L platform/device/driver/infineon/libtlf35584.a \
-L platform/device/driver/libled.a \
-L platform/device/driver/libsimple_cli.a \
-L platform/device/driver/lwip/libarch.a \
-L platform/device/driver/lwip/liblwip_no_sys_port.a \
-L platform/device/driver/lwip/lwip_utils/libiperf.a \
-L platform/device/driver/lwip/lwip_utils/libping.a \
-L platform/device/driver/lwip/lwip_utils/libtcp_client.a \
-L platform/device/driver/lwip/lwip_utils/libtcp_server.a \
-L platform/device/driver/lwip/lwip_utils/libudp_server.a \
-L platform/device/driver/maxim/libmax20087.a \
-L platform/device/driver/micro_chip/libpac1954.a \
-L platform/device/driver/mps/libmpq8875.a \
-L platform/device/driver/nxp/tja1145/libtja1145.a \
-L platform/device/driver/phy/libnetwork_phy.a \
-L platform/device/driver/phy/marvell/libphy_88q2112.a \
-L platform/device/driver/rtc/libpca2131.a \
-L platform/device/driver/storage_flash/libstorage_flash.a \
-L platform/device/driver/switch/libswitch_common.a \
-L platform/device/driver/ti/libads101x_q1.a \
-L platform/device/driver/ti/libina226.a \
-L platform/device/driver/ti/libina3221_q1.a \
-L platform/device/driver/ti/libtca9539_q1.a \
-L platform/device/driver/ti/libtmp102.a \
-L platform/device/driver/ti/libtmp451.a \
-L platform/device/utils/libpin_channel.a \
-L platform/device/utils/libpower_channel.a \
-L platform/protocol/librouter.a \
-L platform/system/libsystemtime.a \
-L products/f0100_0001/aurix_a/app/libethernet.a \
-L products/f0100_0001/aurix_a/app/libethernet_manager.a \
-L products/f0100_0001/aurix_a/app/libi2c_test.a \
-L products/f0100_0001/aurix_a/app/libiperf.a \
-L products/f0100_0001/aurix_a/app/liborin_debug.a \
-L products/f0100_0001/aurix_a/app/libping.a \
-L products/f0100_0001/aurix_a/app/libswitch_flash.a \
-L products/f0100_0001/aurix_a/app/libtca9539.a \
-L products/f0100_0001/aurix_a/app/libtcp_cli_print.a \
-L products/f0100_0001/aurix_a/app/libtlf35584.a \
-L products/f0100_0001/nut_aurix/app/libadc_monitor.a \
-L products/f0100_0001/nut_aurix/app/libbootchain.a \
-L products/f0100_0001/nut_aurix/app/libcli.a \
-Wl--whole-archive=common/mcu/utils/libdebug.lo \
-Wl--whole-archive=platform/device/bsp/libbsp_adc.lo \
-Wl--whole-archive=platform/device/bsp/libbsp_can.lo \
-Wl--whole-archive=platform/device/bsp/libbsp_cpu.lo \
-Wl--whole-archive=platform/device/bsp/libbsp_delay.lo \
-Wl--whole-archive=platform/device/bsp/libbsp_flash.lo \
-Wl--whole-archive=platform/device/bsp/libbsp_gpio.lo \
-Wl--whole-archive=platform/device/bsp/libbsp_i2c.lo \
-Wl--whole-archive=platform/device/bsp/libbsp_irq.lo \
-Wl--whole-archive=platform/device/bsp/libbsp_loader.lo \
-Wl--whole-archive=platform/device/bsp/libbsp_mac.lo \
-Wl--whole-archive=platform/device/bsp/libbsp_spi.lo \
-Wl--whole-archive=platform/device/bsp/libbsp_timer.lo \
-Wl--whole-archive=platform/device/bsp/libbsp_uart.lo \
-Wl--whole-archive=platform/device/driver/bootchain/libbootchain_cmd.lo \
-Wl--whole-archive=platform/device/driver/bootloader/libloader_main.lo \
-Wl--whole-archive=platform/device/driver/ethernet_manager/libcommand.lo \
-Wl--whole-archive=platform/device/driver/ethernet_manager/libethernet_module.lo \
-Wl--whole-archive=platform/device/driver/ethernet_manager/libhw_info.lo \
-Wl--whole-archive=platform/device/service/libmd5.lo \
-Wl--whole-archive=platform/device/utils/libconfig_cmd.lo \
-Wl--whole-archive=products/f0100_0001/aurix_a/app/libaurix_spi.lo \
-Wl--whole-archive=products/f0100_0001/aurix_a/app/libcamera_trigger.lo \
-Wl--whole-archive=products/f0100_0001/aurix_a/app/libconfig.lo \
-Wl--whole-archive=products/f0100_0001/aurix_a/app/libeeprom.lo \
-Wl--whole-archive=products/f0100_0001/aurix_a/app/libgpio.lo \
-Wl--whole-archive=products/f0100_0001/aurix_a/app/libled.lo \
-Wl--whole-archive=products/f0100_0001/aurix_a/app/libloader_version.lo \
-Wl--whole-archive=products/f0100_0001/aurix_a/app/liborin_fsi.lo \
-Wl--whole-archive=products/f0100_0001/aurix_a/app/libpps.lo \
-Wl--whole-archive=products/f0100_0001/aurix_a/app/librtc.lo \
-Wl--whole-archive=products/f0100_0001/aurix_a/app/libtemperature.lo \
-Wl--whole-archive=products/f0100_0001/aurix_a/app/libversion.lo \
-Wl--whole-archive=products/f0100_0001/nut_aurix/app/libpower.lo \


C_FILES = \
external/aurix_tc39b_illd/Infra/Platform/Tricore/Compilers/CompilerDcc.c \
external/aurix_tc39b_illd/Infra/Platform/Tricore/Compilers/CompilerGhs.c \
external/aurix_tc39b_illd/Infra/Platform/Tricore/Compilers/CompilerGnuc.c \
external/aurix_tc39b_illd/Infra/Platform/Tricore/Compilers/CompilerTasking.c \
external/aurix_tc39b_illd/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Infra.c \
external/aurix_tc39b_illd/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc0.c \
external/aurix_tc39b_illd/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc1.c \
external/aurix_tc39b_illd/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc2.c \
external/aurix_tc39b_illd/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc3.c \
external/aurix_tc39b_illd/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc4.c \
external/aurix_tc39b_illd/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc5.c \
external/aurix_tc39b_illd/Service/CpuGeneric/If/SpiIf.c \
external/aurix_tc39b_illd/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.c \
external/aurix_tc39b_illd/Service/CpuGeneric/StdIf/IfxStdIf_Pos.c \
external/aurix_tc39b_illd/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.c \
external/aurix_tc39b_illd/Service/CpuGeneric/StdIf/IfxStdIf_Timer.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Bsp/Assert.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Bsp/Bsp.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Comm/Ifx_Console.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Comm/Ifx_Shell.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/General/Ifx_GlobalResources.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math/Ifx_AngleTrkF32.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math/Ifx_Cf32.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math/Ifx_Crc.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math/Ifx_FftF32.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_BitReverseTable.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_TwiddleTable.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math/Ifx_IntegralF32.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math/Ifx_LowPassPt1F32.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32_Table.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math/Ifx_LutLSincosF32.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math/Ifx_LutLinearF32.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32_Table.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math/Ifx_RampF32.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_BlackmanHarrisTable.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_HannTable.c \
external/aurix_tc39b_illd/Service/CpuGeneric/SysSe/Time/Ifx_DateTime.c \
external/aurix_tc39b_illd/config/Debug/sync_on_halt.c \
external/aurix_tc39b_illd/config/Ifx_Cfg_Ssw.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Asclin/Asc/IfxAsclin_Asc.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Asclin/Lin/IfxAsclin_Lin.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Asclin/Spi/IfxAsclin_Spi.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Asclin/Std/IfxAsclin.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Can/Can/IfxCan_Can.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Can/Std/IfxCan.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ccu6/Icu/IfxCcu6_Icu.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ccu6/PwmBc/IfxCcu6_PwmBc.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ccu6/PwmHl/IfxCcu6_PwmHl.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ccu6/Std/IfxCcu6.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ccu6/TPwm/IfxCcu6_TPwm.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ccu6/Timer/IfxCcu6_Timer.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ccu6/TimerWithTrigger/IfxCcu6_TimerWithTrigger.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Convctrl/Std/IfxConvctrl.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Cpu/Irq/IfxCpu_Irq.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Cpu/Std/IfxCpu.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Cpu/Trap/IfxCpu_Trap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Dma/Dma/IfxDma_Dma.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Dma/Std/IfxDma.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Dts/Dts/IfxDts_Dts.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Dts/Std/IfxDts.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ebu/BFlashSpansion/IfxEbu_BFlashSpansion.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ebu/BFlashSt/IfxEbu_BFlashSt.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ebu/Dram/IfxEbu_Dram.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ebu/Sram/IfxEbu_Sram.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Ebu/Std/IfxEbu.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Edsadc/Edsadc/IfxEdsadc_Edsadc.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Edsadc/Std/IfxEdsadc.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Emem/Std/IfxEmem.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Eray/Eray/IfxEray_Eray.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Eray/Std/IfxEray.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Evadc/Adc/IfxEvadc_Adc.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Evadc/Std/IfxEvadc.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Fce/Crc/IfxFce_Crc.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Fce/Std/IfxFce.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Flash/Std/IfxFlash.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Geth/Eth/IfxGeth_Eth.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Geth/Std/IfxGeth.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gpt12/IncrEnc/IfxGpt12_IncrEnc.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gpt12/Std/IfxGpt12.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Atom/Dtm_PwmHl/IfxGtm_Atom_Dtm_PwmHl.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Atom/Pwm/IfxGtm_Atom_Pwm.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Atom/PwmHl/IfxGtm_Atom_PwmHl.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Atom/Timer/IfxGtm_Atom_Timer.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Atom.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Cmu.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Dpll.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Dtm.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Psm.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Spe.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Tbu.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Tim.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Tom.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Tim/In/IfxGtm_Tim_In.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Tim/Timer/IfxGtm_Tim_Timer.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Tom/Dtm_PwmHl/IfxGtm_Tom_Dtm_PwmHl.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Tom/Pwm/IfxGtm_Tom_Pwm.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Tom/PwmHl/IfxGtm_Tom_PwmHl.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Gtm/Trig/IfxGtm_Trig.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Hspdm/Std/IfxHspdm.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Hssl/Hssl/IfxHssl_Hssl.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Hssl/Std/IfxHssl.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/I2c/I2c/IfxI2c_I2c.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/I2c/Std/IfxI2c.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Iom/Driver/IfxIom_Driver.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Iom/Iom/IfxIom_Iom.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Iom/Std/IfxIom.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Msc/Msc/IfxMsc_Msc.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Msc/Std/IfxMsc.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Mtu/Std/IfxMtu.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Pms/Std/IfxPmsEvr.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Pms/Std/IfxPmsPm.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Port/Io/IfxPort_Io.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Port/Std/IfxPort.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Psi5/Psi5/IfxPsi5_Psi5.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Psi5/Std/IfxPsi5.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Psi5s/Psi5s/IfxPsi5s_Psi5s.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Psi5s/Std/IfxPsi5s.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Qspi/SpiMaster/IfxQspi_SpiMaster.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Qspi/SpiSlave/IfxQspi_SpiSlave.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Qspi/Std/IfxQspi.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Rif/Rif/IfxRif_Rif.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Rif/Std/IfxRif.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Scu/Std/IfxScuCcu.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Scu/Std/IfxScuEru.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Scu/Std/IfxScuLbist.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Scu/Std/IfxScuRcu.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Sdmmc/Emmc/IfxSdmmc_Emmc.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Sdmmc/Sd/IfxSdmmc_Sd.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Sdmmc/Std/IfxSdmmc.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Sent/Sent/IfxSent_Sent.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Sent/Std/IfxSent.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Smu/Smu/IfxSmu_Smu.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Smu/Std/IfxSmu.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Smu/Std/IfxSmuStdby.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Spu/Std/IfxSpu.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Src/Std/IfxSrc.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Stm/Std/IfxStm.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/Stm/Timer/IfxStm_Timer.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxAsclin_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxCan_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxCcu6_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxCif_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxCpu_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxDma_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxEmem_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxEray_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxEvadc_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxFlash_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxGeth_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxGtm_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxHspdm_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxHssl_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxI2c_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxMsc_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxMtu_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxPort_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxPsi5_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxQspi_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxRif_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxScu_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxSent_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxSmu_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxSpu_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxSrc_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Impl/IfxStm_cfg.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Lib/DataHandling/Ifx_CircularBuffer.asm.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Lib/DataHandling/Ifx_CircularBuffer.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Lib/DataHandling/Ifx_Fifo.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_Lib/InternalMux/Ifx_InternalMux.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxAsclin_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxCan_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxCcu6_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxDmu_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxEdsadc_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxEray_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxEvadc_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxGeth_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxGpt12_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxGtm_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxHspdm_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxI2c_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxMsc_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxPms_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxPort_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxPsi5_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxPsi5s_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxQspi_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxRif_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxScu_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxSdmmc_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxSent_PinMap.c \
external/aurix_tc39b_illd/iLLD/TC39B/Tricore/_PinMap/IfxSmu_PinMap.c \
external/lwip/src/api/api_lib.c \
external/lwip/src/api/api_msg.c \
external/lwip/src/api/err.c \
external/lwip/src/api/if_api.c \
external/lwip/src/api/netbuf.c \
external/lwip/src/api/netdb.c \
external/lwip/src/api/netifapi.c \
external/lwip/src/api/sockets.c \
external/lwip/src/api/tcpip.c \
external/lwip/src/apps/lwiperf/lwiperf.c \
external/lwip/src/core/altcp.c \
external/lwip/src/core/altcp_alloc.c \
external/lwip/src/core/altcp_tcp.c \
external/lwip/src/core/def.c \
external/lwip/src/core/dns.c \
external/lwip/src/core/inet_chksum.c \
external/lwip/src/core/init.c \
external/lwip/src/core/ip.c \
external/lwip/src/core/ipv4/autoip.c \
external/lwip/src/core/ipv4/dhcp.c \
external/lwip/src/core/ipv4/etharp.c \
external/lwip/src/core/ipv4/icmp.c \
external/lwip/src/core/ipv4/igmp.c \
external/lwip/src/core/ipv4/ip4.c \
external/lwip/src/core/ipv4/ip4_addr.c \
external/lwip/src/core/ipv4/ip4_frag.c \
external/lwip/src/core/mem.c \
external/lwip/src/core/memp.c \
external/lwip/src/core/netif.c \
external/lwip/src/core/pbuf.c \
external/lwip/src/core/raw.c \
external/lwip/src/core/stats.c \
external/lwip/src/core/sys.c \
external/lwip/src/core/tcp.c \
external/lwip/src/core/tcp_in.c \
external/lwip/src/core/tcp_out.c \
external/lwip/src/core/timeouts.c \
external/lwip/src/core/udp.c \
external/lwip/src/netif/ethernet.c \
products/f0100_0001/aurix_a/sdk/can.c \
products/f0100_0001/aurix_a/sdk/can_bridge_demo.c \
products/f0100_0001/aurix_a/sdk/network.c \
products/f0100_0001/aurix_a/sdk/orin_spi.c \
products/f0100_0001/aurix_a/sdk/timer.c \
products/f0100_0001/nut_aurix/cpu0_main.c \
products/f0100_0001/nut_aurix/cpu1_main.c \
products/f0100_0001/nut_aurix/cpu2_main.c \
products/f0100_0001/nut_aurix/cpu3_main.c \
products/f0100_0001/nut_aurix/cpu4_main.c \
products/f0100_0001/nut_aurix/cpu5_main.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/CAN.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/CAN_CheckSums.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/CAN_NetworkManagement.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/CAN_Networks.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/CAN_Process.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Framemonitor.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/MCMCAN.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/VINCAN.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/CAN_Defaults.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/CAN_Diag.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/CAN_InitMessageObjects.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/CAN_OutputSignals.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/CAN_PostSettings.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/ADASCANFD/ADASCANFD_Handlers.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/ADASCANFD/ADASCANFD_MessageObjects.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/ADASCANFD/ADASCANFD_Vars.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/MRRX_DIAG/MRRX_DIAG_Handlers.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/MRRX_DIAG/MRRX_DIAG_MessageObjects.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/MRRX_DIAG/MRRX_DIAG_Vars.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/TEST_FD/FD_Handlers.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/TEST_FD/FD_MessageObjects.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/TEST_FD/FD_Vars.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/MRRX_DATA/MRRX_DATA_Handlers.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/MRRX_DATA/MRRX_DATA_MessageObjects.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/MRRX_DATA/MRRX_DATA_Vars.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/HAVAL/HAVAL_Handlers.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/HAVAL/HAVAL_MessageObjects.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/HAVAL/HAVAL_Vars.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/XCPCAN/XCPCAN_Handlers.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/XCPCAN/XCPCAN_MessageObjects.c \
products/f0100_0001/nut_aurix/DASCU/MCMCAN/Generated/XCPCAN/XCPCAN_Vars.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/ADAS.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/ADAS_data.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/I_DIAG_DAS.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/I_PERC_DAS.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/O_CAN_DAS.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/O_DIAG_DAS.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/O_PERC_DAS.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/O_VLC_DAS.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/ParametersAcc.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/ParametersAeb.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/ParametersLccAlccDow.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/ParametersLdwLdp.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/ParametersMain.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/ParametersMlia.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/ParametersRcw.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/ParametersRdaRctc.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/ParametersSens.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/ParametersRecNvTsrVis.c \
products/f0100_0001/nut_aurix/DASCU/simulink/ADAS/ParametersAfs.c \
products/f0100_0001/nut_aurix/DASCU/simulink/shared/rtGetInf.c \
products/f0100_0001/nut_aurix/DASCU/simulink/shared/rtGetNaN.c \
products/f0100_0001/nut_aurix/DASCU/simulink/vlc/Sedan.c \
products/f0100_0001/nut_aurix/DASCU/simulink/vlc/Sedan_armoured.c \
products/f0100_0001/nut_aurix/DASCU/simulink/vlc/Sedan_long.c \
products/f0100_0001/nut_aurix/DASCU/simulink/vlc/SUV.c \
products/f0100_0001/nut_aurix/DASCU/simulink/vlc/VINdependentVars.c \
products/f0100_0001/nut_aurix/DASCU/simulink/vlc/VLCforADAS_UMP.c \
products/f0100_0001/nut_aurix/DASCU/simulink/vlc/VLCforADAS_UMP_data.c \
products/f0100_0001/nut_aurix/DASCU/simulink/vlc/vlcout.c \
products/f0100_0001/nut_aurix/DASCU/simulink/vlc/vlcoutTX_CAN.c \
products/f0100_0001/nut_aurix/DASCU/UDP/UDP.c \
products/f0100_0001/nut_aurix/DASCU/UDP/udp_echoclient.c \
products/f0100_0001/nut_aurix/DASCU/UDP/UDP_Process.c \
products/f0100_0001/nut_aurix/DASCU/UDP/Generated/UDP_Defaults.c \
products/f0100_0001/nut_aurix/DASCU/UDP/Generated/UDP_Diag.c \
products/f0100_0001/nut_aurix/DASCU/UDP/Generated/UDP_InitMessageObjects.c \
products/f0100_0001/nut_aurix/DASCU/UDP/Generated/UDP_Prepare.c \
products/f0100_0001/nut_aurix/DASCU/UDP/Generated/UdpHandlers.c \
products/f0100_0001/nut_aurix/DASCU/UDP/Generated/UdpMessageObjects.c \
products/f0100_0001/nut_aurix/DASCU/UDP/Generated/UDP_PostSettings.c \
products/f0100_0001/nut_aurix/DASCU/UDP/IC/UDP_IC_Handlers.c \
products/f0100_0001/nut_aurix/DASCU/UDP/IC/UDP_IC_MessageObjects.c \
products/f0100_0001/nut_aurix/DASCU/DiagMrr/DiagMrr.c \
products/f0100_0001/nut_aurix/DASCU/DiagMrr/DiagMrr_DidHandlers.c \
products/f0100_0001/nut_aurix/DASCU/DiagMrr/DiagMrr_ManageRequest.c \
products/f0100_0001/nut_aurix/DASCU/Diagnostic/DiagVars.c \
products/f0100_0001/nut_aurix/DASCU/Diagnostic/uds.c \
products/f0100_0001/nut_aurix/DASCU/Diagnostic/sid_handles.c \
products/f0100_0001/nut_aurix/DASCU/Diagnostic/image.c \
products/f0100_0001/nut_aurix/DASCU/Diagnostic/dids.c \
products/f0100_0001/nut_aurix/DASCU/DiagErag/DiagErag.c \
products/f0100_0001/nut_aurix/DASCU/DiagErag/DiagErag_DidHandlers.c \
products/f0100_0001/nut_aurix/DASCU/DiagErag/DiagErag_ManageRequest.c \
products/f0100_0001/nut_aurix/DASCU/XCP/xcp_core.c \
products/f0100_0001/nut_aurix/DASCU/XCP/xcp_daq_list.c \
products/f0100_0001/nut_aurix/DASCU/XCP/xcp_fifo.c \
products/f0100_0001/nut_aurix/DASCU/XCP/xcp_node.c \
products/f0100_0001/nut_aurix/DASCU/events/ERAG/ERAG.c \
products/f0100_0001/nut_aurix/DASCU/events/TurnIndForming/TurnInd_event.c \
products/f0100_0001/nut_aurix/DASCU/events/MRRX_UDP/MRRX_UDP.c \
products/f0100_0001/nut_aurix/DASCU/events/MRRX_UDP/MRRX_DATA_Buff.c \
products/f0100_0001/nut_aurix/DASCU/events/AATest/AATest.c \
products/f0100_0001/nut_aurix/DASCU/events/PWR_MNGMNT/pwr_mngmnt.c \
products/f0100_0001/nut_aurix/DASCU/events/MEM/memfiu.c \
products/f0100_0001/nut_aurix/DASCU/events/MEM/mem.c \

EXTRA_CFLAGS = \
-DBOOTCHAIN_DEVICE_NUMBER=1 \
-DDEBUG_LEVEL=DEBUG_INFO \
-DDISABLE_REBOOT_AFTER_UPDATE \
-DDISABLE_SET_ACTIVE_SLOT_AFTER_FLASH \
-DELMOS_SDK_DISABLE \
-DHWPROTOOCL_CONFIG=products/f0100_0001/nut_aurix/hwprotocol_def.h \
-DHW_VERSION_B200 \
-DMAX_CONFIG_DATA_SIZE=256 \
-DMSD_DEBUG_QD=1 \
-DNO_COPY_FLASH_DRIVER_TO_LMURAM \
-DPONY_CONFIGS=products/f0100_0001/nut_aurix/f0100_03_0001_aurix_configs.h \
-DSIMPLE_CLI_MAX_CMD_NUMBER=64 \
-DSPRUCE_BUILD_IN \
-DSUPPORT_FOR_F0100_03_0000 \
-DSUPPORT_LWIP_TCP_SERVER \
-DSUPPORT_MCU_SDK \
-DSWITCH_88Q6113_MAX_NUM=1 \
-DUSE_COLOR_LOGGING \


### Template required end

# Please define your Tasking ctc path here!
#TASKING_PATH = C:/Users/igor.loginov/Desktop/TASKING/TriCorev6.3r1/ctc
#TASKING_PATH = C:/TASKING/TriCorev6.3r1/ctc
TASKING_PATH = C:/TASKING/ctc


ifeq ($(slot_type), SLOT_A)
OBJDIR = obj_slot_A
else
OBJDIR = obj_slot_B
endif

##OBJDIR = obj

TARGET_NAME = $(PROJECT)

CC = $(TASKING_PATH)/bin/cctc

all :

INCLUDE_PATH := $(addprefix -I ,$(INCLUDE_PATH))

CFLAGS = $(INCLUDE_PATH) -Ctc39xb -lsl-core=vtc --emit-locals=-equs,-symbols --iso=99 \
--language=+gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 \
--default-near-size=0 --default-a0-size=0 --default-a1-size=0 --tradeoff=4 --compact-max-size=200 \
--error-limit=1042 -Wa-gAHLs -Wa-Ogs -Wa--error-limit=1042  -Wa-H"sfr/regtc39xb.def" --source -c -t \
-g -O2 -D SUPPORT_MCU_SDK

CFLAGS += $(EXTRA_CFLAGS)

CFLAGS += $(SLOT_CFLAGS)

LDFLAGS = -Wl--output=$(OBJDIR)/$(TARGET_NAME).hex:IHEX:4 \
    --hex-format=s \
    --lsl-file=$(LINK_FILE) \
    --lsl-core=vtc \
    -Wl--error-limit=1042 \
    --fp-model=3 \
    --c++=14 \
    -Wl-S -Ctc39xb -Wa-Hsfr/regtc39xb.def

OBJ_FILES := $(addprefix $(OBJDIR)/,$(C_FILES:%.c=%.o))
C_DEPS := $(addprefix $(OBJDIR)/,$(SOURCE:%.c=%.d))

all : "$(OBJDIR)/$(TARGET_NAME).elf"

"$(OBJDIR)/$(TARGET_NAME).elf": $(OBJ_FILES)
	@echo + Linking to $(OBJDIR)/$(TARGET_NAME).elf
	@$(CC) $(LDFLAGS) $(OBJ_FILES) $(EXT_LIBRARIES) -o "$(OBJDIR)/$(TARGET_NAME).elf"

$(OBJ_FILES):$(OBJDIR)/%.o:%.c
	@echo + cc $<
	@mkdir -p $(dir $@)
	@$(CC) -o $@ $< $(CFLAGS) -Wc--make-target= $@

.PHONY : clean

clean :
	-rm $(OBJ_FILES)