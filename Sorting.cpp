#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "Sorting.h"
#include "OutputColours.h"

void sort_text_adds(TEXTDATA* text_data)
{
    assert(text_data->buffer);
    assert(text_data->adds);
    assert(text_data->line_lens);

    int bound = text_data->nlines - 1;

    while (bound > 0) {
        for (int j = 0; j < bound; j++) {
            if (my_strcmp((text_data->adds)[j], (text_data->adds)[j+1],
                          (text_data->line_lens)[j], (text_data->line_lens)[j+1]) > 0) {

                swap(&((text_data->adds)[j]), &((text_data->adds)[j+1]), sizeof(char**));
                swap(&((text_data->line_lens)[j]), &((text_data->line_lens)[j+1]), sizeof(int));
            }
        }
        --bound;
    }
}

/*void sort_text(const char text[][LINE_LEN], int* inds)
{
    int bound = NLINES - 1;

    while (bound > 0) {
        for (int j = 0; j < bound; j++) {
            if (my_strcmp(text[inds[j]], text[inds[j+1]]) > 0) {
                swap(&inds[j], &inds[j+1], sizeof(int));
            }
        }
        --bound;
    }
}*/

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

    if (curr_char1 < 0 || curr_char2 < 0) {
        fprintf(stderr, RED "Error: empty line!\n" COLOUR_RESET);
        exit(1);
    }

    while (curr_char1 >= 0 && curr_char2 >= 0) {
        if (s1[curr_char1] > s2[curr_char2]) return  1;
        if (s2[curr_char2] > s1[curr_char1]) return -1;

        --curr_char1;
        --curr_char2;

        while (curr_char1 >= 0 && !isalpha(s1[curr_char1])) curr_char1--;
        while (curr_char2 >= 0 && !isalpha(s2[curr_char2])) curr_char2--;
    }

    if (curr_char1 < 0 && curr_char2 < 0) return 0;
    if (curr_char2 < 0) return 1;

    return -1;
}

void swap(void* a, void* b, size_t sz)
{
    void* tmp = calloc(1, sz);

    memcpy(tmp, a, sz);
    memcpy(a, b, sz);
    memcpy(b, tmp, sz);

    free(tmp);
}
