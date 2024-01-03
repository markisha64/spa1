
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int DP[1000005];

int f(int n) {
  if (DP[n] != -1)
    return DP[n];

  if (n < 10)
    return 1;

  int num = n;
  int r = 1e9;
  while (num) {
    int znamenka = num % 10;

    if (znamenka != 0)
      r = min(r, f(n - znamenka) + 1);

    num /= 10;
  }

  return DP[n] = r;
}

int main() {
  memset(DP, -1, sizeof DP);

  int n;
  cin >> n;

  cout << f(n);
}
