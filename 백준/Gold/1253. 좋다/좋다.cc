#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n, 0);

	//입력
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//정렬
	sort(arr.begin(), arr.end());

	//좋은수 알고리즘 (투포인터)

	int count = 0;

	for (int i = 0; i < n; i++) {
		long find = arr[i];
		int s = 0, e = n - 1;

		while (s < e) {
			int sum;
			sum = arr[s] + arr[e];
			if (sum == find) {
				if (s != i && e != i) {
					count++;
					break;
				}
				else if (s == i)s++;
				else if (e == i)e--;

			}

			else if (sum < find) s++;
			else e--;
		}
	}

	cout << count << endl;
	return 0;
}
