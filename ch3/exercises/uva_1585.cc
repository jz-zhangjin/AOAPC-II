#include <stdio.h>
#include <cstring>
#define maxn 85

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    char s[maxn];
    scanf("%s", s);
    int n = strlen(s);
    int p = 0, score = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'O')
        p++;
      else {
        score += p * (p + 1) / 2;
        p = 0;
      }
    }
    score += p * (p + 1) / 2;
    printf("%d\n", score);
  }
}
