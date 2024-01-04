#include <iostream>
using namespace std;

int main() {
	int N, result = 0;
	int num, cnt;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		cnt = 0;
		for (int div = 1; div <= num; div++) {
			if (num % div == 0)
				cnt++;
		}

		if (cnt == 2)
			result++;
		
	}

	cout << result << endl;
	return 0;
}