#include <iostream>
using namespace std;

struct node{
	int val;
	node *left;
	node *right;
};

void insert(node*& head, int val){
	node* new_node = new node;
	new_node->val = val;
	new_node->right = NULL;
	new_node->left = NULL;

	if (head == NULL) head = new_node;
	else{
		node* parent;
		node* cur = head;
		while (cur != NULL){
			parent = cur;
			if (val >= cur->val){
				cur = cur->right;
			}	
			else {
				cur = cur->left;
			}
		}
		if (val >= parent->val) parent->right = new_node;
		else parent->left = new_node;
	}
}

void in_order_print(node* head){
	if (head == NULL) return;
	else{
		cout << head->val << "->";
		in_order_print(head->left);
		in_order_print(head->right);
	}
}

int size(node* head){
	if (head == NULL)
		return 0;
	else{
		int left_size = size(head->left);
		int right_size = size(head->right);
		return 1+left_size+right_size;
	}
}

void size_test(node* a, node* b, node* c){
	cout << "Normal tree" << endl;
	cout << size(a) << endl; 
	cout << "Empty tree" << endl;
	cout << size(b) << endl; 
	cout << "Linear tree" << endl;
	cout << size(c) << endl; 
}

void print_test(node* a, node* b, node* c){
	cout << "Normal tree" << endl;
	in_order_print(a);
	cout << endl; 
	cout << "Empty tree" << endl;
	in_order_print(b);
	cout << endl; 
	cout << "Linear tree" << endl;
	in_order_print(c);
	cout << endl; 
}


int main(){
	int arr[7] = {6,2,8,1,3,7,9};
	int i = 0;
	node* a = NULL;
	for (i = 0; i < 7; ++i){
		/* code */
		insert(a,arr[i]);
	}
	node* b = NULL;
	node* c = NULL;
	for (i = 0; i < 10 ; i++){
		insert(c,i);
	}
	// print_test(a,b,c);
	size_test(a,b,c);
}

