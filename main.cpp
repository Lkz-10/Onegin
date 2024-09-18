#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Globals.h"
#include "Sorting.h"
#include "ScanPrint.h"
#include "ArgcCheck.h"
#include "Make_adds.h"

//typedef int (*cmp_type)(void* el1, void* el2);

int cmp(const void* el1, const void* el2);

int main(int argc, const char* argv[])
{
    check_argc(argc);

    TEXTDATA text_data = {};

    file_size(&text_data, argv[1]);

    text_data.buffer = (char*) calloc(1, text_data.file_sz);

    buf_scan(&text_data);
    assert(text_data.buffer);

    fill_adds(&text_data);
    assert(text_data.lines_data);

    print_text(&text_data);

    //sort_text(&text_data);
    qsort(text_data.lines_data, text_data.nlines, sizeof(LINESDATA), cmp);

    print_text(&text_data);
    //printf_text(&text_data, argv[2]);

    free(text_data.buffer);
    free(text_data.lines_data);

    return 0;
}

int cmp(const void* el1, const void* el2)
{
    return my_strcmp(((const LINESDATA*) el1)->add,      ((const LINESDATA*) el2)->add,
                     ((const LINESDATA*) el1)->line_len, ((const LINESDATA*) el2)->line_len);
}
