#include <iostream>

class Stack {
	char* stack;
	int top_ptr = -1;
public:
	Stack(int capacity) {
		stack = new char[capacity];
	}
	~Stack() {
		delete stack;
	}
	void push(char c) {
		top_ptr++;
		*(stack + top_ptr) = c;
	}
	void pop() {
		top_ptr--;
	}
	char top() {
		return stack[top_ptr];
	}
	int size() {
		return top_ptr + 1;
	}
};

bool balPar(std::string text) {
	Stack stack(text.length());
	for (int i = 0; i < text.length(); i++) {
		if(text[i] == '(') {
			stack.push('(');
		}
		else if (text[i] == ')') {
			if (stack.size() <= 0 || stack.top() != '(') { return false; }
			else { stack.pop(); }
		}
		else if (text[i] == '[') {
			stack.push('[');
		}
		else if (text[i] == ']') {
			if (stack.size() <= 0 || stack.top() != '[') { return false; }
			else { stack.pop(); }
		}
		else if (text[i] == '{') {
			stack.push('{');
		}
		else if (text[i] == '}') {
			if (stack.size() <= 0 || stack.top() != '{') { return false; }
			else { stack.pop(); }
		}
	}
	return stack.size() == 0;
}

int main() {
	std::string text;
	text = "Hallo()[{]}";
	std::cout << text << ": " << balPar(text) << std::endl;

	return 0;
}