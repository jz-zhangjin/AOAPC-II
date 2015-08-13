/*************************************************************************
	> File Name: uva455.c
	> Author: Jin ZHANG
	> Mail: jz.zhangjin@gmail.com
	> Created Time: 四  8/13 09:58:07 2015
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define maxn 85

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char s[maxn] = {0};
        scanf("%s", s);
        int n = strlen(s);

        for (int i = 1, j; i <= n; i++) {
            if (n % i) continue;
            for (j = i; j < n; j++ ) {
                if (s[j] != s[j % i]) break;
            }
            if (j == n) { printf("%d\n", i); break; }
        }
        if (T) printf("\n");
    }
    return 0;
}
