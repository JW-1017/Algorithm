#include <cstdio>

#pragma warning(disable:4996)

/*
input
50
30
24
5
28
45
98
52
60

output
5
28
24
45
30
60
52
98
50

https://www.acmicpc.net/problem/5639

/* Copyright (C) 2017 by Son */

using namespace std;

class t_node {
public:
	int num;
	t_node* left;
	t_node* right;

	t_node() {}
	t_node(int num) {
		this->num = num;
		this->left = NULL;
		this->right = NULL;
	}
};
class tree {
public:
	t_node* root;
	void post_order(t_node* temp) {
		if (temp->left != NULL) {
			post_order(temp->left);
		}
		if (temp->right != NULL) {
			post_order(temp->right);
		}
		printf("%d\n", temp->num);
	}
};

int main() {
	int temp_num, value;
	tree t;
	t_node* temp;

	scanf("%d", &value);

	t.root = new t_node(value);

	while (scanf("%d", &value) != EOF) {
		//if (value == -1) break;
		temp = t.root;
		temp_num = temp->num;
		while (1) {
			temp_num = temp->num;
			if (value < temp->num) {
				if (temp->left == NULL) {
					temp->left = new t_node(value);
					break;
				}
				else {
					temp = temp->left;
				}
			}
			else {
				if (temp->right == NULL) {
					temp->right = new t_node(value);
					break;
				}
				else {
					temp = temp->right;
				}
			}
		}
	}
	t.post_order(t.root);

	return 0;
}