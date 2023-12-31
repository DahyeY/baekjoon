#include <iostream>
#include <stack>
using namespace std;


int main() {
	stack<int> stack;
	int number;
	cin >> number;
	for (int i = 0; i < number; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int i;
			cin >> i;
			stack.push(i);
		}
		else if (str == "pop") {
			if (stack.empty()) cout << "-1" << endl;
			else {
				cout << stack.top() << endl;
				stack.pop();
			}
		}
		else if (str == "size") {
			cout << stack.size() << endl;
		}
		else if (str == "empty") {
			if (stack.empty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
		else if (str == "top") {
			if (stack.empty()) cout << "-1" << endl;
			else cout << stack.top() << endl;
		}
	}
	return 0;
}