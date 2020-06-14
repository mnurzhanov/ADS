#include <iostream>
#include <string>
using namespace std;
#define SIZE 1000000000

struct stack {
	unsigned long long storage[SIZE];
	int cursor = 0;
	void push (int n) {
		storage[cursor] = n;
		cursor++;
	}
	int pop () {
		return storage[--cursor];
	}
	int back () {
		return storage[cursor-1];
	}
	unsigned int size () {
		return cursor;
	}

};
int main () {
	stack s;
	string str;
	int n;
	int Q;
	cin >> Q;
	for(int i = 0; i < Q; i++)) {
		if (str == "PUSH") {
			cin >> n;
			s.push(n);
			cout << "ok" << endl;
		}
		else if (str == "POP") cout << s.pop() << endl;
		else if (str == "WHAT") cout << s.size() << endl;

	}
	return 0;
}