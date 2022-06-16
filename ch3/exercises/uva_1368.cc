#include <iostream>
#include <map>
using namespace std;

const int maxm = 50;
string sequences[maxm];

int main() {
  int T;
  cin >> T;

  while (T--) {
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; ++i) {
      cin >> sequences[i];
    }

    string consensus_string = "";
    int consensus_errors = 0;
    for (int i = 0; i < n; i++) {
      map<char, int> counts;
      int max_count = 0;
      char consensus_char;
      for (int j = 0; j < m; j++) {
        char c = sequences[j][i];
        ++counts[c];
        if (counts[c] > max_count || (counts[c] == max_count && c < consensus_char)) {
          max_count = counts[c];
          consensus_char = c;
        }
      }
      consensus_string += consensus_char;
      consensus_errors += m - max_count;
    }
    cout << consensus_string << endl << consensus_errors << endl;
  }
  return 0;
}
