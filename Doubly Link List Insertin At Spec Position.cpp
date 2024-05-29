#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
	node* prev;

	node(int d)
	{
		data = d;
		next = NULL;
		prev = NULL;
	}

	void inserattail(node*& tail, int d)
	{
		node* temp = new node(d);

		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}

	void insertatHead(node*& head, int d)
	{
		node* temp = new node(d);
		temp->next = head;
		head->prev = temp;
		head = temp;
	}

	void insertatspecificpos(node*& head, node*& tail, int d,int p)
	{
	
		int count = 1;

		if (p == 0)
		{
			insertatHead(head, d);
			return;
		}

		node* temp = head;
		while (count < p - 1)
		{
			temp = temp->next;
			count++;
		}

		node* nodetoinsert = new node(d);
		nodetoinsert->next = temp->next;
		temp->next->prev = nodetoinsert;
		temp->next = nodetoinsert;
		nodetoinsert->prev = temp;

		if (temp->next == NULL)
		{
			inserattail(tail, d);
			return;
		}
	}

	void display(node*& head)
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "NULL";
	}
};

void main()
{
	node* tail = NULL;
	node* node1 = new node(1);
	node* node2 = new node(2);
	node* node3 = new node(4);

	node* head = node1;
	node1->next = node2;
	node2->next = node3;

	head->insertatspecificpos(head, tail, 3, 3);
	head->display(head);
	cout << endl;
	
}