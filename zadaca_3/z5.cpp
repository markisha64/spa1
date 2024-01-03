
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> polje(n);
  for (int &x : polje) {
    cin >> x;
  }

  vector<int> psuma;
  int suma = 0;
  for (int i = 0 ; i < n; i++) {
    psuma.push_back(suma);
    suma += polje[i];
  }

  cout << psuma[3] - psuma[0];
}
