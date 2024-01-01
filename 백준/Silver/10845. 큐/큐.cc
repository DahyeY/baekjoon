#include <iostream>
using namespace std;

class Queue {
public:
	int count;
	int *arr;
	
	Queue(int SIZE) {
		count = 0;
		arr = new int[SIZE];
	}


	void push(int x) {
		arr[count] = x;
		count++;
	}

	void pop() {
		if (count == 0) cout << "-1" << endl;
		else {
			cout << arr[0] << endl;
			for (int i = 0; i < count - 1; i++) {
				arr[i] = arr[i + 1];
			}
			count--;
		}
	}

	int size() {
		return count;
	}

	int empty() {
		if (count == 0) return 1;
		else return 0;
	}

	int front() {
		if (empty()) return -1;
		else return arr[0];
	}

	int back() {
		if (empty()) return -1;
		else return arr[count - 1];
	}
};


int main() {
	
	int N;
	cin >> N;
	Queue queue(N);

	string in;
	while (N--) {
		cin >> in;
		if (in == "push") {
			int x;
			cin >> x;
			queue.push(x);
		}
		else if (in == "pop") {
			queue.pop();
		}
		else if (in == "size") {
			cout << queue.size() << endl;
		}
		else if (in == "empty") {
			cout << queue.empty() << endl;
		}
		else if (in == "front") {
			cout << queue.front() << endl;
		}
		else if (in == "back") {
			cout << queue.back() << endl;
		}
	}

	return 0;
}