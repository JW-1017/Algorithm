#include <iostream>
#include <string>
#include <sstream>

/*
input
7 3

output
<3, 6, 2, 7, 5, 1, 4>

https://www.acmicpc.net/problem/11866

/* Copyright (C) 2017 by Son */

using namespace std;

template <class T>
class queue {
private:
	T* arr;
	int num;
	int pop_point;
	int push_point;
public:
	queue(){
		this->num = 100;
	}
	queue(int num) {
		this->num = num+1;
		arr = new T[num+1];
		//push_point = 0;
		pop_point = 0;
		this->init();
	}
	// 조세퍼스를 위한 것(main에서 push num번 해도 됨)
	void init() {						
		for (int i = 1; i < num; i++) {
			arr[i] = i;
		}
		this->push_point = num - 1;
	}
	void push(T value) {
		push_point = (push_point + 1) % num;
		if (push_point == pop_point) {
			push_point--;
			return;
		}
		arr[push_point] = value;
	}
	T pop() {
		if (push_point == pop_point) {
			return -1;
		}
		pop_point = (pop_point + 1) % num;
		return arr[pop_point];
	}
	int size() {
		return (num - (pop_point - push_point)) % num;
	}
	int empty() {
		if (push_point == pop_point) {
			return 1;
		}
		return 0;
	}
	int front() {
		if (push_point == pop_point) {
			return -1;
		}
		return arr[(pop_point + 1) % num];
	}
	int back() {
		if (push_point == pop_point) {
			return -1;
		}
		return arr[push_point];
	}
};

int main(void)
{
	int i = 0, j, num, count, temp = 1;
	string str;
	stringstream result;

	cin >> num >> count;

	int* arr = new int[num];
	queue<int>* que = new queue<int>(num);

	for (; i < num; i++) {
		for (j = 1; j < count; j++) {
			que->push(que->pop());
		}
		arr[i] = que->pop();
	}
	cout << '<';
	for (i = 0; i < num-1; i++) {
		cout << arr[i] << ", ";
	}
	cout << arr[num-1] << '>' << endl;
	return 0;
}