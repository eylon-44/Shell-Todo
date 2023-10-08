// Todo Data Handler // ~ eylon

#include <data/data_handler.h>
#include <data/file_io.h>

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

// Add a todo list to the data file
void add_todo_list(TodoEntry* todo, uint16_t count)
{

}

// Remove a todo by its display (virtual) index from the data file
void remove_todo(uint16_t display_index)
{
    
}

// Get the sorted todo list :: Return [uint16_t] list item count :: Take [TodoEntry**] a pointer to the todo list
uint16_t get_sorted_todos(TodoEntry** todo_list)
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
    
    free(data);
    return item_count;
}