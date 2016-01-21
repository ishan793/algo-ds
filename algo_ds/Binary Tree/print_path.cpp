#include <iostream>
#include <vector>
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

void print_path_helper(node* current, vector<int> path_till_now, vector< vector<int> >& res){
	if (current == NULL){
		res.push_back(path_till_now);
	}
	else{
		vector<int> next = path_till_now;
		next.push_back(current->val);
		if (current->left == NULL)
			print_path_helper(current->right,next,res);
		else if (current->right == NULL)
			print_path_helper(current->left,next,res);
		else{
			print_path_helper(current->right,next,res);
			print_path_helper(current->left,next,res);
		}
	}
}

void print_vector(vector<int> vec){
	int n = vec.size();
	int i = 0;
	for(i = 0; i < n; i++){
		if (i != n-1){
			cout << vec[i] << "-";
		}
		else{
			cout << vec[i] << endl;
		}
	}
}

void print_path(node* head){
	vector< vector<int> > res;
	vector<int> base;
	print_path_helper(head, base, res);
	int num_paths = res.size();

	for (int i = 0; i < num_paths; ++i)
	{
		print_vector(res[i]);
	}
}

void print_path_test(node* a, node* b, node* c,node* d){
	cout << "Normal tree" << endl;
	print_path(a) ;
	cout << "Empty tree" << endl;
	print_path(b); 
	cout << "Linear tree" << endl;
	print_path(c); 
	cout << "Nearly Random" << endl;
	print_path(d);
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
	print_path_test(a,b,c,d);
	
}