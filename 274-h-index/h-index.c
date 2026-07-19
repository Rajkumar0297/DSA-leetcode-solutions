#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int hIndex(int* citations, int citationsSize) {

    qsort(citations, citationsSize, sizeof(int), compare);

    int h = 0;

    for (int i = 0; i < citationsSize; i++) {
        if (citations[i] >= i + 1)
            h = i + 1;
        else
            break;
    }

    return h;
}