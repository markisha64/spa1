
#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int>& A, int p, int q, int e) {
	while (p < q) {
		int mid = (p + q) / 2;

		if (A[mid] < e) p = mid + 1;
		else q = mid;
	}

	return p;
}

int main() {
	vector<int> polje = {-5, 3, 6, 8, 15 ,16};	

	int indeks = binarySearch(polje, 0, polje.size(), 15);

	cout << polje[indeks];
}
