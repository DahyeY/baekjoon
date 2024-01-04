#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[26];

	string s;

	cin >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	stack<double> st;

	for (int i = 0; i < s.size(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			st.push(arr[s[i] - 'A']);
		}
		else {
			if (s[i] == '+') {
				double a = st.top();
				st.pop();
				double b = st.top();
				st.pop();
				st.push(b + a);
			}
			if (s[i] == '-') {
				double a = st.top();
				st.pop();
				double b = st.top();
				st.pop();
				st.push(b - a);
			}
			if (s[i] == '*') {
				double a = st.top();
				st.pop();
				double b = st.top();
				st.pop();
				st.push(b * a);
			}
			if (s[i] == '/') {
				double a = st.top();
				st.pop();
				double b = st.top();
				st.pop();
				st.push(b / a);
			}
		}
	}

	printf("%.2f", st.top());
	return 0;
}