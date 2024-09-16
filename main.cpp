#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Globals.h"
#include "Sorting.h"
#include "ScanPrint.h"
#include "ArgcCheck.h"
#include "Make_adds.h"

int main(int argc, const char* argv[])
{
    check_argc(argc);

    TEXTDATA text_data = {};

    file_size(&text_data, argv[1]);

    text_data.buffer = (char*) calloc(1, text_data.file_sz);

    buf_scan(&text_data);
    assert(text_data.buffer);

    fill_adds(&text_data);
    assert(text_data.adds);
    assert(text_data.line_lens);

    print_text(&text_data);

    sort_text(&text_data);

    //print_text(&text_data);
    printf_text(&text_data, argv[2]);

    free(text_data.buffer);
    free(text_data.adds);
    free(text_data.line_lens);

    return 0;
}
