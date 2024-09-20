#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Headers.h"

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

    printf("\nOrigin text:\n\n");

    print_text(&text_data);

    //sort_text(&text_data);
    my_qsort(text_data.lines_data, text_data.nlines, sizeof(LINESDATA), cmp);

    printf("Sorted text:\n\n");
    print_text(&text_data);
    //printf_text(&text_data, argv[2]);

    free(text_data.buffer);
    free(text_data.lines_data);

    return 0;
}
