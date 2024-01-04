#include <iostream>
using namespace std;

int factorial(int n) {
	if (n == 1) return 1;
	return n * factorial(n - 1);
}
int main() {
	int n;
	int result = 1;
	cin >> n;
	if (n != 0) result = factorial(n);
	cout << result << endl;
	return 0;
}