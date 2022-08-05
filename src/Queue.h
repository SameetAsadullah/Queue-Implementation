#pragma once
#include<iostream>
using namespace std;

template<class DT>
class Node {
public:
	DT data;
	Node<DT>* next;

	Node() :data(0), next(NULL) {
	}
};

template<class DT>
class Queue {
	Node<DT>* front;
	Node<DT>* rear;
	int size;

public:
	Queue() :front(NULL), rear(NULL), size(0) {
	}

	int getLength()const {
		return size;
	}

	Node<DT>* getFront() {
		return front;
	}

	Node<DT>* getRear() {
		return rear;
	}

	void enqueue(const DT& newDataItem) {
		Node<DT>* temp = new Node<DT>;
		temp->data = newDataItem;

		if (front == NULL) {
			front = temp;
			rear = temp;
		}

		else {
			rear->next = temp;
			rear = temp;
		}
		size++;
	}

	DT dequeue() {
		if (front != NULL) {
			Node<DT>* temp1 = front;
			DT data = front->data;
			front = front->next;
			delete temp1;
			size--;
			return data;
		}

		if (front == NULL) {
			rear = NULL;
		}
	}

	void clear() {
		int s = size;
		for (int i = 0; i < s; i++) {
			dequeue();
		}
	}

	bool isEmpty() {
		if (front == NULL) {
			return true;
		}
		return false;
	}

	void Display() {
		Node<DT>* temp = front;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void operator+(const DT& newDataItem) {
		enqueue(newDataItem);
	}

	DT operator-() {
		DT data;
		data = dequeue();
		return data;
	}
};