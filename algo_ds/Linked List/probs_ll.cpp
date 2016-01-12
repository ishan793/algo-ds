#include <iostream>
using namespace std;

struct node{
	int key;
	struct node* next;
};
// helper functions
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
void sorted_insert(node **headref, int val){
	node* cur = *headref;
	node* prev = cur;
	
	node* new_node = new node;
	new_node->key = val;
	new_node->next = NULL;
	
	if (cur == NULL){	
		*headref = new_node;
		return;
	}
	while(cur != NULL && cur->key < val){
		prev = cur;
		cur = cur->next;
	}
	if (cur == prev){
		// when the element is first
		new_node->next = *headref;
		*headref = new_node;
	}
	else {
		new_node->next = cur;
		prev->next = new_node;
	}
}

void sorted_insert_test(node* list){
	cout << "Original List" << endl;
	list_print(list);
	cout << "test for inserting smallest element in a populated list" << endl;
	sorted_insert(&list,0);
	list_print(list);
	cout << "test for inserting largest element in a populated list" << endl;
	sorted_insert(&list,10);
	list_print(list);
	cout << "test for inserting element in a populated list" << endl;
	sorted_insert(&list,5);
	list_print(list);
	cout << "Empty list test" << endl;
	node* new_list = NULL;
	sorted_insert(&new_list,3);
	list_print(new_list);
}

node* reverse(node **headref){
	node* temp = NULL;
	node* cur = *headref;
	node* prev = NULL;

	while(cur != NULL){
		temp = cur->next;
		cur->next = prev;
		// modify pts
		prev = cur;
		cur = temp;
	}
	cur = *headref;
	*headref = prev;
	return cur;
}

node* k_reverse(node* head, int k){
	node* temp = head;
	node* next_k;
	int count = 0;
	// list_print(head);
	while(count<k-1){
		cout << "Starting iteration" << endl;
		if (temp == NULL) {
			cout << "returning" << endl;
			return head;
		}
		cout << "next please " << temp->key << endl;
		if (temp->next == NULL) temp = temp->next;//cout << "Error detected" << endl;
		// temp = temp->next;
		count++;
	}
	next_k = temp->next;
	temp->next = NULL;
	temp = reverse(&head);
	// list_print(temp);
	// list_print(head);
	// list_print(next_k);
	next_k = temp->next = k_reverse(next_k,k);
	// list_print(next_k);
	return head;
}
void revers_test(node* list){
	list_print(list);
	node* last = reverse(&list);
	list_print(list);
	node* new_node = new node;
	new_node->key = 10;
	new_node->next = NULL;
	last->next = new_node;
	list_print(list);
}

void k_reverse_test(node* list){
	list_print(list);
	list = k_reverse(list,2);
	list_print(list);
}
int main(){
	node* list ;
	node* empty_list;
	list = NULL;
	empty_list = NULL;
	int i = 0;

	for(i=0;i<1;i++){
		push(&list, 8-2*i);
	}
	// sorted_insert_test(list);
	// revers_test(list);
	k_reverse_test(list);

}