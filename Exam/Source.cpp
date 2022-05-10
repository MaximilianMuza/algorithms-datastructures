#include <iostream>

class Chain {
public:
	int val;
	Chain* next;
	Chain(int val, Chain* next) {
		this->val = val;
		this->next = next;
	}
};

int findPatho1();
int findPatho2();
int getLongestChain(int N);
int createChain(int X);

int findPatho2() {
	int steps = 0;
	for (int c = 2; c < 997; c++) {
		for (int b = 1; b < c; b++) {
			int a = 1000 - b - c;
			steps++;
			if (a * a + b * b == c * c) {
				return steps;
			}
		}
	}
	return 0;
}
int findPatho1() {
	int steps = 0;
	for (int c = 2; c < 997; c++) {
		for (int b = 1; b < c; b++) {
			for (int a = 0; a < b; a++) {
				steps++;
				if (a + b + c == 1000) {
					if (a * a + b * b == c * c) {
						return steps;
					}
				}
			}
		}
	}
	return 0;
}
int getLongestChain(int N) {
	int *chains;
	chains = new int[N];
	for (int i = 1; i <= N; i++) {
		chains[i - 1] = createChain(i);
	}
	int max_val = 0;
	int max_ind = 0;
	for (int j = 0; j < N; j++) {
		if (chains[j] > max_val) {
			max_val = chains[j];
			max_ind = j;
		}
	}
	return max_ind + 1;

}
int createChain(int X) {
	Chain* curr = new Chain(X, nullptr);
	int length = 0;
	while (X != 1) {
		if (X % 2 == 0) {
			curr->next = new Chain(X / 2, nullptr);
			X = X / 2;
		}
		else {
			curr->next = new Chain(3*X + 1, nullptr);
			X = 3 * X + 1;
		}
		length++;
		curr = curr->next;
	}
	return length;
}

int getNumberEqual(int x[], int n, int val) {

	return sizeof(x[0]);
}

int main() {
	std::cout << findPatho1() << std::endl;
	std::cout << findPatho2() << std::endl;
	std::cout << getLongestChain(10000) << std::endl;
	int x[8] = { 7,4,1,3,5,6,4,8};
	std::cout << getNumberEqual(x, 8, 4) << std::endl;
	return 0;
}