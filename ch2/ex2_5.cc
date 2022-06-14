#include <stdio.h>
#include <math.h>

int main() {
    FILE *fin;
    int a, b, c, count = 0;
    double deci;

    fin = fopen("ex2_5.in", "rb");
    while (fscanf(fin, "%d%d%d", &a, &b, &c) == 3
        && (a != 0 || b != 0 || c != 0)) {

        deci = (double)a / b;
        printf("Case %d: %d.", ++count, (int)floor(deci));
        deci -= floor(deci);

        for (int i = 1; i < c; i++) {
            double tensDeci = deci * 10;
            printf("%d", (int)floor(tensDeci));
            deci = tensDeci - floor(tensDeci);
        }
        printf("%d\n", (int)floor(deci * 10 + 0.5));
    }

    return 0;
}
