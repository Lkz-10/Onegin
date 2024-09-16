#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ScanPrint.h"
#include "OutputColours.h"

void file_size(TEXTDATA* text_data, const char* file_name)
{
    FILE* ptr_sz = fopen(file_name, "rb");

    if (ptr_sz == NULL) {
        fprintf(stderr, RED "Error while opening file\n" COLOUR_RESET);
        fclose(ptr_sz);
        exit(1);
    }

    fseek(ptr_sz, 0, SEEK_END);
    text_data->file_sz = ftell(ptr_sz) + 1;

    fclose(ptr_sz);
}

void buf_scan(TEXTDATA* text_data, const char* file_name)
{
    FILE* ptr_scan = fopen(file_name, "rb");

    if (ptr_scan == NULL) {
        fprintf(stderr, RED "Error while opening file\n" COLOUR_RESET);
        fclose(ptr_scan);
        exit(1);
    }

    text_data->text_sz = fread(text_data->buffer, sizeof(char), (text_data->file_sz) / sizeof(char), ptr_scan);

    text_data->nlines = 1;

    for (int i = 0; i < (int) text_data->text_sz - 1; ++i) {
        if ((text_data->buffer)[i] == '\n') (text_data->nlines)++;
    }

    fclose(ptr_scan);
}

void scan_text(char text[][LINE_LEN], const char* file_name)
{
    FILE* ptr_scan = fopen(file_name, "r");

    if (ptr_scan == NULL) {
        fprintf(stderr, RED "Error while opening file\n" COLOUR_RESET);
        exit(1);
    }

    for (int i = 0; i < NLINES; ++i) {
        if (fgets(text[i], LINE_LEN, ptr_scan) == NULL) {
            fprintf(stderr, RED "Error while reading %d line\n" COLOUR_RESET, i+1);
            exit(1);
        }
    }

    fclose(ptr_scan);
}

void printf_text(const char text[][LINE_LEN], int* inds, const char* file_name)
{
    FILE* ptr_print = fopen(file_name, "w");

   if (ptr_print == NULL) {
        fprintf(stderr, RED "Error while opening file for print\n" COLOUR_RESET);
        exit(1);
    }

    for (int i = 0; i < NLINES; i++) {
        if (fputs(text[inds[i]], ptr_print) == EOF) {
            fprintf(stderr, RED "Error while writing into file\n" COLOUR_RESET);
            exit(1);
        }
    }

    fclose(ptr_print);
}

void print_text_adds(TEXTDATA* text_data)
{
    assert(text_data->adds);

    for (int i = 0; i < text_data->nlines; ++i) {
        printf("%s", (text_data->adds)[i]);
    }
    printf("\n");
}

void print_text(const char text[][LINE_LEN], int* inds)
{
    for (int i = 0; i < NLINES; ++i) {
        printf("%s", text[inds[i]]);
    }
}

void fill(int* inds)
{
    for (int i = 0; i < NLINES; ++i) {
        inds[i] = i;
    }
}
