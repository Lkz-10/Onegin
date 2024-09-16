#include "Make_adds.h"

#include <assert.h>
#include <stdlib.h>

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
