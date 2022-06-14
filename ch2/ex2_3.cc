#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        int j = 1;
        while (j < i)
        {
            printf(" ");
            j++;
        }
        for (j = 1; j <= (n - i + 1) * 2 - 1; ++j)
            printf("#");
        printf("\n");
    }

    return 0;
}
