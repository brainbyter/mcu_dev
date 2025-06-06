// Copyright @2019 Pony AI Inc. All rights reserved.

/// @defgroup bsp_interface bsp interface

/// @defgroup bsp_gpio bsp gpio
/// @ingroup bsp_interface
/// This is the implementation of the GPIO interface. By calling 
/// relevant API functions, developers can perform operations on GPIO, 
/// such as setting pin status, setting output status, reading input status, 
/// interrupt registration, etc.

/// @file
/// @ingroup bsp_gpio
/// @brief the header file for bsp gpio driver

#ifndef PLATFORM_DEVICE_BSP_BSP_GPIO_H_
#define PLATFORM_DEVICE_BSP_BSP_GPIO_H_

#include <stdio.h>

#include "common/mcu/utils/status.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PIN_LOW 0x00
#define PIN_HIGH 0x01

#define PIN_MODE_OUTPUT 0x00
#define PIN_MODE_INPUT 0x01
#define PIN_MODE_INPUT_PULLUP 0x02
#define PIN_MODE_INPUT_PULLDOWN 0x03
#define PIN_MODE_OUTPUT_OD 0x04
#define PIN_MODE_AF_PP 0x05

#define PIN_IRQ_MODE_RISING 0x00
#define PIN_IRQ_MODE_FALLING 0x01
#define PIN_IRQ_MODE_RISING_FALLING 0x02
#define PIN_IRQ_MODE_HIGH_LEVEL 0x03
#define PIN_IRQ_MODE_LOW_LEVEL 0x04

#define PIN_IRQ_DISABLE 0x00
#define PIN_IRQ_ENABLE 0x01

#define PIN_IRQ_PIN_NONE -1

/// @ingroup bsp_gpio
/// @brief A structure that describes the interrupt function of the pin.
struct pony_pin_irq_hdr {
  /// Pin number.
  int16_t pin;
  /// Trigger mode of the pin, supporting rising edge trigger, falling edge 
  /// trigger, double edge trigger (both rising and falling edge trigger).
  uint16_t mode;
  /// The interrupt handling function bound to the pin.
  void (*hdr)(void* args);
  /// The parameters for the interrupt handling function.
  void* args;
};

/// @ingroup bsp_gpio
/// @brief Used to describe the structure of a pin, its properties include the working mode of the pin, 
/// input/output, and interrupt control. This structure is used in the MCU layer to implement the real 
/// functions for Pins, the application layer user should not touch this structure. 
typedef struct PonyPinOps {
  /// A function pointer pointing to a function used to initialize the working mode of the pin.
  ReturnCode (*pin_mode)(int16_t pin, uint16_t mode);
  /// A function pointer pointing to a function used to set the pin output state.
  ReturnCode (*pin_write)(int16_t pin, uint16_t value);
  /// A function pointer pointing to a function used to obtain the input state of a pin.
  int (*pin_read)(int16_t pin);
  /// A function pointer pointing to a function that sets an interrupt handling function for a pin.
  ReturnCode (*pin_attach_irq)(int16_t pin, uint16_t mode, void (*hdr)(void* args), void* args);
  /// A function pointer pointing to a function that cancels the pin interrupt handling function.
  ReturnCode (*pin_detach_irq)(int16_t pin);
  /// A function pointer pointing to a function that enables the interrupt function of a pin.
  ReturnCode (*pin_irq_enable)(int16_t pin, uint32_t enabled);
} pony_pin_ops_t;

/// @ingroup bsp_gpio
/// @brief Used to register pins. The working mode configuration, input/output control, interrupt control, and other 
/// functions of GPIO are implemented through the function pointer members of pony_pin_ops_t, the underlying adaptation 
/// interface is disabled by SDK users.
/// @param ops [pony_pin_ops_t] Used to implement the real functions for Pins.
/// @return return void.
extern void RegisterGpio(pony_pin_ops_t* ops);
/// @ingroup bsp_gpio
/// @brief Set the interrupt handler for the interrupt function of this pin.
/// @param pin [int16_t] The number of the pin to set.
/// @param mode [uint16_t] The working mode of the pin, including Rising edge trigger\Falling edge 
/// trigger\Double edge trigger (both rising and falling edge trigger).
/// @param hdr [void (*hdr)(void* args)] The interrupt the callback function. 
/// @param args [void*] Interrupt callback function parameters. 
/// @return return ERROR_OK if the setting is successful, return ERROR_INVALID_PARAM if the pin number is illegal, 
/// return ERROR_OUT_OF_RANGE if the trigger mode is not supported, and return ERROR_BUSY if the 
/// interrupt line is occupied by another I/O port.
extern ReturnCode AttachGpioIrq(int16_t pin, uint16_t mode, void (*hdr)(void* args), void* args);
/// @ingroup bsp_gpio
/// @brief Cancels the interrupt function for a GPIO pin.
/// @param pin [int16_t] The number of the pin to cancel.
/// @return return ERROR_OK if the cancellation succeeded, return ERROR_INVALID_PARAM if the pin does not exist.
extern ReturnCode DetachGpioIrq(int16_t pin);
/// @ingroup bsp_gpio
/// @brief Enable the interrupt function of a certain GPIO pin.
/// @param pin [int16_t] The number of the pin to enable.
/// @param enabled [uint32_t] 0 represents disable, 1 represents enable. 
/// @return return ERROR_OK if successful execution.
extern ReturnCode EnableGpioIrq(int16_t pin, uint32_t enabled);
/// @ingroup bsp_gpio
/// @brief Set the mode of each pin of GPIO to input or output mode.
/// @param pin [int16_t] The number of the pin to set.
/// @param mode [uint16_t] The working mode of the pin.
/// @return return ERROR_OK if the working mode is successfully set, 
/// return ERROR_INVALID_PARAM if the pin number is incorrect, 
/// return ERROR_OUT_OF_RANGE if the working mode is incorrect.
extern ReturnCode SetGpioMode(int16_t pin, uint16_t mode);
/// @ingroup bsp_gpio
/// @brief Set the output state of a GPIO pin (high or low).
/// @param pin [int16_t] The number of the pin to set.
/// @param value [uint16_t] Level logic value, 0 represents low level, 1 represents high level.
/// @return return ERROR_OK_ OK if the setting is successful,
/// return ERROR_OUT_OF_RANGE if the pin does not exist.
extern ReturnCode WriteGpio(int16_t pin, uint16_t value);
/// @ingroup bsp_gpio
/// @brief Gets the input status (high or low) of a GPIO pin.
/// @param pin [int16_t] The number of the pin to set.
/// @return return 1 indicates high level, return 0 indicates low level.
extern int ReadGpio(int16_t pin);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // PLATFORM_DEVICE_BSP_BSP_GPIO_H_
