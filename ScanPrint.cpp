#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ScanPrint.h"
#include "OutputColours.h"

void file_size(TEXTDATA* text_data, const char* file_name)
{
    text_data->ptr_scan = fopen(file_name, "rb");

    if (text_data->ptr_scan == NULL) {
        fprintf(stderr, RED "Error while opening file\n" COLOUR_RESET);
        fclose(text_data->ptr_scan);
        exit(1);
    }

    fseek(text_data->ptr_scan, 0, SEEK_END);
    text_data->file_sz = ftell(text_data->ptr_scan);

    rewind(text_data->ptr_scan);
}

void buf_scan(TEXTDATA* text_data)
{
    if (text_data->ptr_scan == NULL) {
        fprintf(stderr, RED "Error while opening file\n" COLOUR_RESET);
        fclose(text_data->ptr_scan);
        exit(1);
    }

    text_data->text_sz = fread(text_data->buffer, sizeof(char),
                               (text_data->file_sz) / sizeof(char), text_data->ptr_scan);

    text_data->nlines = 1;

    for (int i = 0; i < (int) text_data->text_sz - 1; ++i) {
        if ((text_data->buffer)[i] == '\n') (text_data->nlines)++;
    }

    fclose(text_data->ptr_scan);
}

void printf_text(TEXTDATA* text_data, const char* file_name)
{
    assert(text_data->lines_data);

    FILE* ptr_print = fopen(file_name, "wb");

   if (ptr_print == NULL) {
        fprintf(stderr, RED "Error while opening file for print\n" COLOUR_RESET);
        exit(1);
    }

    for (int i = 0; i < text_data->nlines; i++) {
        if (fputs(((text_data->lines_data)[i]).add, ptr_print) == EOF) {
            fprintf(stderr, RED "Error while writing into file\n" COLOUR_RESET);
            exit(1);
        }
    }

    fclose(ptr_print);
}

void print_text(TEXTDATA* text_data)
{
    assert(text_data->lines_data);

    for (int i = 0; i < text_data->nlines; ++i) {
        printf("%s", ((text_data->lines_data)[i]).add);
    }
    printf("\n");
}
