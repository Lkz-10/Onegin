#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Headers.h"

void my_qsort (void* arr, size_t num, size_t size, int (*cmp) (const void*, const void*));

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

void my_qsort (void* arr, size_t num, size_t size, int (*cmp) (const void*, const void*))
{
    assert(arr);
    assert(cmp);

    if (num > 1) {
        char* mid = (char*) arr + (num/2) * size;

        size_t swap_eq = 0, swap_all = 0;

        char* left = (char*) arr;
        char* right = (char*) arr + (num - 1) * size;

        while (left < right) {
            while (cmp(left, mid) < 0) {
                left += size;
            }

            while (right > left && cmp(right, mid) > 0) {
                right -= size;
            }

            if (left < right) {
                if (cmp(left, right) == 0) {
                    swap_eq++;
                    swap_all++;

                    swap(left, right - size, size);

                    right -= size;
                    mid = right;
                } else {
                    if (right == mid) {
                        mid = left;
                    } else if (left == mid){
                        mid = right;
                    }
                    swap(left, right, size);
                    swap_all++;
                }
            }
        }
        if (swap_eq != swap_all) {

            my_qsort(arr, ((size_t)(mid - (char*) arr)) / size, size, cmp);
            my_qsort(mid, num - ((size_t)(mid - (char*) arr)) / size, size, cmp);
        }
    }
}
