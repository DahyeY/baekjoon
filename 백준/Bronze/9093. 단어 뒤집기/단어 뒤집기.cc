#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main() {
	int T;
	cin >> T;
	cin.ignore();
	string str;
	stack<char> st;
	for (int i = 0; i < T; i++) {
		getline(cin, str);
		str += ' ';
		for (int j = 0; j < str.length(); j++) {

			if (str[j] == ' ') {
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << ' ';
			}
			else {
				st.push(str[j]);
			}
		}
		cout << endl;
	}
	return 0;
}