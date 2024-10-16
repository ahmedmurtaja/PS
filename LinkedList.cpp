#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node* next;
};

void insertNode(Node*& head, int data)
{
	if (head == nullptr) {
		head = new Node;
		head->data = data;
		head->next = nullptr;
	} else {
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		temp->next = newNode;
	}
	cout << "Inserting New Node with Value " << data << endl;
}

bool containsCycle(Node* head)
{
	Node* temp = head;
	unordered_map<Node*, bool> visited;
	while(temp->next != nullptr)
	{
		if(visited.count(temp) != 0)
		{
			return true;
		}
		visited[temp] = true;
		temp = temp->next;
	}

    return false;
}

void printList(Node* head) {
	Node* current = head;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

int main() {
	Node* head = nullptr;
	insertNode(head, 1);
	insertNode(head, 2);
	insertNode(head, 3);
	insertNode(head, 4);
	printList(head);

	Node* cycle = new Node;
	cycle->data = 1;

	Node* secN = new Node;
	secN->data = 2;

	cycle->next = secN;

	Node* third = new Node;
	third->data = 5;

	secN->next = third;
	third->next = cycle;

//	printList(cycle); // OO LOOP
	cout << containsCycle(head) << "HEAD" << endl;
	cout << containsCycle(cycle) << "cycle" << endl;


	return 0;
}