#include <iostream>

class TreeNode {
	friend class BinaryTree;
private:
	int val;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(int x, TreeNode* l, TreeNode* r) {
		val = x;
		left = l;
		right = r;
	}
};

class BinaryTree {
private:
	int tot_depth = 0;
protected:
	TreeNode* root;
public:
	BinaryTree() {
		root = NULL;
	}
	TreeNode* insert(int input, TreeNode *current) {
		if (current == NULL) {
			if (root == NULL) {
				return root = new TreeNode(input, NULL, NULL);
			}
			else {
				return new TreeNode(input, NULL, NULL);
			}
		}
		if (input < current->val) {
			current->left = insert(input, current->left);
		}
		else if (input > current->val) {
			current->right = insert(input, current->right);
		}
		return current;
	}
	TreeNode* remove(int input, TreeNode *current) {
		if (current == NULL)
			return current; 

		if (input < current->val)
			current->left = remove(input, current->left);
		else if (input > current->val)
			current->right = remove(input, current->right);
		else if (current->left != NULL && current->right != NULL)
		{
			current->val = findMin(current->right)->val;
			current->right = remove(current->val, current->right);
		}
		else
			current = (current->left != NULL) ? current->left : current->right;
		return current;

	}
	TreeNode* findMin(TreeNode* current) {
		if (current == NULL) {
			return NULL;
		} 
		if(current->left == NULL) {
			return current;
		} 
		else {
			findMin(current->left);
		}
	}
	bool contains(int input, TreeNode* current) {
		if (current == NULL) {
			return false;
		}
		if (input < current->val) {
			contains(input, current->left);
		}
		else if (input > current->val) {
			contains(input, current->right);
		}
		else {
			return true;
		}
	}
	void preOrder(TreeNode* current) {
		if (current == NULL) {
			return;
		}
		printNode(current);
		preOrder(current->left);
		preOrder(current->right);
	}
	void inOrder(TreeNode* current) {
		if (current == NULL) {
			return;
		}
		inOrder(current->left);
		printNode(current);
		inOrder(current->right);
	}
	void postOrder(TreeNode* current) {
		if (current == NULL) {
			return;
		}
		postOrder(current->left);
		postOrder(current->right);
		printNode(current);
	}
	TreeNode* getRoot() {
		return root;
	}
	void printNode(TreeNode* current) {
		std::cout << current->val << std::endl;
	}
	int depth(int curr_depth, TreeNode* current) {
		if (current == NULL) {
			return 0;
		}
		return curr_depth + depth((curr_depth + 1), current->left) + depth((curr_depth + 1), current->right);
	}
	void makePerfectTree(int height) {
		for (int i = 0; i < getN(height); i++) {
			insert(i + 1, root);
		}
	}
	int getN(int height) {
		if (height == 0) {
			return 1;
		}
		return 2 * getN(--height);
	}
	
};

int main() {
	BinaryTree t;
	t.insert(5, t.getRoot());
	t.insert(7, t.getRoot());
	t.insert(3, t.getRoot());
	t.insert(6, t.getRoot());
	t.insert(4, t.getRoot());
	t.insert(8, t.getRoot());
	t.insert(2, t.getRoot());
	t.insert(1, t.getRoot());
	t.insert(10, t.getRoot());
	t.inOrder(t.getRoot());
	std::cout << "----------------" << std::endl;

	// Get internal path legth
	std::cout << "Internal path legth is: " << t.depth(0, t.getRoot()) << std::endl;

	std::cout << "----------------" << std::endl;

	// Make Perfect Tree with Height 
	t.makePerfectTree(4);
	t.inOrder(t.getRoot());


	return 0;
}