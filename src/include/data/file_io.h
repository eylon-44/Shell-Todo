// data/file_io.c Header File // ~ eylon

#if !defined(FILE_IO_H)
#define FILE_IO_H

#include <stdint.h>

typedef enum 
{
    APPEND,
    OVERRIDE
} WriteMode;

char* read_file();
int write_file(char* string, WriteMode write_mode);
void delete_line(uint16_t line);

#endif