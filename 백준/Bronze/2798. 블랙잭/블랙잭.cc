#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	vector<int> A(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = A[i] + A[j] + A[k];
				if (ans < sum && sum <= m) ans = sum;
			}
		}
	}

	cout << ans << endl;



	return 0;
}
