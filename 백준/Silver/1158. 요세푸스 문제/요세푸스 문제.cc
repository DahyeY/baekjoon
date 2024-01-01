#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N;
	cin >> K;

	int* arr;
	arr = new int[N];

	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}


	cout << "<";
	int idx = 0;
	int size = N;
	for (int i = 0; i < N - 1; i++) {
		idx += K;
		idx -= 1;
		idx %= size;
		
		if (idx < 0) idx = size - 1;

		cout << arr[idx] << ", ";

		for (int j = idx; j < size; j++) {
			arr[j] = arr[j + 1];
		}

		size--;
	}
	cout << arr[0] << ">" << endl;

	return 0;
}
