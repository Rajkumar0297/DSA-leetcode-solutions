#include <stdlib.h>

int largestRectangle(int* heights, int size) {
    int stack[size + 1];
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= size; i++) {
        int currHeight = (i == size) ? 0 : heights[i];

        while (top != -1 && currHeight < heights[stack[top]]) {
            int height = heights[stack[top--]];
            int width;

            if (top == -1)
                width = i;
            else
                width = i - stack[top] - 1;

            int area = height * width;
            if (area > maxArea)
                maxArea = area;
        }

        stack[++top] = i;
    }

    return maxArea;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0)
        return 0;

    int cols = matrixColSize[0];
    int* heights = (int*)calloc(cols, sizeof(int));
    int maxArea = 0;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1')
                heights[j]++;
            else
                heights[j] = 0;
        }

        int area = largestRectangle(heights, cols);
        if (area > maxArea)
            maxArea = area;
    }

    free(heights);
    return maxArea;
}