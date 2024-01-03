
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &A, int p, int q) {
  int mid = (p + q) / 2;
  int pivot = A[mid];
  int i = p;

  // prva polovica
  for (int j = p + 1; j < mid; j++) {
    if (A[j] <= pivot) {
      i = i + 1;
      swap(A[i], A[j]);
    }
  }

  // druga polovica
  for (int j = mid + 1; j <= q; j++) {
    if (A[j] <= pivot) {
      i = i + 1;

      // ako smo dosli do mida, preskoci
      // mozda ovo prebaciti i iza prve polovice?
      if (i == mid) i++;

      swap(A[i], A[j]);
    }
  }

  swap(A[mid], A[i]);

  return i;
}

void QSort(vector<int> &A, int p, int r) {
  if (p < r) {
    int q = partition(A, p, r);
    QSort(A, p, q - 1);
    QSort(A, q + 1, r);
  }
}

void QuickSort(vector<int> &A) {
  QSort(A, 0, A.size());
}

void isprintaj(vector<int> &A) {
  for (int x: A) {
    cout << x << ' ';
  }

  cout << endl;
}

int main() {
  vector<int> polje = {2, -5, 3, 9, -1, 6};
  isprintaj(polje);
  QuickSort(polje);
  isprintaj(polje);
  
  // Memorijska kompleksnost je trivijalna jer
  // algoritam ne alocira dodatnu memoriju osim 
  // nekoliko varijabli na stacku, otprilike Sigma(n)
  
  // Sto se tice vremenske kompleksnosti
  // kao i sa pivotom prvi element
  // worst case je Sigma(n**2), a average
  // je Sigma(nlogn)
}
