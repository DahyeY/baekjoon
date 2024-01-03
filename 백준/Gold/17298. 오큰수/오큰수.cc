#include <iostream>
#include <stack>
using namespace std;

int main() {
	int N;
	cin >> N;

	stack<int> st;

	int* arr = new int[N];
	int num;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int* ans = new int[N];

	for (int i = 0; i < N; i++) {
		while (!st.empty() && arr[st.top()] < arr[i]) {
			ans[st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}

	while (!st.empty()) {
		ans[st.top()] = -1;
		st.pop();
	}

	for (int i = 0; i < N; i++) cout << ans[i] << " ";


	return 0;
}