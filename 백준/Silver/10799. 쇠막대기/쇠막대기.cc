#include <iostream>
#include <stack>
using namespace std;

int main() {
	string S;

	cin >> S;
	int size = S.size();
	stack<char> st;
	int i = 0;

	int sum = 0;
	while (size--) {
		if (S[i] == '(' && S[i + 1] == '(') {
			st.push('(');
		}
		else if (S[i] == '(' && S[i + 1] == ')') {
		 sum += st.size();
		}
		else if (S[i] == ')' && S[i + 1] == ')') {
			st.pop();
			sum++;
		}

		i++;
	}
	cout << sum << endl;

	return 0;
}