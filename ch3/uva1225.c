/*************************************************************************
	> File Name: uva1225.c
	> Author: Jin ZHANG
	> Mail: jz.zhangjin@gmail.com
	> Created Time: 三  8/12 19:57:51 2015
 ************************************************************************/

#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, a[10] = {0};
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int k = i;
            while (k > 0) {
                a[k % 10]++;
                k /= 10;
            }   
        }

        for (int i = 0; i < 9; i++)
            printf("%d ", a[i]);
        printf("%d\n", a[9]);
    }
    return 0;
}
