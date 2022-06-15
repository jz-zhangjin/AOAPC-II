#include <stdio.h>

int main() {
  int n, m, count = 0;

  while (scanf("%d%d", &n, &m) == 2 && (m != 0 || n != 0)) {
    double sum = 0.0;
    for (long long i = n; i <= m; i++) {
      sum += 1.0 / (long long)(i * i);
    }
    printf("Case %d: %.5lf\n", ++count, sum);
  }

  return 0;
}
