#include <stdio.h>
#include <stdlib.h>

#include "OutputColours.h"

const int nlines = 14, line_len = 42;

void scan_text(char text[nlines][line_len]);

void lines_sort(char text[nlines][line_len], int* inds);

void fill(int* inds);

void print_text(char text[][line_len], int* inds);

int my_strcmp(const char* s1, const char* s2);

void swap(int* a, int* b);

int main()
{
    char text[nlines][line_len] = {};

    scan_text(text);

    int inds[nlines] = {};
    fill(inds);

    lines_sort(text, inds);

    print_text(text, inds);

    return 0;
}

void scan_text(char text[nlines][line_len])
{
    FILE* ptr_scan = fopen("Onegin_text.txt", "r");

    if (ptr_scan == NULL) {
        fprintf(stderr, RED "Error while opening file\n" COLOUR_RESET);
        exit(1);
    }

    for (int i = 0; i < nlines; ++i) {
        if (fgets(text[i], line_len, ptr_scan) == NULL) {
            fprintf(stderr, RED "Error while reading %d line\n" COLOUR_RESET, i+1);
            exit(1);
        }
    }

    fclose(ptr_scan);
}

void lines_sort(char text[nlines][line_len], int* inds)
{
    int bound = nlines - 1;

    while (bound > 0) {
        for (int j = 0; j < bound; j++) {
            if (my_strcmp(text[inds[j]], text[inds[j+1]]) > 0) {
                swap(&inds[j], &inds[j+1]);
            }
        }
        --bound;
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

void print_text(char text[][line_len], int* inds)
{
    for (int i = 0; i < nlines; i++) {
        printf("%s", text[inds[i]]);
    }
}

void fill(int* inds)
{
    for (int i = 0; i < nlines; ++i) {
        inds[i] = i;
    }
}

void swap(int* a, int* b)
{
    int t = *a;

    *a = *b;
    *b = t;
}
