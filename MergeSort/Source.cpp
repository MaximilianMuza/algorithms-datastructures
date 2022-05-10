#include <iostream>
#include <queue>
#include <stack>

int main() {
	std::queue<int> q;
	q.push(5);
	q.push(10);
	std::cout << q.front() << std::endl;

	// Removing/Extracting the content from the queue container
	while (!q.empty()) {
		q.pop();
	}

	return 0;
}