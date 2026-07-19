#include <stdlib.h>
#include <string.h>

char* longestPrefix(char* s) {
    int n = strlen(s);

    int *lps = (int *)calloc(n, sizeof(int));

    int len = 0;
    int i = 1;

    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    int ansLen = lps[n - 1];

    char *ans = (char *)malloc(ansLen + 1);

    for (int i = 0; i < ansLen; i++)
        ans[i] = s[i];

    ans[ansLen] = '\0';

    free(lps);

    return ans;
}