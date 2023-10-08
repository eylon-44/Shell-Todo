// Output Handler // ~ eylon

#include <io/output.h>
#include <utils/constants.h>
#include <stdio.h>

// Print the full sorted todo list 
void print_todo_list(TodoEntry* todo_list, uint16_t count)
{
    printf(TODO_OUTPUT_TEXT);
    for (uint16_t dis_ind = 1; dis_ind <= count; dis_ind++)
    {
        for (uint16_t t = 0; t < count; t++)
        {
            if (todo_list[t].display_index == dis_ind)
            {
                printf("\t%d. [%d] %s\n", dis_ind, todo_list[t].priority, todo_list[t].text);
                break;
            }
        }
    }
}