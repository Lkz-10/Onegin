#include <stdio.h>
#include <stdlib.h>

#include "OutputColours.h"

const int lines = 14, line_len = 42;

void sort_text();
void lines_sort(char text[lines][line_len]);

int my_strcmp(const char* s1, const char* s2);

void swap(int* a, int* b);

int main()
{
    sort_text();
}

void sort_text()
{
    FILE* ptr_scan = fopen("Onegin_text.txt", "r");

    if (ptr_scan == NULL) {
        fprintf(stderr, RED "Error while opening file\n" COLOUR_RESET);
        exit(1);
    }

    char text[lines][line_len] = {};

    for (int i = 0; i < lines; ++i) {
        if (fgets(text[i], line_len, ptr_scan) == NULL) {
            fprintf(stderr, RED "Error while reading %d line\n" COLOUR_RESET, i+1);
            exit(1);
        }
    }

    fclose(ptr_scan);

    lines_sort(text);
}

void lines_sort(char text[lines][line_len])
{
    int inds[lines] = {};
    for (int i = 0; i < lines; ++i) {
        inds[i] = i;
    }

    int bound = lines - 1;

    while (bound > 0) {
        for (int j = 0; j < bound; j++) {
            if (my_strcmp(text[inds[j]], text[inds[j+1]]) > 0) {
                swap(&inds[j], &inds[j+1]);
            }
        }
        --bound;
    }

    for (int i = 0; i < lines; i++) {
        printf("%s", text[inds[i]]);
    }
}

int my_strcmp(const char* s1, const char* s2)
{
    int i = 0;

    while (i < line_len && ((int) s1[i]) == ((int) s2[i])) {
        i++;
    }

    if (i == line_len) return 0;
    return ((int) s1[i]) - ((int) s2[i]);
}

void swap(int* a, int* b)
{
    int t = *a;

    *a = *b;
    *b = t;
}
