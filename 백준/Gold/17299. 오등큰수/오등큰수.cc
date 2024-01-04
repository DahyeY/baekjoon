#include <iostream>
#include <stack>
using namespace std;

int main() {
	int N;
	cin >> N;

	stack<int> st;

	int arr[N+10];
    int cnt[1000000+10];
	int ans[N+10];
    
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
        ans[i] = -1;
        cnt[arr[i]] = 0;
	}
	for (int i = 0; i < N; i++) {
		cnt[arr[i]]++;
	}

	for (int i = 0; i < N; i++) {
		while (!st.empty() && cnt[arr[st.top()]] < cnt[arr[i]]) {
			ans[st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}

	//while (!st.empty()) {
	//	ans[st.top()] = -1;
	//	st.pop();
	//}

	for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

	return 0;
}