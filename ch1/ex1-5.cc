#include <stdio.h>

int main()
{
    const double price = 95.0;
    double total = 0.0;

    int n;
    scanf("%d", &n);
    total = price * n;
    if (total >= 300)
        total *= 0.85;

    printf("%.2f\n", total);
}
