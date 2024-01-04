#include <iostream>
using namespace std;

int func(int a, int b) {
	int r = a % b;

	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		int x;
		x = a * b / func(a, b);

		cout << x << endl;
	}
}