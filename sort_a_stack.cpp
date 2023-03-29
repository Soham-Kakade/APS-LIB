#include <stack>
#include <iostream>

using namespace std;

void sortStack(stack<int> &s) {
	if (s.empty())
		return;

	int x = s.top();
	s.pop();

	sortStack(s);

	stack<int> tempStack;

	while (!s.empty() && s.top() > x) {
		tempStack.push(s.top());
		s.pop();
	}

	s.push(x);

	while (!tempStack.empty()) {
		s.push(tempStack.top());
		tempStack.pop();
	}
}

int main() {
	stack<int> s;

	s.push(34);
	s.push(3);
	s.push(31);
	s.push(98);
	s.push(92);
	s.push(23);

	sortStack(s);

	cout << "Sorted numbers are: ";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}
