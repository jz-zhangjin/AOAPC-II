#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int maxn = 10;
string puzzle[maxn];
int numbering[maxn][maxn];

int main() {
  int r, c;
  int cnt = 0;

  while (cin >> r >> c && r != 0) {
    for (int i = 0; i < r; ++i) {
      cin >> puzzle[i];
    }

    memset(numbering, 0, sizeof(numbering));
    int idx = 1;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (puzzle[i][j] != '*') {
          if (i == 0 || j == 0) {
            numbering[i][j] = idx++;
          } else {
            if (puzzle[i][j - 1] == '*' || puzzle[i - 1][j] == '*') {
              numbering[i][j] = idx++;
            }
          }
        }
      }
    }

    if (cnt++) cout << endl;
    cout << "puzzle #" << cnt << ":" << endl;
    cout << "Across" << endl;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        int k = numbering[i][j];
        if (k != 0) {
          if (j == 0 || puzzle[i][j - 1] == '*') {
            cout << setw(3) << k << ".";
            int l = j;
            while (l < c && puzzle[i][l] != '*') {
              cout << puzzle[i][l++];
            }
            cout << endl;
          }
        }
      }
    }
    cout << "Down" << endl;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        int k = numbering[i][j];
        if (k != 0) {
          if (i == 0 || puzzle[i - 1][j] == '*') {
            cout << setw(3) << k << ".";
            int l = i;
            while (l < r && puzzle[l][j] != '*') {
              cout << puzzle[l++][j];
            }
            cout << endl;
          }
        }
      }
    }
  }

  return 0;
}
