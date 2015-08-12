/*************************************************************************
	> File Name: Uva1583.c
	> Author: Jin ZHANG
	> Mail: jz.zhangjin@gmail.com
	> Created Time: 三  8/12 11:20:16 2015
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define maxn 100005
int ans[maxn];

int main() {
    int T, n;
    memset(ans, 0, sizeof(ans));
    for (int m = 1; m < maxn; m++) {
        int x = m; int y = m;
        while (x > 0) { y += x % 10; x /= 10; }
        if (ans[y] == 0 || m < ans[y]) ans[y] = m;
    }

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}
