#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Headers.h"

int main(int argc, const char* argv[])
{
    if (check_argc(argc) == -1) return -1;

    TEXTDATA text_data = {};

    if (read_data(&text_data, argv[1]) == -1) return -1;

    assert(text_data.buffer);
    assert(text_data.lines_data);

    printf("\nOriginal text:\n\n");
    print_text(&text_data);

    //sort_text(&text_data);
    my_qsort(text_data.lines_data, text_data.nlines, sizeof(LINESDATA), cmp);

    printf("Sorted text:\n\n");
    print_text(&text_data);
    //if (printf_text(&text_data, argv[2]) == -1) return -1;

    free(text_data.buffer);
    free(text_data.lines_data);

    return 0;
}
