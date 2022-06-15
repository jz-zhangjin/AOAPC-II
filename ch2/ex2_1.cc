#include <math.h>
#include <stdio.h>

int main() {
  int i, a, b, c;

  FILE *fout;
  fout = stdout;
  for (i = 100; i <= 999; i++) {
    a = i / 100;
    c = i % 10;
    b = i / 10 % 10;
    if (pow(a, 3) + pow(b, 3) + pow(c, 3) == i) fprintf(fout, "%d\n", i);
  }
  fclose(fout);
  return 0;
}
