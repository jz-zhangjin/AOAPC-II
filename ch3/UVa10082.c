/*************************************************************************
	> File Name: UVa10082.c
	> Author: Jin ZHANG
	> Mail: jz.zhangjin@gmail.com
	> Created Time: 二  8/11 14:10:11 2015
 ************************************************************************/

#include<stdio.h>
char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main() {
    int i, c;
    while ((c = getchar()) != EOF) {
        for (i = 1; s[i] && s[i] != c; i++);
        if (s[i]) putchar(s[i-1]);
        else putchar(c);
    }
    return 0;
}

