
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll DP[1001][1001];
ll grid[1001][1001];

ll mod = 1e9 + 7;

ll f(int i, int j) {
  if (DP[i][j] != -1)
    return DP[i][j];
  
  if (i + 1 == n and j + 1 == n)
    return 1;

  if (i >= n or j >= n)
    return 0;

  if (grid[i][j])
    return 0;

  return DP[i][j] = (f(i + 1, j) + f(i, j + 1)) % mod;
}

int main() {
  memset(DP, -1, sizeof DP);

  cin >> n;

  char x;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> x;
      if  (x == '*') grid[i][j] = 1;
    }
  }

  cout << f(0, 0);
}
