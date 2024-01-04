#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string arr[4];
	string a, b;
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}
	a = arr[0] + arr[1];
	b = arr[2] + arr[3];

	long aa = 0, bb = 0;
	long as = a.size();
	long bs = b.size();

	for (int i = 0; i < a.size(); i++) {
		aa = aa + (pow(10, --as) * (a[i] - 48));
	}
	for (int i = 0; i < b.size(); i++) {
		bb += (pow(10, --bs) * (b[i] - 48));
	}
	cout << aa + bb;
}