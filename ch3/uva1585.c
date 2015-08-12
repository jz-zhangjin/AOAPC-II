/*************************************************************************
	> File Name: uva1585.c
	> Author: Jin ZHANG
	> Mail: jz.zhangjin@gmail.com
	> Created Time: 三  8/12 18:05:46 2015
 ************************************************************************/

#include <stdio.h>
#include <memory.h>
#define maxn 85

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char s[maxn];
//        memset(s, 0, sizeof(s));;
        scanf("%s", s);
        int n = strlen(s);
        int p = 0, score = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'O') p++;
            else { score += p*(p+1)/2; p = 0;}
        }
        score += p*(p+1)/2;
        printf("%d\n", score);
    }
}
