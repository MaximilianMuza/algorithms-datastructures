#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

class Test {
private:
	int* results;
	int average = 0;
	int var = 0;
	int N;
public:
	Test(int x) {
		N = x;
		results = new int[N];
	}
	~Test() {
		delete[] results;
	}
	int test(int (*f)(int, int)) {
		for (int k = 1; k <= N; k++) {
			results[k - 1] = 0;
			for (int i = 0; i < 10; i++) {
				var = (*f)(k, N);
				results[k - 1] += var;
				// std::cout << "pq: " << k << ", " << var << std::endl;
			}
			results[k - 1] /= 10;
			average += results[k - 1];
		}
		return (average /= N);
	}
};

class PriorityQueue {
private:
	int* arr;
	int arrSize;
	int index = 0;
	int currentSize = 0;
	int input = 0;
	std::vector<int> numbers;
	int steps = 0;

public:
	PriorityQueue(int N) {
		arr = new int[N];
		arrSize = N;
		for (int a = 0; a < N; a++) {
			numbers.push_back(a + 1);
		}
		std::shuffle(std::begin(numbers), std::end(numbers), std::default_random_engine());
	}
	~PriorityQueue() {
		delete[] arr;
		numbers.clear();
	}
	void insert(int i) {
		input = numbers[i];
		index++;
		if (currentSize == arrSize - 1) {
			enlargeArray(arrSize * 2 + 1);
		}

		// Percolate up
		int hole = ++currentSize;
		for (; hole > 1 && compareBetween(input, arr[hole / 2]); hole /= 2) {
			arr[hole] = arr[hole / 2];
			steps++;
		}
		arr[hole] = input;
	}
	void deleteMin() {
		if (false) { 
			std::cout << "Heap is empty" << std::endl;
			return;
		}

		// Percolate down
		int hole = 1;
		for (; hole <= index / 2 && hole < arrSize;) {
			if (compareBetween(arr[2 * hole], arr[2 * hole + 1])) {
				// arr[2i] is smaller
				arr[hole] = arr[2 * hole];
				hole += hole;
			}
			else {
				// arr[2i+1] is smaller
				arr[hole] = arr[2 * hole + 1];
				hole += hole + 1;
				
			}
			steps++;
		}
		// make heap complete if not already complete
		 if (hole != index) {
			if (compareBetween(arr[hole], arr[index])) {
				 // arr[index] is bigger than arr[hole-old] and goes into that spot to make the heap complete
				 arr[hole] = arr[index];
			 } 
			else {
				// Percolate up
				int key = hole;
				for (; key > 1 && compareBetween(arr[index], arr[key / 2]); key /= 2) {
					arr[key] = arr[hole / 2];
					steps++;
				}
				arr[key] = arr[index];
			}
		}
		index--;
	}
	void enlargeArray(int length) {
		int* temp = new int[length];
		for (int j = 1; j < arrSize && j < index; j++) {
			steps++;
			*(temp+j) = arr[j];
		}
		delete[] arr;
		arr = temp;
		arrSize = length;
	}
	bool compareBetween(int val1, int val2) {
		if (val1 < val2) {
			return true;
		} 
		else {
			return false;
		}
	}
	int root() {
		return arr[1];
	}
	int getSteps() {
		return steps;
	}
};

int pqSelect(int k, int x) {
	PriorityQueue heap(x);

	for (int i = 0; i < x; i++) {
		heap.insert(i);
	}
	for (int j = 1; j != k; j++) {
		heap.deleteMin();
	}
	// std::cout << "The " << k << "'th smallest element in the list is " << heap.root() << std::endl;
	// std::cout << "The steps to select the k'th item from an unsorted list with N = " << N << " items is: " << heap.getSteps() << std::endl;
	return heap.getSteps();
}

int main() {
	Test** c;
	c = new Test*[10];
	int N = 1000;
	std::cout << "The average number of instructions is:" << std::endl;
	for (int i = 0; i < 10; i++) {
		c[i] = new Test(N);
		std::cout << c[i]->test(pqSelect) << " for N = " << N << std::endl;
		N += 1000;
	}


	return 0;
}

