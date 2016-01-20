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
int max_depth(node* head){
	if (head == NULL) return 0;
	else{
		int right_min = max_depth(head->right);
		int left_min = max_depth(head->left);
		if (right_min == 0 && left_min == 0){
			return 1;
		}
		else if (right_min == 0){
			return 1 + left_min;
		}
		else if (left_min == 0){
			return 1 + right_min;
		}
		else{
			// return 1+min(max_depth(head->right),max_depth(head->left));
			return 1+max(max_depth(head->right),max_depth(head->left));
		}
		
	}
}
void max_depth_test(node* a, node* b, node* c,node* d){
	cout << "Normal tree" << endl;
	cout << max_depth(a) << endl; 
	cout << "Empty tree" << endl;
	cout << max_depth(b) << endl; 
	cout << "Linear tree" << endl;
	cout << max_depth(c) << endl; 
	cout << "Nearly Random" << endl;
	cout << max_depth(d) << endl;
}

// node* rand_tree(){
// 	node* head = new node;
// 	head->val = 10;
// }
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
		insert(c,10-i);
	}
	// print_test(a,b,c);
	node *d = NULL;
	for (i = 0; i < 10 ; i++){
		insert(d,10-i);
	}
	insert(d,15);
	insert(d,13);
	insert(d,14);
	insert(d,12);
	insert(d,16);
	// insert(d,17);
	max_depth_test(a,b,c,d);
	
}

