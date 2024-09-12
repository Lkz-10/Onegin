#ifndef __SCANPRINT_H__
#define __SCANPRINT_H__

#include "Globals.h"

void scan_text(char text[][line_len], const char* file_name);

void printf_text(const char text[][line_len], int* inds, const char* file_name);

void print_text(const char text[][line_len], int* inds);

void fill(int* inds);

#endif
