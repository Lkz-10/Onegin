#include <stdio.h>
#include <stdlib.h>

#include "ScanPrint.h"
#include "OutputColours.h"

void scan_text(char text[][line_len], const char* file_name)
{
    FILE* ptr_scan = fopen(file_name, "r");

    if (ptr_scan == NULL) {
        fprintf(stderr, RED "Error while opening file\n" COLOUR_RESET);
        exit(1);
    }

    for (int i = 0; i < nlines; ++i) {
        if (fgets(text[i], line_len, ptr_scan) == NULL) {
            fprintf(stderr, RED "Error while reading %d line\n" COLOUR_RESET, i+1);
            exit(1);
        }
    }

    fclose(ptr_scan);
}

void printf_text(const char text[][line_len], int* inds, const char* file_name)
{
    FILE* ptr_print = fopen(file_name, "w");

   if (ptr_print == NULL) {
        fprintf(stderr, RED "Error while opening file for print\n" COLOUR_RESET);
        exit(1);
    }

    for (int i = 0; i < nlines; i++) {
        if (fputs(text[inds[i]], ptr_print) == EOF) {
            fprintf(stderr, RED "Error while writing into file\n" COLOUR_RESET);
            exit(1);
        }
    }

    fclose(ptr_print);
}

void print_text(const char text[][line_len], int* inds)
{
    for (int i = 0; i < nlines; ++i) {
        printf("%s", text[inds[i]]);
    }
}

void fill(int* inds)
{
    for (int i = 0; i < nlines; ++i) {
        inds[i] = i;
    }
}
