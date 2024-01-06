
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s = "ACAATCC";
  string t = "AGCATGC";
  int DP[100][100];

  for (int i = 0; i <= s.length(); i++) {
    DP[i][0] = i;
  }

  for (int j = 0; j <= t.length(); j++) {
    DP[0][j] = j;
  }

  for (int i = 1; i <= s.length(); i++) {
    for (int j = 1; j <= t.length(); j++) {
      if (s[i - 1] == t[j - 1]) {
        DP[i][j] = DP[i - 1][j - 1];
        continue;
      }

      DP[i][j] = 1 + min({DP[i - 1][j], DP[i][j - 1], DP[i - 1][j - 1]});
    }
  }

  int i = s.length();
  int j = t.length();
  int optim = DP[i][j];
  vector<int> r, x, y;

  while (i > 0 and j > 0) {
    if (s[i - 1] == t[j - 1]) {
      i--;
      j--;
      continue;
    }

    int minSusjed = min({DP[i - 1][j], DP[i][j - 1], DP[i - 1][j - 1]});

    if (DP[i - 1][j] == minSusjed) {
      if (optim != minSusjed) {
        optim = minSusjed;
        r.push_back(0);
        x.push_back(i);
        y.push_back(j);
      }

      i--;
      continue;
    }

    if (DP[i][j - 1] == minSusjed) {
      if (optim != minSusjed) {
        optim = minSusjed;
        r.push_back(1);
        x.push_back(i);
        y.push_back(j);
      }

      j--;
      continue;
    }

    if (DP[i - 1][j - 1] == minSusjed) {
      if (optim != minSusjed) {
        optim = minSusjed;
        r.push_back(2);
        x.push_back(i);
        y.push_back(j);
      }

      i--;
      j--;
      continue;
    }
  }

  reverse(r.begin(), r.end());
  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());
  
  for (int i = 0; i < r.size(); i++) {
    switch (r[i]) {
    case 0: {
      cout << "Removed " << x[i] << ". character from s ('" << s[x[i] - 1]
           << "')";
    } break;

    case 1: {
      if (x[i]) {
        cout << "Inserted " << y[i] << ". character from t ('" << t[y[i] - 1]
             << "') to the " << x[i] << ". position (after '" << s[x[i] - 1]
             << "')";
      } else {
        cout << "Inserted " << y[i] << ". character from t ('" << t[y[i] - 1]
             << "') to the beginning of the string";
      }
    } break;

    case 2: {
      cout << "Replaced " << x[i] << ". character in s ('" << s[x[i] - 1]
           << "') with " << y[i] << ". character in t ('" << t[y[i] - 1]
           << "')";
    } break;
    }

    cout << endl;
  }
}
