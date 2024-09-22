#ifndef __COMPARATOR_BACKLINE_H__
#define __COMPARATOR_BACKLINE_H__

/**
    @brief     Comparator for sorting lines by their ends
    @param el1 first element
    @param el2 second element
    @return    positive if el1 > el2, 0 if equal, negative if el1 < el2
 */
int cmp(const void* el1, const void* el2);

#endif
