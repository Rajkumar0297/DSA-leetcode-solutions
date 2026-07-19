#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void backtrack(char* s, int len, int index, int part,
               char* path, int pathLen,
               char** result, int* returnSize) {

    if (part == 4) {
        if (index == len) {
            path[pathLen - 1] = '\0';   // Remove last '.'
            result[*returnSize] = (char*)malloc(strlen(path) + 1);
            strcpy(result[*returnSize], path);
            (*returnSize)++;
        }
        return;
    }

    if (index >= len)
        return;

    int num = 0;
    for (int i = index; i < len && i < index + 3; i++) {
        num = num * 10 + (s[i] - '0');

        if (num > 255)
            break;

        int oldLen = pathLen;

        for (int j = index; j <= i; j++)
            path[pathLen++] = s[j];

        path[pathLen++] = '.';

        backtrack(s, len, i + 1, part + 1,
                  path, pathLen,
                  result, returnSize);

        pathLen = oldLen;

        if (s[index] == '0')
            break;
    }
}

char** restoreIpAddresses(char* s, int* returnSize) {
    *returnSize = 0;

    int len = strlen(s);

    char** result = (char**)malloc(100 * sizeof(char*));
    char path[20];

    backtrack(s, len, 0, 0, path, 0, result, returnSize);

    return result;
}