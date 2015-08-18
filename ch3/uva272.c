/*************************************************************************
	> File Name: uva272.c
	> Author: Jin ZHANG
	> Mail: jz.zhangjin@gmail.com
	> Created Time: 二  8/11 11:19:45 2015
 ************************************************************************/

#include<stdio.h>
int main() {
    int c, q = 1;
    while ((c = getchar()) != EOF) {
        if (c == '\"') { printf("%s", q ? "``" : "''"); q = !q; }
        else printf("%c", c);
    }
    return 0;
}
