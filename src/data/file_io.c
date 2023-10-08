// File Input & Output Handling // ~ eylon

#include <data/file_io.h>
#include <utils/constants.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

// Local function :: return a string with the data file path
static char* get_data_path()
{
    // [TOFREE]
    char* path = (char*) malloc(1024 * sizeof(char)); // buffer to store the current working directory 
    getcwd(path, 1024);

    strcat(path, DATA_FILE_NAME);

    return path;
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

// Append/override a null terminated string to a file
int write_file(char* data, WriteMode write_mode)
{
    char* path = get_data_path();
    printf(path);
    FILE* file = fopen(path, write_mode == APPEND ? "a" : "w");

    // [TODO] make a new file if not found
    // if no todo file found
    if (file == NULL) {
        return -1;
    }

    fprintf(file, "%s", data);

    // free resources
    fclose(file);
    free(path);

    return 0;
}