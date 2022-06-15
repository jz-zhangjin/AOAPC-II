#include <stdio.h>
#include <string.h>

const int maxn = 100005;
int ans[maxn];

int main() {
  int T, n;
  memset(ans, 0, sizeof(ans));
  for (int m = 1; m < maxn; m++) {
    int x = m;
    int y = m;
    while (x > 0) {
      y += x % 10;
      x /= 10;
    }
    if (ans[y] == 0 || m < ans[y]) ans[y] = m;
  }

  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%d\n", ans[n]);
  }
  return 0;
}
