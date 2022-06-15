#include <iostream>
#include <string>
using namespace std;

const int maxn = 5;
string map[maxn];

int main() {
  int cnt = 0;

  while (getline(cin, map[0]) && map[0] != "Z") {
    for (int i = 1; i < maxn; ++i) {
      getline(cin, map[i]);
    }

    for (int i = 0; i < maxn; ++i) {
      if (map[i].size() == 4) {
        map[i] += ' ';
      }
    }

    int x = 0, y = 0;
    for (int i = 0; i < maxn; ++i) {
      for (int j = 0; j < maxn; ++j) {
        if (map[i][j] == ' ') {
          x = i;
          y = j;
          break;
        }
      }
    }

    string input, cmd = "";
    while (getline(cin, input)) {
      cmd += input;
      if (input.back() == '0') break;
    }

    bool valid = true;
    for (auto c : cmd) {
      switch (c) {
        case 'A':
          if (x == 0) {
            valid = false;
          } else {
            swap(map[x][y], map[x - 1][y]);
            --x;
          }
          break;
        case 'B':
          if (x == maxn - 1) {
            valid = false;
          } else {
            swap(map[x][y], map[x + 1][y]);
            ++x;
          }
          break;
        case 'L':
          if (y == 0) {
            valid = false;
          } else {
            swap(map[x][y], map[x][y - 1]);
            --y;
          }
          break;
        case 'R':
          if (y == maxn - 1) {
            valid = false;
          } else {
            swap(map[x][y], map[x][y + 1]);
            ++y;
          }
          break;
        case '0':
          break;
        default:
          valid = false;
          break;
      }

      if (!valid) {
        break;
      }
    }

    if (cnt++) cout << endl;
    cout << "Puzzle #" << cnt << ":" << endl;
    if (!valid) {
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
