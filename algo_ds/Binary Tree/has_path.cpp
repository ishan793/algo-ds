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

int has_path(node* head, int sum){
	if (sum == 0 && head == NULL){
		return 1;
	}
	else if (head == NULL){
		return 0;
	}
	else{
		int next_val = sum - head->val;
		int left_val = has_path(head->left,next_val);
		int right_val = has_path(head->right,next_val);
		if (right_val == 1 || left_val == 1){
			return 1;
		}
	}
}

void max_depth_test(node* a, node* b, node* c,node* d){
	cout << "Normal tree" << endl;
	cout << has_path(a,9) << endl; 
	cout << "Normal tree" << endl;
	cout << has_path(a,30) << endl; 
	cout << "Empty tree" << endl;
	cout << has_path(b,2) << endl; 
	cout << "Linear tree" << endl;
	cout << has_path(c,40) << endl; 
	cout << "Linear tree" << endl;
	cout << has_path(c,-12) << endl; 
	cout << "Nearly Random" << endl;
	cout << has_path(d,40) << endl;
	cout << "Nearly Random" << endl;
	cout << has_path(d,50) << endl;
	cout << "Nearly Random" << endl;
	cout << has_path(d,152) << endl;
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
	for (i = 0; i < 5 ; i++){
		insert(c,10-i);
	}
	// print_test(a,b,c);
	node *d = NULL;
	for (i = 0; i < 5 ; i++){
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