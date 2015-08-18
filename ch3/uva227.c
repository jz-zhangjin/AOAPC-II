/*************************************************************************
	> File Name: uav227.c
	> Author: Jin ZHANG
	> Mail: jz.zhangjin@gmail.com
	> Created Time: 四  8/13 19:42:47 2015
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define maxn 5
char cmd[1001];
char a[maxn+1][maxn+1];

void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int count = 0;

    //freopen("uva227.in", "r", stdin);

    while (gets(a[0]) && a[0][0] != 'Z') {

        // get input and find space
        int sx = 0, sy = 0;
        for (int i = 1; i < maxn; i++) {
            gets(a[i]);
            if (!a[i][maxn-1]) a[i][maxn-1] = ' ';
        }
        for (int i = 0; i < maxn; i++)
            for (int j = 0; j < maxn; j++ )
                if (a[i][j] == ' ') { sx = i; sy = j; break;}
        
        // go
        char *c; int fail = 0;
        //memset(cmd, 0, sizeof(cmd));
        //while (scanf("%s\n", cmd + strlen(cmd)) && cmd[strlen(cmd)-1] != '0');
        int len = 0;
        while (~scanf("%c", &cmd[len]))
            if (cmd[len] != '0') len++;
            else break;
        cmd[len] = 0; getchar(); 

 //       for (int i=0; cmd[i]; i++) {//} = cmd; *c != '0'; c++) {
        for(c = cmd; *c != 0; c++) {
            switch (*c) {
                case 'L':
                    if (sy == 0) fail = 1;
                    else { swap(&a[sx][sy], &a[sx][sy-1]); sy--; }
                    break;
                case 'R':
                    if (sy == maxn - 1) fail = 1;
                    else { swap(&a[sx][sy], &a[sx][sy+1]); sy++; }
                    break;
                case 'A':
                    if (sx == 0) fail = 1;
                    else { swap(&a[sx][sy], &a[sx-1][sy]); sx--; }
                    break;
                case 'B':
                    if (sx == maxn - 1) fail = 1;
                    else { swap(&a[sx][sy], &a[sx+1][sy]); sx++; }
                    break;
            }
            if (fail == 1) break;
        }

        // output
        if (count++) printf("\n");
        printf("Puzzle #%d:\n",count);
        if (!fail) {
            for (int i = 0; i < maxn; i++) {
                printf("%c", a[i][0]);    
                for (int j = 1; j < maxn; j++) {
                    printf (" %c", a[i][j]);
                }
                printf("\n");
            } 
        } else {
            printf("This puzzle has no final configuration.\n");
        }
    }
    return 0;
}
