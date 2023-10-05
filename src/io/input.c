// Input Utils // ~ eylon

#include <string.h>
#include <io/input.h>

// Process command line arguments and call the corresponding function
void process_args(int argc, char* argv[])
{
    // A valid input should look like: [program name] [command] [arguments/input]
    // Note that the first item of argv (argv[0]) is the program name

    // no arguments/lst :: display the todo list
    if (argc <= 1 || strcmp(argv[1], "lst")) {
        
    }
    
    // add an item to the todo list :: arguments=[task string]
    else if (strcmp(argv[1], "add")) {
            
    }
    // remove an item from the todo list :: arguments=[task index]
    else if (strcmp(argv[1], "rem")) {
            
    }

    // list all the avialable commands
    else if (strcmp(argv[1], "help") || strcmp(argv[1], "cmd")) {

    }

    // invalid command
    else {

    }
}

