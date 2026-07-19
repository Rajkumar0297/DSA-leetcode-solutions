#include <stdlib.h>

int* majorityElement(int* nums, int numsSize, int* returnSize) {

    int candidate1 = 0, candidate2 = 1;
    int count1 = 0, count2 = 0;

    // Find possible candidates
    for (int i = 0; i < numsSize; i++) {

        if (nums[i] == candidate1) {
            count1++;
        }
        else if (nums[i] == candidate2) {
            count2++;
        }
        else if (count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        }
        else {
            count1--;
            count2--;
        }
    }

    // Verify candidates
    count1 = 0;
    count2 = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1)
            count1++;
        else if (nums[i] == candidate2)
            count2++;
    }

    int *ans = (int *)malloc(2 * sizeof(int));
    *returnSize = 0;

    if (count1 > numsSize / 3) {
        ans[(*returnSize)++] = candidate1;
    }

    if (count2 > numsSize / 3) {
        ans[(*returnSize)++] = candidate2;
    }

    return ans;
}