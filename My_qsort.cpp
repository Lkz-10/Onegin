#include <stdlib.h>
#include <assert.h>

#include "My_qsort.h"
#include "Sorting.h"

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
