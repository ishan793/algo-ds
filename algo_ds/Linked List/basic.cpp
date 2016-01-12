#include <iostream>
using namespace std;

struct node{
	int key;
	node* next; 
};
void list_print(node* head){
	node* cur = head;
	
	while(cur != NULL){
		cout << cur->key;
		if (cur->next != NULL){
			cout << "->";
		}
		cur = cur->next;
	}
	cout <<endl;
}

void push(node** headref, int k){
	node* new_node = new node;
	
	new_node->key = k;
	new_node->next = *headref;
	*headref = new_node;
}

int len(node* head){
	int len = 0;
	node *cur = head;
	while(cur != NULL){
		len += 1;
		cur = cur->next;
	}
	return len;
}

void sortedInsert(node** headref, int val){
	
}
int main(){
	node* list = new node;
	list = NULL;
	int i = 0;

	for(i=0;i<5;i++){
		push(&list, i);
		cout << "Length is " << len(list) << endl;
		list_print(list);
	}
}

