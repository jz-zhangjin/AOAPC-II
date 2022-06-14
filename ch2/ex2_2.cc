#include <stdio.h>

int main()
{
    int a, b, c;
    int num = 0, count = -1;

    FILE *fin, *fout;
    fin = stdin;   // fopen("ex2_2.in", "rb");
    fout = stdout; // fopen("ex2_2.out", "wb");

    while (fscanf(fin, "%d%d%d", &a, &b, &c) == 3)
    {
        num = c;
        count++;
        while (num < 10)
            num += 7;
        while (num <= 100)
        {
            if ((num % 3 == a) && (num % 5 == b))
            {
                fprintf(fout, "Case %d: %d\n", count, num);
                break;
            }
            num += 7;
        }
        if (num > 100)
            fprintf(fout, "Case %d: No answer\n", count);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
