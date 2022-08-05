#include<iostream>
#include"Queue.h"
using namespace std;

int main() {
	Queue<int> q;
	q.enqueue(4);
	q.enqueue(9);
	q.enqueue(5);
	q.dequeue();
	q.Display();
	cout << endl;
	q + 10;
	-q;
	q.Display();
}