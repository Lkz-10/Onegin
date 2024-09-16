#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Globals.h"
#include "Sorting.h"
#include "ScanPrint.h"
#include "ArgcCheck.h"

void fill_adds(TEXTDATA* text_data);

int main(int argc, const char* argv[])
{
    check_argc(argc);

    TEXTDATA text_data = {};

    file_size(&text_data, argv[1]);

    text_data.buffer = (char*) calloc(1, text_data.file_sz);

    buf_scan(&text_data, argv[1]);
    assert(text_data.buffer);

    fill_adds(&text_data);
    assert(text_data.adds);
    assert(text_data.line_lens);

    print_text_adds(&text_data);

    sort_text_adds(&text_data);

    print_text_adds(&text_data);

    free(text_data.buffer);
    free(text_data.adds);
    free(text_data.line_lens);

    return 0;
}

void fill_adds(TEXTDATA* text_data)
{
    assert(text_data->buffer);

    text_data->adds = (char**) calloc(text_data->nlines, sizeof(char*));

    (text_data->adds)[0] = text_data->buffer;

    int line_num = 1, curr_line_len = 0;

    text_data->line_lens = (int*) calloc(text_data->nlines, sizeof(int));

    for (int i = 0; i < (int) (text_data->text_sz); ++i) {
        curr_line_len++;

        if ((text_data->buffer)[i] == '\r') (text_data->buffer)[i] = '\n';

        else if ((text_data->buffer)[i] == '\n') {
            (text_data->buffer)[i] = '\0';

            (text_data->line_lens)[line_num-1] = curr_line_len;
            curr_line_len = 0;

            if (i != (int) text_data->text_sz - 1) {
                (text_data->adds)[line_num] = &(text_data->buffer)[i] + 1;
                line_num++;
            }
        }
    }
}

