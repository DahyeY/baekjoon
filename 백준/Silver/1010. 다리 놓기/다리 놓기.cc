#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, m;
	cin >> t;
	while (t--) {

		cin >> n >> m;
		long ans;
		ans = 1;

		for (int i = 0; i < n; i++) {
			ans = (ans * (m - i)) / (i + 1);
		}

		cout << ans << " ";
	}

	return 0;
}
