
#include <cstring>
#include <iostream>

using namespace std;

int n;
int DP[100005];
int nums[1005];

bool f(int val) {
  if (DP[val] != -1)
    return DP[val];

  if (val == 0)
    return 1;

  if (val < 0)
    return 0;

  bool r = 0;
  for (int i = 0; i < n; i++) {
    r = r or !(f(val - nums[i]));
  }

  return DP[val] = r;
}

int main() {
  memset(DP, -1, sizeof DP);
  int k;

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  if (!f(k)) {
    cout << "Marica";
  } else {
    cout << "Ivica";
  }
}
