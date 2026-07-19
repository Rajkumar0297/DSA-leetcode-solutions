#include <stdlib.h>

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int* dp = (int*)malloc(triangleSize * sizeof(int));

    // Initialize with the last row
    for (int i = 0; i < triangleColSize[triangleSize - 1]; i++) {
        dp[i] = triangle[triangleSize - 1][i];
    }

    // Bottom-up DP
    for (int i = triangleSize - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (dp[j] < dp[j + 1])
                dp[j] = triangle[i][j] + dp[j];
            else
                dp[j] = triangle[i][j] + dp[j + 1];
        }
    }

    int result = dp[0];
    free(dp);

    return result;
}