#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;

	string temp;
	vector<string> v;

	for (int i = 0; i < s.size(); i++) {
		temp = s.substr(i, s.length());
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}