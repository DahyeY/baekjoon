#include <iostream>
using namespace std;

int main() {
	string s;
	int arr[26] = { -1 };
	cin >> s;

	for (int j = 'a'; j <= 'z'; j++) {
		for (int i = 0; i < s.size(); i++) {
			if (j == s[i]) {
				arr[j - 'a'] = i;
				break;
			}
			else arr[j - 'a'] = -1;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}


	return 0;
}