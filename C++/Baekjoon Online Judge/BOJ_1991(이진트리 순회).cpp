#include <iostream>
#include <string>
/*
input
7
A B C
B D .
C E F
E . .
F . G
D . .
G . .

output
ABDCEFG
DBAECFG
DBEGFCA

https://www.acmicpc.net/problem/1991

/* Copyright (C) 2017 by Son */

using namespace std;

// 이 방법보다 알파벳 vector배열 27개를 만들고 0번째 요소 왼쪽노드 1번째 요소 오른쪽노드 하는 방법이 더 빠르다
class node {
public:
	char a;
	node* parent;
	node* left;
	node* right;
	node(char a) {
		this->a = a;
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
	}
	node(char a, node* parent) {
		this->a = a;
		this->parent = parent;
		this->left = NULL;
		this->right = NULL;
	}
	void insert_left(char c) {
		this->left = new node(c, this);
	}
	void insert_right(char c) {
		this->right = new node(c, this);
	}
};

class tree {
public:
	node* root;
	node* target;

	tree() {
		this->root = new node('A');
		this->target = NULL;
	}
	void find_node(node* t, char a) {
		if (target != NULL) {
			return;
		}
		if (t->left != NULL) {
			find_node(t->left, a);
		}
		if (t->right != NULL) {
			find_node(t->right, a);
		}
		if (t->a == a) {
			target = t;
		}
	}
	string s_pre_order(node* t) {
		string result = "";
		pre_oreder(t, result);
		return result;
	}
	void pre_oreder(node* t, string& result) {
		result += t->a;
		if (t->left != NULL) {
			pre_oreder(t->left, result);
		}
		if (t->right != NULL) {
			pre_oreder(t->right, result);
		}
	}
	string s_in_order(node* t) {
		string result = "";
		in_oreder(t, result);
		return result;
	}
	void in_oreder(node* t, string& result) {
		if (t->left != NULL) {
			in_oreder(t->left, result);
		}
		result += t->a;
		if (t->right != NULL) {
			in_oreder(t->right, result);
		}
	}
	string s_post_order(node* t) {
		string result = "";
		post_oreder(t, result);
		return result;
	}
	void post_oreder(node* t, string& result) {
		if (t->left != NULL) {
			post_oreder(t->left, result);
		}
		if (t->right != NULL) {
			post_oreder(t->right, result);
		}
		result += t->a;
	}
};

int main() {
	int i = 0, num;
	char me, left, right;
	tree t;
	node* root = t.root;

	cin >> num;

	cin >> me >> left >> right;
	if (left != '.') {
		root->insert_left(left);
	}
	if (right != '.') {
		root->insert_right(right);
	}

	for (; i < num - 1; i++) {
		cin >> me >> left >> right;
		if (left == '.' && right == '.') {
			continue;
		}
		t.find_node(root, me);
		if (left != '.') {
			t.target->insert_left(left);
		}
		if (right != '.') {
			t.target->insert_right(right);
		}
		t.target = NULL;
	}
	cout << t.s_pre_order(root) << endl;
	cout << t.s_in_order(root) << endl;
	cout << t.s_post_order(root) << endl;
	return 0;
}