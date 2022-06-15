#include <math.h>
#include <stdio.h>

int main() {
  int a, b, c, count = 0;
  double deci;

  while (scanf("%d%d%d", &a, &b, &c) == 3 && (a != 0 || b != 0 || c != 0)) {
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
