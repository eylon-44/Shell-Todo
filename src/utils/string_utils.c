// String Utils // ~ eylon

#include <utils/string_utils.h>

#include <stdlib.h>
#include <string.h>
#include <stdint.h>


// Convert a char pointer array to a single string | return value must be freed later
char* word_list_to_string(int argc, char* argv[])
{
    // [TOFREE] assuming string length won't be over 1024 bytes
    char* str = (char*) malloc(sizeof(char) * 1024);

    // go over each word in argv and add it to the string
    uint16_t size = 0; // size_t
    for (uint16_t i = 0; i < argc; i++)
    {
        strcpy(str+size, argv[i]);
        size += strlen(argv[i]);
        str[size] = ' ';
        size++;
    }
    str[size] = '\0';

    return (char*) realloc(str, size);
}
