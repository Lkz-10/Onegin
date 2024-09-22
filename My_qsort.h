#ifndef __MY_QSORT_H__
#define __MY_QSORT_H__

/**
 *   @brief      Quick sort function
 *   @param arr  massive to sort
 *   @param num  number of elements
 *   @param size size of each element
 *   @param cmp  comparator function
 */
void my_qsort (void* arr, size_t num, size_t size, int (*cmp) (const void*, const void*));

#endif
