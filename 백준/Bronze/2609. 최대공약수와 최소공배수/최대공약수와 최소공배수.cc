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
	int a, b;
	cin >> a >> b;
	int A, B; //최대공약수, 최소공배수
	A = func(a, b);
	B = a * b / func(a, b);

	cout << A << endl
		<< B << endl;
}