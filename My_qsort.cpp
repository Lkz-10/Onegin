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
                    left += size;
                } else {
                    if (right == mid) {
                        mid = left;
                    } else if (left == mid){
                        mid = right;
                    }
                    swap(left, right, size);
                }
            }
        }
        mid = left;

        if (mid == arr) mid += size;

        my_qsort(arr, ((size_t)(mid - (char*) arr)) / size, size, cmp);
        my_qsort(mid, num - ((size_t)(mid - (char*) arr)) / size, size, cmp);

    }
}
