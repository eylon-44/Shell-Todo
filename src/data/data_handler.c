// Todo Data Handler // ~ eylon

#include <data/data_handler.h>
#include <data/file_io.h>
#include <utils/constants.h>
#include <core/commands.h>

#include <stdint.h>
#include <stdlib.h>
#include <string.h>


// Add a todo to the data file
void add_todo(TodoEntry* todo)
{
    uint16_t str_len = (strlen(todo->text) + 2);
    // [TOFREE]
    char* str = (char*) malloc(str_len * sizeof(char));
    
    // set the priority
    str[0] = todo->priority + '0';
    // set the task
    strcpy(str+1, todo->text);
    str[str_len-1] = '\n';
    str[str_len] = '\0';

    write_file(str, APPEND);

    free(str);
}

// Remove a todo by its display (virtual) index from the data file
int remove_todo(uint16_t display_index)
{
    TodoEntry* todo_list;
    uint16_t count = get_todos(&todo_list);

    // if index is out of range
    if (display_index < 1 || display_index > count) {
        cmd_invalid();
        return -1;
    }

    // find the real index of the todo in the file
    uint16_t real_index;
    for (int i = 0; i < count; i++)
    {
        if (todo_list[i].display_index == display_index) {
            real_index = todo_list[i].real_index;
            break;
        }
    }

    // delete the line
    delete_line(real_index);

    // free resources
    free_todo(&todo_list, count);

    return 0;
}

// Get the todo list :: Return [uint16_t] list item count :: Take [TodoEntry**] a pointer to the todo list
uint16_t get_todos(TodoEntry** todo_list)
{
    // read file data
    char* data = read_file();
    if (data == NULL) {
        return 0;
    }

    // replace each \n in \0 and count how many items in the list
    uint16_t i = 0;
    uint16_t item_count = 0;

    while (data[i] != '\0')
    {
        if (data[i] == '\n') {
            data[i] = '\0';
            item_count++;
        }

        i++;
    }

    // [TOFREE] allocate memory to the list
    *todo_list = (TodoEntry*) malloc(item_count * sizeof(TodoEntry));

    // go over each TodoEntry, set the priority, copy the string starting from the data[offset]
    uint16_t offset = 0;
    for (i = 0; i < item_count; i++)
    {
        uint16_t str_len = strlen(data+offset);

        // set real index
        (*todo_list)[i].real_index = i;

        // set priority number :: convert char to int
        (*todo_list)[i].priority = data[offset] - '0';

        // [TOFREE] allocate memory for a string
        (*todo_list)[i].text = (char*) malloc((str_len -1) * sizeof(char));

        // copy string
        strcpy((*todo_list)[i].text, data+offset+1);

        // set an offset to the next string
        offset += str_len + 1;
    }

    // sort :: set the display index
    uint16_t display_index = 1;
    for (uint8_t p = PRIORITY_MIN; p <= PRIORITY_MAX; p++)
    {
        for (i = 0; i < item_count; i++)
        {
            if ((*todo_list)[i].priority == p)
            {
                (*todo_list)[i].display_index = display_index;
                display_index++;
            }
        }
    }
    
    free(data);
    return item_count;
}

// Free a todo list :: free each todo struct and its contents
void free_todo(TodoEntry** todo, uint16_t count)
{

}