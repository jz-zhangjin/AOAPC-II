#include <iostream>
using namespace std;

const int maxn = 5;
char map[maxn][maxn + 1];

int main() {
  int cnt = 0;

  while (cin.getline(map[0], maxn + 1)) {
    if (map[0][0] == 'Z') break;

    for (int i = 1; i < maxn; ++i) {
      cin.getline(map[i], maxn + 1);
    }

    int bx = 0, by = 0;
    for (int i = 0; i < maxn; ++i) {
      for (int j = 0; j < maxn; ++j) {
        if (map[i][j] == ' ' || !map[i][j]) {
          bx = i;
          by = j;
          break;
        }
      }
    }

    string input, cmd = "";
    while (getline(cin, input)) {
      cmd += input;
      if (cmd.back() == '0') break;
    }

    bool move = true;
    int x, y;
    for (auto c : cmd) {
      switch (c) {
        case 'A':
          x = bx - 1;
          y = by;
          break;
        case 'B':
          x = bx + 1;
          y = by;
          break;
        case 'L':
          x = bx;
          y = by - 1;
          break;
        case 'R':
          x = bx;
          y = by + 1;
          break;
      }
      if (x < 0 || x >= maxn || y < 0 || y >= maxn) {
        move = false;
        break;
      }

      map[bx][by] = map[x][y];
      map[x][y] = ' ';
      bx = x;
      by = y;
    }

    if (cnt++) cout << endl;
    cout << "Puzzle #" << cnt << ":" << endl;
    if (!move) {
      cout << "This puzzle has no final configuration." << endl;
    } else {
      for (int i = 0; i < maxn; ++i) {
        cout << map[i][0];
        for (int j = 1; j < maxn; ++j) {
          cout << " " << map[i][j];
        }
        cout << endl;
      }
    }
  }

  return 0;
}
