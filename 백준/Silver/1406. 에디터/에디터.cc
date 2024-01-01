#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main() {
	stack<char> left, right;
	string st, in;
	int M;
	cin >> st;

	for (int i = 0; i < st.length(); i++) {
		left.push(st[i]);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> in;

		if (in == "L") {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		if (in == "D") {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		if (in == "B") {
			if (!left.empty()) {
				left.pop();
			}
		}
		if (in == "P") {
			char c;
			cin >> c;
			left.push(c);
		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}

}