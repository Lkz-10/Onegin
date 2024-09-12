#ifndef __SORTING_H__
#define __SORTING_H__

#include <stdlib.h>

#include "Globals.h"

void sort_text(const char text[][line_len], int* inds);

int my_strcmp(const char* s1, const char* s2);

void swap(void* a, void* b, size_t sz);

#endif
