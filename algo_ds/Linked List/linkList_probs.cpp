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
// count function: counts the number of times
// val occurs
int count(node* head, int val){
	int res = 0;
	// node* cur = head;

	while (head != NULL){
		// cout << head->key;
		if (head->key == val) res++;
		head = head->next;
	}
	return res;
}
// function to get value at nth position
// returns -1 if the list is empty or n is greater than list size 
int getn(node *head, int n){
	node* cur = head;
	int count = 0;

	while(cur != NULL){
		if (count == n) return cur->key;
		else {
			count++;
			cur = cur->next;
		} 
	}
	return -1;
}

void delete_list(node** headref){
	node* temp;
	node* cur = *headref;

	while(cur != NULL){
		temp = cur;
		cur = cur->next;
		delete temp;
	}
	*headref = NULL;
}

int pop(node** headref){
	node* res_node = *headref;
	if (res_node == NULL)	return -1;
	*headref = res_node->next;
	int ans = res_node->key;
	delete res_node;
	return ans;
}

void insert_n(node** headref, int n, int val){
	node* cur = *headref;
	node* new_node = new node;
	int count = 0;

	new_node->key = val;
	new_node->next = NULL;

	if (count == n){
		// case for the case when n = 0
		new_node->next = *headref;
		*headref = new_node;
	}
	else{
		while(cur != NULL && count < n-1){
			count ++;
			cur = cur->next;
		}
		// 
		if (cur == NULL){return;}
		else{
			new_node->next = cur->next;
			cur->next = new_node;
		}
	}
}


int main(){
	node* list ;
	node* empty_list;
	list = NULL;
	empty_list = NULL;
	int i = 0;

	for(i=0;i<5;i++){
		push(&list, i);
	}
	// push(&list,2);
	list_print(list);
	// ---- testing for get n
	// cout << getn(list, 10) << endl;
	// cout << getn(empty_list,3) << endl;
	// delete_list(&list);
	// ---- ending test
	// ----* test for pop -----
	// for(i=0;i<5;i++){
	// 	// cout << pop(&list) << endl;
	// 	pop(&list);
	// 	list_print(list);
	// }
	// int a = pop(&list);
	// if (a==-1) cout << "Right" <<endl;
	// ending test
	// testing for insert_n
	for (i=0;i<3;i++){
		insert_n(&list,i,5*i);
		list_print(list);
	}
	insert_n(&list,8,20);
	list_print(list);
	insert_n(&list,10,20);
	list_print(list);
}
