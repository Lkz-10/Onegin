#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ScanPrint.h"
#include "OutputColours.h"
#include "Make_adds.h"

int file_size(TEXTDATA* text_data, const char* file_name)
{
    assert(text_data);

    text_data->ptr_scan = fopen(file_name, "rb");

    if (text_data->ptr_scan == NULL) {
        fprintf(stderr, RED "Error while opening file\n" COLOUR_RESET);
        fclose(text_data->ptr_scan);
        return -1;
    }

    fseek(text_data->ptr_scan, 0, SEEK_END);
    text_data->file_sz = ftell(text_data->ptr_scan);

    rewind(text_data->ptr_scan);

    return 0;
}

int buf_scan(TEXTDATA* text_data)
{
    assert(text_data);

    if (text_data->ptr_scan == NULL) {
        fprintf(stderr, RED "Error while opening file in \"buf_scan\"\n" COLOUR_RESET);
        fclose(text_data->ptr_scan);
        return -1;
    }

    text_data->text_sz = fread(text_data->buffer, sizeof(char),
                               (text_data->file_sz) / sizeof(char), text_data->ptr_scan);

    return 0;
}

int count_lines(TEXTDATA* text_data)
{
    assert(text_data);

    if (text_data->ptr_scan == NULL) {
        fprintf(stderr, RED "Error while opening file in \"count_lines\"\n" COLOUR_RESET);
        fclose(text_data->ptr_scan);
        return -1;
    }

    text_data->nlines = 0;

    for (int i = 0; i < (int) text_data->text_sz; ++i) {
        if ((text_data->buffer)[i] == '\n') (text_data->nlines)++;
    }

    fclose(text_data->ptr_scan);

    return 0;
}

int read_data (TEXTDATA* text_data, const char* file_name)
{
    assert(text_data);

    if (file_size(text_data, file_name) == -1) return -1;

    text_data->buffer = (char*) calloc(1, text_data->file_sz + 1);
    assert(text_data->buffer);

    if (buf_scan(text_data) == -1) return -1;
    assert(text_data->buffer);

    if (count_lines(text_data) == -1) return -1;

    fill_adds(text_data);
    assert(text_data->lines_data);

    return 0;
}

int printf_text(TEXTDATA* text_data, const char* file_name)
{
    assert(text_data);

    FILE* ptr_print = fopen(file_name, "wb");

   if (ptr_print == NULL) {
        fprintf(stderr, RED "Error while opening file for print\n" COLOUR_RESET);
        return -1;
    }

    for (int i = 0; i < text_data->nlines; i++) {
        if (fputs(((text_data->lines_data)[i]).addr, ptr_print) == EOF) {
            fprintf(stderr, RED "Error while writing into file\n" COLOUR_RESET);
            return -1;
        }
    }

    fclose(ptr_print);

    return 0;
}

void print_text(TEXTDATA* text_data)
{
    assert(text_data->lines_data);

    for (int i = 0; i < text_data->nlines; ++i) {
        printf("%s", ((text_data->lines_data)[i]).addr);
    }
    printf("\n");
}
