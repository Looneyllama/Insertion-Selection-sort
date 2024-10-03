#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};


void printList(Node* head){
	cout << "[ ";
	while(head){
		cout << head->data << ", ";
		head = head->next;
	}
	cout << "]" << endl;
}

void insert(Node** head, int value){
	Node* new_node = new Node();
	new_node->data = value;
	new_node->next = (*head);
	(*head) = new_node;
}

void inserstionSort(Node** head){
	Node* sorted = NULL;
	Node* current = *head;
	while(current != NULL){
		Node* next_node = current -> next;
		if(sorted == NULL || sorted -> data >= current-> data){
			current-> next = sorted;
			sorted = current;
		}
		else{
			Node* temp = sorted;
			while(temp -> next != NULL && temp->next->data < current->data){
				temp = temp->next;
			}
			current->next = temp->next;
			temp->next = current;
		}
		current = next_node;
	}
	*head = sorted;
}
Node* selectionSort(Node *head){
	Node *a,*b,*c,*d,*r;
	a = b = head;
	while(b->next){
		c = d = b->next;
		while(d){
			if(b->data > d->data){
				if(b->next == d){
					if(b == head){
						b->next = d->next;
						d->next = b;

						r=b;
						b=d;
						d=r;

						c=d;

						head = b;

						d = d-> next;
					}
					else{

						b->next = d->next;
						d->next = b;
						a->next = d;

						r=b;
						b=d;
						d=r;

						c=d;

						d = d-> next;

					}
				}
				else{
					if(b == head){
						r = b->next;
						b->next = d->next;
						d->next = r;
						c->next = b;

						r=b;
						b=d;
						d=r;
						c=d;

						d = d->next;
						head = b;
					}
					else{
						r = b->next;
						b->next = d->next;
						d->next = r;
						c->next = b;
						a->next = d;

						r=b;
						b=d;
						d=r;
						c=d;

						d = d->next;
					}
				}
			}
			else{
				c = d;
				d = d->next;
			}
		}
		a = b;
		b = b->next;
	}
	return head;

}

int main(){
	Node* head = NULL;
	int input, value;
	cout << "Enter the number of elements in the list : ";
	cin >> input;
	cout << endl;
	for(int x = 0; x < input; x++){
		cout << "Enter Value: ";
		cin >> value;
		insert(&head, value);
	}
	cout << "List before sorting " << endl;
	printList(head);

	//inserstionSort(&head);
	head = selectionSort(head);

	cout << "List after sorting " << endl;
	printList(head);

	return 0;

}