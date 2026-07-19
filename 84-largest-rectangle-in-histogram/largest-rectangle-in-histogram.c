int largestRectangleArea(int* heights, int heightsSize) {
    int stack[heightsSize + 1];
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= heightsSize; i++) {
        int currHeight = (i == heightsSize) ? 0 : heights[i];

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