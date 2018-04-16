#include <iostream>
#include <sstream>

using namespace std;

class tree_t
{
private:
	struct node_t {
		node_t * left;
		node_t * right;
		int key;
	};
private:
	node_t * root_;
public:
	tree_t();
	void insert(int key);
	bool find(int key) const;
	void print(std::ostream & stream) const;
	void rout(std::ostream & stream, const node_t * temp, int count) const;
};

tree_t::tree_t()
{
	root_ = nullptr;
}

void tree_t::insert(int key) {
	node_t * branch = new node_t;
	branch->key = key;
	branch->left = nullptr;
	branch->right = nullptr;

	if (root_ == nullptr) {
		root_ = branch;
	}
	else {
		node_t * temp = root_;
		while (temp != nullptr) { 
			if (key > temp->key) {
				if (temp->right != nullptr) {
					temp = temp->right;
				}
				else {
					temp->right = branch;
					return;
				}
			}
			else {
				if (temp->left != nullptr) {
					temp = temp->left;
				}
				else {
					temp->left = branch;
					return;
				}
			}

		}
	}
}

bool tree_t::find(int key) const {
	node_t * branch = root_;
	while (branch != nullptr) {
		if (key > branch->key) {
			branch = branch->right;
		}
		else if (key < branch->key) {
			branch = branch->left;
		}
		else {
			return true;
		}
	}
	return false;
}

void tree_t::print(std::ostream & stream) const {
	int count = 1;
	rout(stream, root_, count);
}

void tree_t::rout(std::ostream & stream, const node_t * temp, int i) const {
	if (temp->right) {
		i++;
		rout(stream, temp->right, i);
		i--;
	}
	for (int k = 0; k < i; k++) {
		stream << "--";
	}
	stream << temp->key << std::endl;
	if (temp->left) {
		i++;
		rout(stream, temp->left, i);
		i--;
	}
}


int main() {
	tree_t in;
	char symbol;
	int k;
	bool q = true;
	while (q) {
		cin >> symbol;
		switch (symbol) {
		case '+': {
			cin >> k;
			in.insert(k);
			in.print(cout);
		}
				  break;
		case '?': {
			cin >> k;
			if (in.find(k) == 1) {
				cout << "true";
			}
			else {
				cout << "false";
			}
		}
				  break;
		case '=': {
			in.print(cout);
		}
				  break;
		case 'q': {
			q = false;
		}
				  break;
		}
	}

	return 0;
}
