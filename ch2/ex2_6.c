#include <stdio.h>

int main() {
    int a, b, c;

    for (int i = 100; i <= 333; i++) {
        a = i;
        b = 2 * i;
        c = 3 * i;

        int digits[9] = {0};
        for (int j = 1; j <= 9; j++) {
            if (a/100 == j || a%10 == j || a/10%10 == j)
                digits[j-1] = 1;
            if (b/100 == j || b%10 == j || b/10%10 == j)
                digits[j-1] = 1;
            if (c/100 == j || c%10 == j || c/10%10 == j) 
                digits[j-1] = 1;
        }

        int k = 1;
        for (int j = 0; j < 9; j++)
            k *= digits[j];

        if (k == 1)
            printf("%d %d %d\n", a, b, c);
    }
    return 0;
}
