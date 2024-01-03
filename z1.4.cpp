
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

// sortiraj in place
void selection_sort(vector<int> &arr) {
  int length = arr.size();

  for (int i = 0; i < length - 1; i++) {
    int min_index = i;

    for (int j = i + 1; j < length; j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }

    swap(arr[i], arr[min_index]);
  }
}

void isprintaj(vector<int> &arr) {
  for (auto x : arr) {
    cout << x << ' ';
  }

  cout << endl;
}

vector<int> random_brojevi(int duljina) {
  vector<int> arr(duljina);

  for (auto& x : arr) {
    // do 9999
    x = rand() % 10000;
  }

  return arr;
}

int main() {
  srand(time(nullptr));

  vector<int> a = random_brojevi(5);

  // a)
  isprintaj(a);

  selection_sort(a);
  isprintaj(a);

  // prekasno je da sad radim b) i c)

  // d)
  auto tempiraj = [](int duljina) {

    double vrijeme = 0;
    for (int i = 0; i < 100; i++) {
      vector<int> arr = random_brojevi(duljina);

      double ct = clock();

      selection_sort(arr);

      vrijeme += clock() - ct;
    }
    
    return (vrijeme / 100) / (double)CLOCKS_PER_SEC;
  };


  cout << "Sortiranje arraya duljine 1000 avg: " << tempiraj(1000) << " sekundi" << endl; 
  cout << "Sortiranje arraya duljine 10000 avg: " << tempiraj(10000) << " sekundi" << endl; 
  cout << "Sortiranje arraya duljine 1000000 avg: " << tempiraj(1000000) << " sekundi" << endl; 

}