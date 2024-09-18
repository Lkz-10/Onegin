#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include <string.h>
#include <stdio.h>

struct LINESDATA {
    char* add;
    int   line_len;
};

struct TEXTDATA {
    long   file_sz;
    size_t text_sz;
    int    nlines;

    char*  buffer;

    LINESDATA* lines_data;

    FILE* ptr_scan;
};

#endif
