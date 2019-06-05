#include "sample.h"
#include<iostream>
#include<assert.h>
#include<vector>
#include<stdlib.h>
#include<string>
#include <algorithm>
#include <ctime>
#include<set>
#include<map>
#include<queue>

using namespace std;
void greeting() {
	cout<<"\n here we persist...\n";
}

typedef pair<int, int> mypair;

class ntree{
public: 
	int val;
	ntree *left;
	ntree *right;
	ntree(int v) {
		val = v;
		left = NULL;
		right = NULL;

	}


};

ntree * construct_bst(vi arr, int low, int high) {
	if(low > high)
		return NULL;

	int mid = low + (high -low)/2;

	ntree *temp = new ntree(arr[mid]);

	if(low == high)
		return temp;

	temp->left = construct_bst(arr, low, mid-1);
	temp->right = construct_bst(arr, mid+1, high);

	return temp;
}

/* percolate up using return values */
int binary_tree_ht(ntree *t) {
	if( t == NULL)
		return -1;

	int left_ht = binary_tree_ht(t->left);
	int right_ht = binary_tree_ht(t->right);

	return max(left_ht, right_ht) +1;
}

/* percolate up using intermediate pointers */
void btree_ht(ntree *t, int * ht) {
	if( t == NULL) {
		(*ht) = -1;
		return;
	}

	int left=0;
	btree_ht(t->left, &left);
	int right =0;
	btree_ht(t->right, &right);

	(*ht) = max( left, right) +1;
}
