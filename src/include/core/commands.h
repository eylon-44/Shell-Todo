// core/commands.c Header File // ~ eylon

#if !defined(COMMANDS_H)
#define COMMANDS_H

#include <stdint.h>

void cmd_list();
void cmd_add(char* text, uint8_t priority);
void cmd_remove(uint16_t display_index);
void cmd_help();
void cmd_invalid();

#endif