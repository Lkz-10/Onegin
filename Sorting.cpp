#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "Sorting.h"
#include "OutputColours.h"

void sort_text(TEXTDATA* text_data)
{
    assert(text_data->buffer);
    assert(text_data->lines_data);

    int bound = text_data->nlines - 1;

    while (bound > 0) {
        for (int j = 0; j < bound; j++) {
            if (my_strcmp((text_data->lines_data)[j].add, (text_data->lines_data)[j+1].add,
                          ((text_data->lines_data)[j]).line_len, ((text_data->lines_data)[j+1]).line_len) > 0) {

                swap(&(((text_data->lines_data)[j]).add), &(((text_data->lines_data)[j+1]).add), sizeof(char*));
                swap(&((text_data->lines_data)[j].line_len), &((text_data->lines_data)[j+1].line_len), sizeof(int));
            }
        }
        --bound;
    }
}

int my_strcmp(const char* s1, const char* s2, int len1, int len2)
{
    assert(s1);
    assert(s2);

    int curr_char1 = len1 - 1, curr_char2 = len2 - 1;

    while (curr_char1 >= 0 && !isalpha(s1[curr_char1])) {
        curr_char1--;
    }

    while (curr_char2 >= 0 && !isalpha(s2[curr_char2])) {
        curr_char2--;
    }

    while (curr_char1 >= 0 && curr_char2 >= 0) {
        if (toupper(s1[curr_char1]) != toupper(s2[curr_char2])) {
            return  toupper(s1[curr_char1]) - toupper(s2[curr_char2]);
        }

        --curr_char1;
        --curr_char2;

        while (curr_char1 >= 0 && !isalpha(s1[curr_char1])) curr_char1--;
        while (curr_char2 >= 0 && !isalpha(s2[curr_char2])) curr_char2--;
    }

    return curr_char1 - curr_char2;
}

void swap(void* a, void* b, size_t sz)
{
    void* tmp = calloc(1, sz);

    memcpy(tmp, a, sz);
    memcpy(a, b, sz);
    memcpy(b, tmp, sz);

    free(tmp);

    /*char* tmp = 0;

    for (size_t i = 0; i < sz; ++i) {
        tmp = (char*) a + i;
        *((char*) a + i) = *((char*) b + i);
        *((char*) b + i) = *tmp;

    }*/
}
