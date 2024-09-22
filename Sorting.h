#ifndef __SORTING_H__
#define __SORTING_H__

#include <stdlib.h>

#include "Globals.h"

/**
    @brief           Function to bubble sort the text
    @param text_data structure with text data
 */
void sort_text(TEXTDATA* text_data);

/**
    @brief      Function to compare lines
    @param s1   first line
    @param s2   second line
    @param len1 length of first line
    @param len2 length of second line
    @return     positive if s1 > s2, 0 if equal, negative if s1 < s2
 */
int my_strcmp(const char* s1, const char* s2, int len1, int len2);


/**
    @brief    Function to swap 2 elements
    @param a  first element
    @param b  second element
    @param sz size of each element
 */
void swap(void* a, void* b, size_t sz);

#endif
