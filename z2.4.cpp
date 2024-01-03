
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergeSortStep(vector<int>& arr, int i, int n) {
	// gotovi smo ako ovo vrijedi
	cout << i << " " << n << endl;
	if ((n - i) <= 1) {
		return;
	} 

	int j = i + (n - i) / 2;
	int sn = i + (n - i) / 2;

	mergeSortStep(arr, i, sn);
	mergeSortStep(arr, j, n);
	
	int nj = j;
	for (int c = i; c < sn; c++) {
		
	}
}

void mergeSort(vector<int>& arr) {
	// gotovi smo ako ovo vrijedi
	if (arr.size() <= 1) 
		return;

	mergeSortStep(arr, 0, arr.size());	
}

void isprintaj(vector<int> &arr) {
  for (auto x : arr) {
    cout << x << ' ';
  }

  cout << endl;
}

int main() {
	vector<int> arr = {3, 2};

	isprintaj(arr);

	mergeSort(arr);
		
	isprintaj(arr);
}