// General Constants Header File // ~ eylon

#if !defined(CONSTANTS_H)
#define CONSTANTS_H

#define PRIORITY_MIN 1
#define PRIORITY_MAX 5

#define DATA_FILE_NAME "/.todo"

#define PRIORITY_INPUT_TEXT "> Enter a priority level:" \
                            "\n\t[1] very high\n\t[2] high\n\t[3] medium\n\t[4] low\n\t[5] very low\n$ "

#define HELP_CMD_TEXT "> Usage: todo [command] [arguments]\n" \
                      "Commands:" \
                      "\n\t-help              -> show this text" \
                      "\n\t-add [text]        -> add a task into the todo list" \
                      "\n\t-rem [index]       -> remove a task from the todo list" \
                      "\n\t-list/[no command] -> display the todo list" \
                      "\n"

#define ADD_CMD_TEXT "> Task added.\n"

#define REM_CMD_TEXT "> Task deleted.\n"

#define INVALID_CMD_TEXT "> Invalid use of command, use \"todo help\" to see how to use a command.\n"

#define TODO_OUTPUT_TEXT "> Todo:\n"

#define NEW_FILE_WARNING_TEXT "> Warning, created a new \".todo\" file in working directory.\n"

#endif