#include <memory.h>
#include <stdio.h>
#include <string.h>
#define maxn 85

const double weights[] = {12.01, 1.008, 16.00, 14.01};
const char* atomics = "CHON";

int getIndex(char c) {
  int n = strlen(atomics);
  for (int i = 0; i < n; i++) {
    if (c == atomics[i]) return i;
  }
  return -1;
}

int main() {
  int T;
  scanf("%d", &T);

  char s[maxn];
  while (T--) {
    memset(s, 0, sizeof(s));
    scanf("%s", s);
    int preIdx = 0, num = 0, n = strlen(s);
    double mol = 0;
    for (int i = 0; i < n; i++) {
      int idx = getIndex(s[i]);
      if (idx == -1) {
        num = num * 10 + s[i] - '0';
      } else {
        if (num == 0)
          mol += weights[idx];
        else
          mol += (num - 1) * weights[preIdx] + weights[idx];
        preIdx = idx;
        num = 0;
      }
    }
    if (num) mol += (num - 1) * weights[preIdx];
    printf("%.3f\n", mol);
  }
  return 0;
}
