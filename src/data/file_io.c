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

    // if file does not exist
    if (access(path, F_OK) != 0) {
        printf(NEW_FILE_WARNING_TEXT);
    }

    FILE* file = fopen(path, write_mode == APPEND ? "a" : "w");

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

// delete a line from the data file
void delete_line(uint16_t line)
{
    // get current file data
    char* data = read_file();

    // find the selected line
    uint16_t on_line = 0;
    uint16_t i = 0;
    uint16_t line_start, line_end;
    while (data[i] != '\0')
    {
        // check when the line starts
        if (on_line == line) {
            line_start = i; // DB 0
            
            // check when the line ends
            while (data[i] != '\n') {
                i++;
            }
            line_end = i; // DB 9

            break;
        }

        // count lines
        if (data[i] == '\n') {
            on_line++;
        }

        i++;
    }

    // remove the selected line :: copy what comes after the end of the line to the start of the line
    uint16_t str_len = strlen(data);
    uint16_t target_len = line_end - line_start + 1;
    
    strcpy(data+line_start, data+line_end+2);
    data[str_len-target_len] = '\0';
    

    // write changes to file
    write_file(data, OVERRIDE);

    // free resources
    free(data);
}