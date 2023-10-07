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
int write_file(char* data, uint16_t length, WriteMode write_mode);

#endif