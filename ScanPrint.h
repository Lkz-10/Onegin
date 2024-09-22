#ifndef __SCANPRINT_H__
#define __SCANPRINT_H__

#include "Globals.h"

/**
 *   @brief           Function to learn size of file
 *   @param text_data structure with text data
 *   @param file_name name of file to read
 *   @return          -1 if error, 0 otherwise
 */
int file_size(TEXTDATA* text_data, const char* file_name);

/**
 *   @brief           Function to scan text to buffer
 *   @param text_data structure with text data
 *   @return          -1 if error, 0 otherwise
 */
int buf_scan(TEXTDATA* text_data);

/**
 *   @brief           Function to count number of lines
 *   @param text_data structure with text data
 *   @return          -1 if error, 0 otherwise
 */
int count_lines(TEXTDATA* text_data);

/**
 *   @brief           Function to read all text data
 *   @param text_data structure with text data
 *   @param file_name name of file to read
 *   @return          -1 if error, 0 otherwise
 */
int read_data (TEXTDATA* text_data, const char* file_name);

/**
 *   @brief           Function to print text into file
 *   @param text_data structure with text data
 *   @param file_name name of file to print
 *   @return          -1 if error, 0 otherwise
 */
int printf_text(TEXTDATA* text_data, const char* file_name);

/**
 *   @brief           Function to print text
 *   @param text_data structure with text data
 */
void print_text(TEXTDATA* text_data);

#endif
