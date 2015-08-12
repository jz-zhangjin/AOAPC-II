/*************************************************************************
	> File Name: uva1584.c
	> Author: Jin ZHANG
	> Mail: jz.zhangjin@gmail.com
	> Created Time: 三  8/12 12:00:56 2015
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define maxn 105

int less(const char* s, int p, int q) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[(p+i) % n] != s[(q+i) % n])
            return s[(p+i) % n] < s[(q+i) % n];
    }
    return 0;
}

int main() {
    int T;
    char s[maxn];
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int ans = 0;
        int n = strlen(s);
        for (int i = 1; i < n; i++)
            if (less(s, i, ans)) ans = i;
        
        for (int i = 0; i < n; i++)
            putchar(s[(i+ans)%n]);    
        putchar('\n');
    }
    return 0;
}
