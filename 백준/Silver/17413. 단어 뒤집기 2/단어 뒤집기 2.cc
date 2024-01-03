#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string S;
	getline(cin, S);

	stack<char> st;

	for (int i = 0; i < S.size() - 1; i++) {
		if (S[i] == '\<') {
			while (1) {
				
				cout << S[i];
				if (S[i] == '\>') break;
				i++;
				if (i == S.size()) break;
			}
		}
		else {
			while (1) {
				if (S[i] == ' ') break;
				if (S[i] == '\<') {
					i--;
					break;
				}
				st.push(S[i]);
				i++;
				if (i == S.size()) break;
			}

			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}
		}

		if (S[i] == ' ') {
			cout << S[i];
		}
	}

	return 0;

}