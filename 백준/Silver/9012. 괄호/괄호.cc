#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main(void) {
	string str;
	int T;
	cin >> T;
	cin.ignore();

	stack<char> st;
	while (T--) {
		bool tf = true;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			st.push(str[i]);
			if (st.top() == ')') {
				st.pop();
				if (st.empty()) {
					tf = false;
					break;
				}
				if (st.top() == '(') {
					st.pop();
				}
			}
		}
		if (!tf) cout << "NO" << endl;
		else if (st.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
		while (!st.empty()) {
			st.pop();
		}
	}
	return 0;
}