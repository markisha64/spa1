
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int DP[100001][3];
int n;
int a[100001], b[100001], c[100001];

int f(int i, int prev) {
  if (prev >= 0 && DP[i][prev] != -1) {
    return DP[i][prev];
  }

  if (i == n)
    return 0;  

  switch (prev) {
    case 0:
      return DP[i][prev] = max({f(i + 1, 1) + b[i], f(i + 1, 2) + c[i]});
    case 1:
      return DP[i][prev] = max({f(i + 1, 0) + a[i], f(i + 1, 2) + c[i]});
    case 2:
      return DP[i][prev] = max({f(i + 1, 1) + b[i], f(i + 1, 0) + a[i]});
    default:
      return max({f(i + 1, 0) + a[i], f(i + 1, 1) + b[i], f(i + 1, 2) + c[i]});
  }
}

int main() {
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }

  memset(DP, -1, sizeof DP);

  cout << f(0, -1);  
}
