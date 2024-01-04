#include <iostream>
using namespace std;


int main() {
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 5; i <= n; i *= 5) {
		ans += n / i;
	}
	cout << ans;
	return 0;
}