// File Input & Output Handling // ~ eylon

#include <data/file_io.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

// Local function :: return a string with the data file path
static char* get_data_path()
{
    // [TOFREE]
    char* data = (char*) malloc(1024 * sizeof(char)); // buffer to store the current working directory 
    getcwd(data, sizeof(data));

    return data;
}

// Read an entire file and return a character pointer to his contents :: return NULL if can't read file
char* read_file()
{
    // open the data file
    char* path = get_data_path();
    FILE* file = fopen(path, "r");

    // if no todo file found
    if (file == NULL) {
        return NULL;
    }

    // find file size
    fseek(file, 0L, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    // allocate memory
    char* data = (char*) malloc((file_size+1) * sizeof(char));

    // read from file
    fread(data, 1, file_size, file);
    data[file_size] = '\0';

    // free resources
    fclose(file);
    free(path);

    return data;
}

// Append/override a string to a file
int write_file(char* data, uint16_t length, WriteMode write_mode)
{
    char* path = get_data_path();
    FILE* file = fopen(path, write_mode == APPEND ? "a" : "w");

    // if no todo file found
    if (file == NULL) {
        return -1;
    }

    fprintf(file, data);

    // free resources
    fclose(file);
    free(path);

    return 0;
}