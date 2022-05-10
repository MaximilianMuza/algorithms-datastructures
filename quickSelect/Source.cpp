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

class Qs {
private:
	int steps = 0;
	std::vector<int> arr;
	int length;
public:
	Qs(int N) {
		length = N;
		for (int a = 0; a < N; a++) {
			arr.push_back(a + 1);
		}
		std::shuffle(std::begin(arr), std::end(arr), std::default_random_engine());
	}
	~Qs() {
		arr.clear();
	}
	void swap(int a, int b) {
		int tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}
	int partition(int left, int right, int pivotIndex)
	{
		int pivot = arr[pivotIndex];

		swap(pivotIndex, right);
		int pIndex = left;
		for (int i = left; i < right; i++)
		{
			if (arr[i] <= pivot)
			{
				swap(i, pIndex);
				pIndex++;
				steps++;
			}
			steps++;
		}
		swap(pIndex, right);
		return pIndex;
	}
	int select(int left, int right, int k)
	{
		steps++;
		if (left == right)
			return arr[left];

		int pivotIndex = left + rand() % (right - left + 1);
		pivotIndex = partition(left, right, pivotIndex);

		if (k == pivotIndex)
			return arr[k];
		else if (k < pivotIndex)
			return select(left, pivotIndex - 1, k);
		else
			return select(pivotIndex + 1, right, k);
	}
	int getSteps() {
		return steps;
	}
};

int quickSelect(int k, int N) {
	Qs qs(N);
	qs.select(0, N - 1, k - 1);
	return qs.getSteps();
}

int main() {
	// std::cout << "K'th smallest element is " << qs.quickselect(0, N-1, k-1) << std::endl;
	// std::cout << "It took " << qs.getSteps() << " steps to find the kth value." << std::endl;
	
	Test** c;
	c = new Test*[10];
	int N = 1000;
	std::cout << "The average number of instructions is:" << std::endl;
	for (int i = 0; i < 10; i++) {
		c[i] = new Test(N);
		std::cout << c[i]->test(quickSelect) << " for N = " << N << std::endl;
		N += 1000;
	}

	return 0;
}