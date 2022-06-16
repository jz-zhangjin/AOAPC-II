#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
  int numerator, denominator;
  int cnt = 0;

  while (cin >> numerator >> denominator) {
    int i = (numerator % denominator) * 10;
    string result = "";

    int l = 0, r = 0;
    map<int, int> factors;
    while (i > 0) {
      auto iter = factors.find(i);
      if (iter != factors.end()) {
        l = iter->second;
        break;
      }

      factors.insert(make_pair(i, r));
      if (i < denominator) {
        result += "0";
      } else {
        result += to_string(i / denominator);
        i %= denominator;
      }
      i *= 10;
      r++;
    }

    if (i == 0) {
      result += "(0)";
    } else {
      result =
          result.substr(0, l) + "(" +
          (r  > 50 ? result.substr(l, 50 - l) + "..." : result.substr(l, r)) +
          ")";
    }
    cout << numerator << '/' << denominator << " = ";
    cout << numerator / denominator << "." << result << endl;
    cout << "   " << (i == 0 ? 1 : r - l);
    cout << " = number of digits in repeating cycle" << endl << endl;
  }
  return 0;
}
