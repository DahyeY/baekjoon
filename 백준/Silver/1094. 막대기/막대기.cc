#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	cin >> x;

	vector<int> A;
	A.push_back(64);
	int size = 64;

	while (size > x) {
		int temp = A.back();
		A.pop_back();

		temp /= 2;

		if (size - temp >= x) {
			A.push_back(temp);
			size -= temp;
		}
		else {
			A.push_back(temp);
			A.push_back(temp);
		}
	}

	cout << A.size();

	return 0;
}
