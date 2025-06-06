// Copyright @2020 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_DEVICE_DRIVER_SIMPLE_CLI_
#define PLATFORM_DEVICE_DRIVER_SIMPLE_CLI_

#include <stdint.h>

#include "common/mcu/utils/status.h"

// Simple CLI (Command Line Interface) is a command line tool that you can easily
// integrate within your project if you need to control some simple behaviors via
// user input commands.
//
// To use Simple CLI, you need to provide the Read / Write function to your terminal,
// and specify an array of commands. You can set these by InitSimpleCli or statically
// define the SimpleCli instance.
// Also you need to run SimpleCliTask to handle the user input commands and invoke
// the corresponding handler. Usually you can put the SimpleCliTask in your main loop.
//
// NOTE: the Read function passed to simple cli should be unblocking,
// otherwise the SimpleCliTask would also be blocking.
//
// example of usage can be found in simple_cli_test.c

#ifndef SIMPLE_CLI_CMD_MAX_LEN
#define SIMPLE_CLI_CMD_MAX_LEN 128
#endif  // SIMPLE_CLI_CMD_MAX_LEN

#ifndef SIMPLE_CLI_MAX_CMD_NUMBER
#define SIMPLE_CLI_MAX_CMD_NUMBER 32
#endif  // SIMPLE_CLI_MAX_CMD_NUMBER

#ifndef SIMPLE_CLI_MAX_ARG_NUMBER
#define SIMPLE_CLI_MAX_ARG_NUMBER 8
#endif  // SIMPLE_CLI_MAX_ARG_NUMBER

// Function for unblocking read from terminal.
// This function type put the content in current terminal buffer into buffer,
// and returns the length of the read bytes.
typedef int32_t (*ReadFunc)(uint8_t* buffer, int32_t max_size);

// Function for write to terminal.
typedef int32_t (*WriteFunc)(const uint8_t* buffer, int32_t size);

typedef struct SimpleCliCommand {
  const char* cmd;
  int args_num;
  void (*handler)(void* arg);
  const char* help_msg;
} SimpleCliCommand;

typedef struct SimpleCli {
  // user provided read / write function
  ReadFunc read;
  WriteFunc write;
  // the cmd table
  uint32_t cmd_table_len;
  SimpleCliCommand cmd_table[SIMPLE_CLI_MAX_CMD_NUMBER];
  // the cmd buffer
  int32_t cmd_cur;
  char cmd[SIMPLE_CLI_CMD_MAX_LEN + 1];  // "+1" for '\0'
} SimpleCli;

ReturnCode InitSimpleCli(SimpleCli* simple_cli,
                         ReadFunc read,
                         WriteFunc write,
                         SimpleCliCommand* cmd_table,
                         uint32_t cmd_table_size);

ReturnCode SimpleCliAppendCmdTable(SimpleCli* simple_cli,
                                   SimpleCliCommand* cmd_table,
                                   uint32_t cmd_table_size);

ReturnCode SimpleCliTask(SimpleCli* simple_cli);

#endif  // PLATFORM_DEVICE_DRIVER_SIMPLE_CLI_
