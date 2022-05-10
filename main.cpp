#include <iostream>
#include <queue>
#include <set>
#include <chrono>
#include "Driver.h"

using namespace std::chrono;

class Node {
	friend class Tree;
private:
	int x;
	int y;
	int height;
	Node* neighbors[8]{};
public:
	Node(int x, int y, int height) {
		this->x = x;
		this->y = y;
		this->height = height;
	}
};

class Tree {
private:
	int **visit;
	int board_height;
	int board_width;
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	int steps = 0;
public:
	Tree(int board_height, int board_width, int start_x, int start_y, int end_x, int end_y) {
		this->board_height = board_height;
		this->board_width = board_width;
		this->start_x = start_x;
		this->start_y = start_y;
		this->end_x = end_x;
		this->end_y = end_y;

		visit = new int* [board_height];
		for (int i = 0; i < board_height; i++) {
			visit[i] = new int[board_width];
		}
		for (int x = 0; x < board_height; x++) {
			for (int y = 0; y < board_width; y++) {
				visit[x][y] = 0;
			}
		}
	}
	int makeTreeLevelOrder()
	{
		Node* node;

		// Create an empty queue for level order traversal
		std::queue<Node*> q;

		// Create move array for x and y direction
		int move_x[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
		int move_y[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

		// Create root node, enqueue it and label it as discovered
		node = new Node(start_x, start_y, 0);
		q.push(node);
		visit[start_x][start_y] == 1;
		
		// create integer for x, y values of neighbor
		int x;
		int y;

		while (q.empty() == false)
		{
			// print front of queue and remove it from queue
			node = q.front();
			q.pop();

			// if endposition reached stop the loop
			if (node->x == end_x && node->y == end_y) {
				visit[end_x][end_y] == 2;
				// printBoard();
				return node->height;
			}

			// create all possible next neighbors
			for (int i = 0; i < 8; i++) {

				// Define neighbors's x,y values 
				x = node->x + move_x[i];
				y = node->y + move_y[i];

				// check if neighbor has been visited before 
				// and check if neighbor is in the fields
				if (inField(x, y)) {
					if (visit[x][y] == 0) {
						// create neighbor, mark it as visited and push it to the queue
						createNeighbor(node, i, x, y);
						visit[x][y] = 1;
						// printBoard();
						q.push(node->neighbors[i]);
					}
				}
			}
		}
	}
	void createNeighbor(Node *parent, int id, int x, int y) {
		parent->neighbors[id] = new Node(x, y, parent->height + 1);
	}
	int inField(int x, int y) {
		if (x >= 0 && x < board_width && y >= 0 && y < board_height) {
			return true;
		}
		else {
			return false;
		}
	}
	void printBoard() {
		for (int x = 0; x < board_height; x++) {
			for (int y = 0; y < board_width; y++) {
				std::cout << visit[x][y] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

};

int MinimumSteps(int BoardHeight, int BoardWidth, int KnightStartXPosition, int KnightStartYPosition, int KnightEndXPosition, int KnightEndYPosition) {
	auto start = high_resolution_clock::now();

	Tree t(BoardHeight, BoardWidth, KnightStartXPosition, KnightStartYPosition, KnightEndXPosition, KnightEndYPosition);
	int steps;
	steps = t.makeTreeLevelOrder();

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stop - start);
	std::cout << "total execution time: " << duration.count() << " seconds" << std::endl;
	
	return steps;
}

int main() {
	std::cout << MinimumSteps(1000, 1000, 1, 2, 3, 4) << std::endl;
	std::cout << MinimumSteps(1000, 1000, 1, 2, 7, 7) << std::endl;
	std::cout << MinimumSteps(1000, 1000, 0, 0, 6, 6) << std::endl;
	std::cout << MinimumSteps(1000, 1000, 6, 4, 241, 230) << std::endl;
	std::cout << MinimumSteps(1000, 1000, 1, 2, 899, 899) << std::endl;

	return 0;
}