#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char *s1 = *(char **)a;
    char *s2 = *(char **)b;

    char ab[25], ba[25];

    strcpy(ab, s1);
    strcat(ab, s2);

    strcpy(ba, s2);
    strcat(ba, s1);

    return strcmp(ba, ab);
}

char* largestNumber(int* nums, int numsSize) {
    char **arr = (char **)malloc(numsSize * sizeof(char *));

    for (int i = 0; i < numsSize; i++) {
        arr[i] = (char *)malloc(12);
        sprintf(arr[i], "%d", nums[i]);
    }

    qsort(arr, numsSize, sizeof(char *), compare);

    // If the largest number is 0
    if (strcmp(arr[0], "0") == 0) {
        char *res = (char *)malloc(2);
        strcpy(res, "0");

        for (int i = 0; i < numsSize; i++)
            free(arr[i]);
        free(arr);

        return res;
    }

    char *ans = (char *)malloc(numsSize * 12 + 1);
    ans[0] = '\0';

    for (int i = 0; i < numsSize; i++) {
        strcat(ans, arr[i]);
        free(arr[i]);
    }

    free(arr);

    return ans;
}