#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "OutputColours.h"

const int nlines = 14, line_len = 42;

void sort_text(char text[nlines][line_len], int* inds);
int my_strcmp(const char* s1, const char* s2);

void scan_text(char text[nlines][line_len]);
void print_text(char text[][line_len], int* inds);

void fill(int* inds);

void swap(int* a, int* b);

int main()
{
    char text[nlines][line_len] = {};
    scan_text(text);

    int inds[nlines] = {};
    fill(inds);

    sort_text(text, inds);

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

void sort_text(char text[nlines][line_len], int* inds)
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
    int curr_char1 = line_len - 1, curr_char2 = line_len - 1;

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
