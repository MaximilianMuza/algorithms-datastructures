#include <iostream>

class Circ {
private:
	int* circ;
	int top = -1;
	int bottom = 0;
public:
	Circ() {
		circ = new int[8];
	}
	~Circ() {
		delete[] circ;
	}
	void queue(int input) {
		top++;
		if (top >= 8) {
			top = 0;
		}
		if (top == bottom) {
			return;
		}
		circ[top] = input;
		print(bottom, top);
	}
	void dequeue() {
		bottom++;
		print(bottom, top);
	}
	void print(int low, int high) {
		/*if (low > high) {
			int var = high;
			high = low;
			low = var;
		}
		std::cout << "[";
		for (int i = low; i <= high; i++) {
			if (i == high) {
				std::cout << circ[i];
			}
			else {
				std::cout << circ[i] << ", ";
			}
		}
		std::cout << "]" << std::endl;
		*/
		std::cout << "[";
		for (int i = 0; i < 8; i++) {
			std::cout << circ[i] << ", ";
		}
		std::cout << "]" << std::endl;
	}
};

int main() {
	Circ c1;
	c1.queue(0);
	c1.queue(1);
	c1.queue(2);
	c1.queue(3);
	c1.queue(4);
	c1.queue(5);
	c1.queue(6);
	c1.queue(7);
	c1.dequeue();
	c1.dequeue();
	c1.queue(8);
	c1.queue(9);
	c1.queue(10);
	c1.dequeue();
	c1.queue(10);
	return 0;
}