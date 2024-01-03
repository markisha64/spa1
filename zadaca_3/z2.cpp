
#include <iostream>
#include <limits>

using namespace std;

// a b
// c d
class M2x2 {
public:
  int a;
  int b;
  int c;
  int d;
  M2x2(int a, int b, int c, int d);
  M2x2& operator*(M2x2 &a);
};

M2x2::M2x2(int a, int b, int c, int d) {
  this->a = a;
  this->b = b;
  this->c = c;
  this->d = d;
}

M2x2& M2x2::operator*(M2x2 &a) {
  int ai = this->a * a.a + this->b * a.c;
  int ci = this->c * a.a + this->d * a.c;
  int bi = this->a * a.b + this->b * a.d;
  int di = this->c * a.b + this->d * a.d;

  M2x2* res = new M2x2(ai, bi, ci, di);

  return *res;
}

template<class T>
T& fastPow(T& a, int e) {
  if (e <= 1) return a;

  if (e % 2 == 0) {
    T& res = fastPow(a, e / 2);

    return res * res;
  } else {
    T& res = fastPow(a, e / 2);

    return res * res * a;
  }
}

int fib(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  M2x2 start = M2x2(1, 1, 1, 0);
  M2x2& res = fastPow(start, n);

  return res.b;
}

int main() {
  int n;
  cin >> n;  

  cout << fib(n);
}
