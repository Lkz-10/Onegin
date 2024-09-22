#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include <string.h>
#include <stdio.h>

/**
 *   @brief Structure with information about the line
 *   @param addr      line ->address
 *   @param line_len line length
 */
struct LINESDATA {
    char* addr;
    int   line_len;
};

/**
 *   @brief Structure with text data
 *   @param file_sz    size of the file
 *   @param text_sz    number of read symbols
 *   @param nlines     number of lines
 *   @param buffer     buffer to read the text into
 *   @param lines_data Structure with information about the line
 *   @param ptr_scan   pointer to the file
 */
struct TEXTDATA {
    long   file_sz;
    size_t text_sz;
    int    nlines;

    char*  buffer;

    LINESDATA* lines_data;

    FILE* ptr_scan;
};

#endif
