#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;

	vector<int> A(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n-1; i++) {
		for (int j = 1; j < n - i; j++) {
			if (A[i] > A[i + j]) swap(A[i], A[i + j]);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << A[i] << endl;
	}

	return 0;
}
