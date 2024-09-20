#include <stdio.h>

#include "Comparator_backline.h"
#include "Sorting.h"

int cmp(const void* el1, const void* el2)
{
    return my_strcmp(((const LINESDATA*) el1)->add,      ((const LINESDATA*) el2)->add,
                     ((const LINESDATA*) el1)->line_len, ((const LINESDATA*) el2)->line_len);
}
