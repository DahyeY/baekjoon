#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main(void) {
	int n;
	cin >> n;
	int N = n;
	stack<int> st;
	int i;
	int j = 1;
	string cst;

	while (n--) {

		cin >> i;


		while (j <= i) {
			st.push(j);
			cst += '+';
			j++;

		}
		if (i == st.top()) {
			st.pop();
			cst += '-';
		}
		else {
			cout << "NO" << endl;
			break;
		}
	}
	if (st.empty())
		for (int i = 0; i < cst.length(); i++) cout << cst[i] << "\n";



	return 0;
}