#include <stdlib.h>
#include <limits.h>

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2)
        return 0;

    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < minVal)
            minVal = nums[i];
        if (nums[i] > maxVal)
            maxVal = nums[i];
    }

    if (minVal == maxVal)
        return 0;

    int bucketSize = (maxVal - minVal) / (numsSize - 1);
    if (bucketSize == 0)
        bucketSize = 1;

    int bucketCount = (maxVal - minVal) / bucketSize + 1;

    int *bucketMin = (int *)malloc(bucketCount * sizeof(int));
    int *bucketMax = (int *)malloc(bucketCount * sizeof(int));
    int *used = (int *)calloc(bucketCount, sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    for (int i = 0; i < numsSize; i++) {
        int idx = (nums[i] - minVal) / bucketSize;

        if (nums[i] < bucketMin[idx])
            bucketMin[idx] = nums[i];

        if (nums[i] > bucketMax[idx])
            bucketMax[idx] = nums[i];

        used[idx] = 1;
    }

    int ans = 0;
    int prev = minVal;

    for (int i = 0; i < bucketCount; i++) {
        if (!used[i])
            continue;

        ans = ans > bucketMin[i] - prev ? ans : bucketMin[i] - prev;
        prev = bucketMax[i];
    }

    free(bucketMin);
    free(bucketMax);
    free(used);

    return ans;
}