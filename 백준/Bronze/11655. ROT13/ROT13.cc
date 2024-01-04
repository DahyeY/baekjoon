#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			int temp = s[i] + 13;
			if (temp >= 97 + 26) temp -= 26;
			cout << char(temp);
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			int temp = s[i] + 13;
			if (temp >= 65 + 26) temp -= 26;
			cout << char(temp);
		}
		else {
			cout << s[i];
		}
	}
}