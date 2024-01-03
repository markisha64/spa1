
#include<iostream>
#include<vector>

using namespace std;

int unimodalBinarySearch(vector<int>& A, int p, int q, int e) {
	while (p < q) {
		int m1 = p + (q - p) / 3;
		int m2 = q - (q - p) / 3;

		if (e < A[m1]) p = m1 + 1;
		else if (e > A[m2]) q = m2 - 1;
		else { p = m1 + 1; q = m2 - 1; }
	}

	return p;
}

int main() {
	vector<int> polje = {-5, 3, 6, 8, 15 ,16, 4, 3, -5, -11, -20};	

	int indeks = unimodalBinarySearch(polje, 0, polje.size(), 4);

	cout << polje[indeks];
}
