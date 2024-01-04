#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	
	
	while (getline(cin, s)) {
		int arr[4] = { 0 };
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') arr[0]++;
			if (s[i] >= 'A' && s[i] <= 'Z') arr[1]++;
			if (s[i] >= '0' && s[i] <= '9') arr[2]++;
			if (s[i] == ' ') arr[3]++;
		}

		for (int i = 0; i < 4; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;

	}
	return 0;
}