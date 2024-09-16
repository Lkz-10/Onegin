#ifndef __SCANPRINT_H__
#define __SCANPRINT_H__

#include "Globals.h"

void file_size(TEXTDATA* text_data, const char* file_name);

void buf_scan(TEXTDATA* text_data, const char* file_name);

void scan_text(char text[][LINE_LEN], const char* file_name);

void printf_text(const char text[][LINE_LEN], int* inds, const char* file_name);

void print_text_adds(TEXTDATA* text_data);

void print_text(const char text[][LINE_LEN], int* inds);

void fill(int* inds);

#endif
