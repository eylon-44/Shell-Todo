// data/data_handler.c Header File // ~ eylon

#if !defined(DATA_HANDLER_H)
#define DATA_HANDLER_H

#include <stdint.h>

// struct to hold data about each task in the todo list
typedef struct
{
    // Task string and priority number
    char* text;
    uint8_t priority;

    // The line number in the data file at which the task is ~ real address
    uint16_t real_index;
    // The index number in the sorted displayed list ~ virtual address
    uint16_t display_index;

} TodoEntry;

void add_todo(TodoEntry* todo);
void add_todo_list(TodoEntry* todo, uint16_t count);
void remove_todo(uint16_t display_index);
uint16_t get_todos(TodoEntry** todo_list);

#endif