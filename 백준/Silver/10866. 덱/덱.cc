#include <iostream>
using namespace std;

class Deque {
private:
	int* arr;
	int cnt;

public:
	Deque(int SIZE) {
		arr = new int[SIZE];
		cnt = 0;
	}

	void push_front(int x) {
		for (int i = cnt; i > 0; i--) {
			arr[i] = arr[i - 1];
		}
		arr[0] = x;
		cnt++;
	}

	void push_back(int x) {
		arr[cnt] = x;
		cnt++;
	}

	void pop_front() {
		if (empty()) cout << -1 << endl;
		else {
			cout << arr[0] << endl;
			for (int i = 0; i < cnt; i++) {
				arr[i] = arr[i + 1];
			}
			arr[cnt - 1] == NULL;
			cnt--;
		}
	}

	void pop_back() {
		if (empty()) cout << -1 << endl;
		else {
			cout << arr[cnt - 1] << endl;
			arr[cnt - 1] == NULL;
			cnt--;
		}
	}

	void size() {
		cout << cnt << endl;
	}

	int empty() {
		if (cnt == 0) return 1;
		else return 0;
	}

	void front() {
		if (empty()) cout << -1 << endl;
		else cout << arr[0] << endl;
	}
	void back() {
		if (empty()) cout << -1 << endl;
		else cout << arr[cnt - 1] << endl;
	}
};

int main() {
	int N;
	cin >> N;
	Deque deque(N);

	string in;
	while (N--) {
		cin >> in;
		if (in == "push_front") {
			int x;
			cin >> x;
			deque.push_front(x);
		}
		else if (in == "push_back") {
			int x;
			cin >> x;
			deque.push_back(x);
		}
		else if (in == "pop_front") {
			deque.pop_front();
		}
		else if (in == "pop_back") {
			deque.pop_back();
		}
		else if (in == "size") {
			deque.size();
		}
		else if (in == "empty") {
			cout << deque.empty() << endl;
		}
		else if (in == "front") {
			deque.front();
		}
		else if (in == "back") {
			deque.back();
		}
	}

	return 0;
}
