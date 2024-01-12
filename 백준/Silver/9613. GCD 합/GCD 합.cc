#include <iostream>
#include <array>
using namespace std;

int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int arr[100];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int ans[100 * 99 / 2] = { 0 };
		int cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				ans[cnt] = gcd(arr[i], arr[j]);
				cnt++;
			}
		}

		long long sum = 0;
		for (int i = 0; i < sizeof ans / sizeof ans[0]; i++) {
			sum += ans[i];
		}
		cout << sum << endl;
	}

	return 0;
}