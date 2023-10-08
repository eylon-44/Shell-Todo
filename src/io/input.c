// Input Handler // ~ eylon

#include <io/input.h>

#include <utils/string_utils.h>
#include <utils/constants.h>
#include <core/commands.h>

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

// Ask for an inteager input indicating the task priority
static uint16_t priority_input()
{
    printf(PRIORITY_INPUT_TEXT);

    // get input
    char priority_string[1024];
    scanf("%s", priority_string); // reads the first input word

    // check validity
    uint16_t priority = atoi(priority_string);
    priority = (priority < PRIORITY_MIN || priority > PRIORITY_MAX) ? 0 : priority;

    return priority;
}

// Process command line arguments and call the corresponding function
void process_args(int argc, char* argv[])
{
    // A valid input should look like: [program name] [command] [arguments/input]
    // Note that the first item of argv (argv[0]) is the program name and can be ignored

    // no arguments/lst :: display the todo list
    if (argc <= 1 || !strcmp(argv[1], "list")) {
        cmd_list();
    }
    
    // add an item to the todo list :: arguments=[task string]
    else if (!strcmp(argv[1], "add") && argc > 2) {
        uint16_t priority = priority_input();
        if (priority == 0) {
            cmd_invalid();
            return;
        }
        cmd_add(word_list_to_string(argc-2, argv+2), priority);
    }
    // remove an item from the todo list :: arguments=[task index]
    else if (!strcmp(argv[1], "rem") && argc > 2) {
        uint8_t display_index = (uint8_t) atoi(argv[2]);
        if (display_index == 0) {
            cmd_invalid();
            return;
        }
        cmd_remove(display_index);
    }

    // list all the avialable commands
    else if (!strcmp(argv[1], "help") || !strcmp(argv[1], "cmd")) {
        cmd_help();        
    }

    // invalid command
    else {
        cmd_invalid();             
    }
}