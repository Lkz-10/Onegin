#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include <string.h>

struct TEXTDATA {
    long   file_sz;
    size_t text_sz;
    int    nlines;

    char*  buffer;
    char** adds;
    int*   line_lens;

    FILE* ptr_scan;
};

#endif
