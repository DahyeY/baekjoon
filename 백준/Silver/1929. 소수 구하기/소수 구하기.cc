#include <iostream>
using namespace std;

int main() {
	int M, N;
	int arr[1000000 + 1];
	cin >> M >> N;

	for (int i = 2; i <= N; i++) {
		arr[i] = i;
	}

	for (int i = 2; i * i <= N; i++) {
		if (arr[i] == 0)
			continue;

		for (int j = i * i; j <= N; j += i)
			arr[j] = 0;
	}

	for (int i = M; i <= N; i++) {
		if (arr[i] != 0) cout << arr[i] << '\n';
	}

	return 0;
}