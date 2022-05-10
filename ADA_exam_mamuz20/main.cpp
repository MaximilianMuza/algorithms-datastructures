#include <iostream>

int sumDivisibleBy3(int N) {
	if (N == 3) {
		return 3;
	}
	if (N % 3 == 0) {
		return sumDivisibleBy3(N - 3) + N;
	} 
	else {
		return sumDivisibleBy3(N - (N % 3));
	}
}

int* findCoefficients(int Z) {
	int final[2] = { 0,0 };
	int Z_curr = 0;
	for (int X = 3; X < 47; X++) {
		Z_curr = X;
		for (int Y = 2; Y < 11; Y++) {
			Z_curr *= X;
			if (Z_curr == Z) {
				if (X > final[0]) {
					final[0] = X;
					final[1] = Y;
				}
			}
		}
	}
	return final;
}

int main() {
	// Exercise two
	std::cout << "Task 2" << std::endl;
	std::cout << "Sum of N divisible by 3 => "<< sumDivisibleBy3(14) << std::endl;
	
	std::cout << std::endl;

	// Exercise 4
	std::cout << "Task 4" << std::endl;
	int* final;
	final = findCoefficients(6561);
	std::cout << "(X,Y) : " << "(" << final[0] << "," << final[1] << ")" <<  std::endl;


	return 0;
}