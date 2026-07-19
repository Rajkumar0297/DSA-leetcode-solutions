#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void backtrack(int* nums, int numsSize, int start,
               int* subset, int subsetSize,
               int** result, int* returnSize,
               int** returnColumnSizes) {

    result[*returnSize] = (int*)malloc(subsetSize * sizeof(int));
    for (int i = 0; i < subsetSize; i++)
        result[*returnSize][i] = subset[i];

    (*returnColumnSizes)[*returnSize] = subsetSize;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        if (i > start && nums[i] == nums[i - 1])
            continue; // Skip duplicates

        subset[subsetSize] = nums[i];
        backtrack(nums, numsSize, i + 1,
                  subset, subsetSize + 1,
                  result, returnSize, returnColumnSizes);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int maxSubsets = 1 << numsSize;

    int** result = (int**)malloc(maxSubsets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxSubsets * sizeof(int));

    int* subset = (int*)malloc(numsSize * sizeof(int));

    *returnSize = 0;

    backtrack(nums, numsSize, 0,
              subset, 0,
              result, returnSize,
              returnColumnSizes);

    free(subset);
    return result;
}