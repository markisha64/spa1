
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

string a, b;
int DP[3001][3001];

int main() {
  cin >> a;
  cin >> b;

  for (int i = 1; i <= a.length(); i++) {
    for (int j = 1; j <= b.length(); j++) {
      if (a[i - 1] == b[j - 1]) {
        DP[i][j] = DP[i - 1][j - 1] + 1;
        continue;
      }

      DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
    }
  }

  int i = a.length();
  int j = b.length();
  int w = DP[i][j];
  string result;

  while (i > 0 and j > 0) {
    if (DP[i - 1][j] == DP[i][j]) {
      i--;
    } else if (DP[i][j - 1] == DP[i][j]) {
      j--;
    } else {
      result.push_back(a[i - 1]);
      i--;
      j--;
    }
  }

  reverse(result.begin(), result.end());

  cout << result;
}
