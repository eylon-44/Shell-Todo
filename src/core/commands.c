// Main Command Handler // ~ eylon

#include <core/commands.h>
#include <io/output.h>
#include <utils/constants.h>
#include <data/data_handler.h>

#include <stdint.h>
#include <string.h>
#include <stdio.h>

// Invoked when the 'list' command or no command is being used :: show the sorted data list
void cmd_list()
{
    TodoEntry* todo_list;
    uint16_t count = get_todos(&todo_list);
    print_todo_list(todo_list, count);
}

// Invoked when the 'add' command is being used with valid parameters :: add a todo to the list
void cmd_add(char* text, uint8_t priority)
{
    TodoEntry todo = {.text=text, .priority=priority};
    add_todo(&todo);
}

// Invoked when the 'rem' command is being used with valid parameters :: remove a todo from the list
void cmd_remove(uint16_t display_index)
{

}

// Invoked when the 'help' command is beign used :: print some usefull information about this program
void cmd_help()
{
    printf(HELP_CMD_TEXT);
}

// Invoked when the command is invalid :: print an error message
void cmd_invalid()
{
    printf(INVALID_CMD_TEXT);
}