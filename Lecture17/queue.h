#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(int d){
		data = d;
		next = NULL;
	}
};

class queue{
	node* head;
	node* tail;
public:
	queue(){
		head = tail = NULL;
	}

	void push(int d){
		if(head == NULL){
			head = tail = new node(d);
		}
		else{
			node* n = new node(d);
			tail->next = n;
			tail = n;
		}
	}

	void pop(){
		if(head == NULL){
			return;
		}
		else if(head->next == NULL){
			delete head;
			head = tail = NULL;
		}
		else{
			node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	int front(){
		return head->data;
	}

	bool empty(){
		return head == NULL;
	}
};