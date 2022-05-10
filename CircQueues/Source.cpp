#include <iostream>
#define N 8

class Circ {
private:
	int* circ;
	int free = N;
	int set = -1;
	int round = 0;
public:
	Circ() {
		circ = new int[N];
		for (int j = 0; j < N; j++) {
			circ[j] = 0;
		}
	}
	~Circ() {
		delete [] circ;
	}
	void queue(int input) {
		if (set + 1 == free) {
			std::cout << "No space in " << set + 1 << std::endl;
			return;
		}
		else {
			set++;
			if (set % N == 0 && set != 0) {
				round++;
			}
			circ[set - round * N] = input;
			print();
		}
	}
	void dequeue() {
		if (free == set || set == -1) {
			std::cout << "Everything is freed already" << std::endl;
			return;
		}
		free++;
		print();
	}
	void print() {
		std::cout << "[";
		for (int i = 0; i < N; i++) {
			if (i == N - 1) {
				std::cout << circ[i];
			}
			else {
				std::cout << circ[i] << ", ";
			}
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
	c1.queue(8);
	c1.queue(9);
	c1.dequeue();
	c1.queue(8);
	c1.dequeue();
	c1.dequeue();
	c1.dequeue();
	c1.dequeue();
	c1.dequeue();
	c1.dequeue();
	c1.queue(9);
	c1.queue(10);
	c1.queue(11);
	c1.queue(12);
	c1.queue(13);
	c1.queue(14);
	c1.dequeue();
	c1.queue(15);
	c1.dequeue();
	c1.queue(16);
	return 0;
}