/*
AUTHOR: avijay@usc.edu
Time complexity of the algorithm is O(n)
*/

#include <stdio.h>
#include <stdlib.h>

/*structure of a tree node*/
typedef struct node{
	struct node *left;
	struct node *right;
	int val;
}TreeNode;

/*method to create new tree node*/
TreeNode *newTreeNode(int value){
	TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
	root->left = NULL;
	root->right = NULL;
	root->val = value;
}

/*method to generate the tree using an input array with tree contents*/
TreeNode *generateTree(int array[], int low, int high){
	if(low > high) return NULL;

	int mid = low + (high-low)/2;

	TreeNode *parent = newTreeNode(array[mid]);
	TreeNode *left = generateTree(array,low,mid-1);
	TreeNode *right = generateTree(array,mid+1,high);
	parent->left = left;
	parent->right = right;
	return parent;
}

/*method to print tree in order*/
void printTree(TreeNode *root){
	if(root->left != NULL) printTree(root->left);
	printf("%d\n",root->val);
	if(root->right != NULL) printTree(root->right);
}

/*method to print tree pre order*/
void printPreTree(TreeNode *root){
	printf("%d\n",root->val);
	if(root->left != NULL) printPreTree(root->left);
	if(root->right != NULL) printPreTree(root->right);
}

/*method to print tree post order*/
void printPostTree(TreeNode *root){
        if(root->left != NULL) printPostTree(root->left);
        if(root->right != NULL) printPostTree(root->right);
        printf("%d\n",root->val);
}

/*method to get max out of two elements (int)*/
int getMax (int a, int b){
	return (a>b)?a:b;
}

/*method to get max path sum in a tree*/
void maxPathVal(TreeNode *root, int curr, int *a){
	if(root == NULL){
		return;
	}
	curr = curr + root->val;
	if(root->left == NULL && root->right == NULL){
		*a = getMax(*a,curr);
		curr = 0;
	}
	maxPathVal(root->left, curr, a);
	maxPathVal(root->right, curr, a);
}

/*driver program*/
int main(){
	int array[7] = {100,-10,1,1,20,10,15};

	TreeNode *root = generateTree(array,0,6);
	printf("Tree's in order traversal:\n");
	printTree(root);
	printf("Tree's pre order traversal:\n");
	printPreTree(root);
	printf("Tree's post order traversal:\n");
	printPostTree(root);
	int res = 0;
	int *a = &res;
	int curr = 0;
	maxPathVal(root,curr, a);
	printf("The maximum path value is: %d\n",*a);
	return 0;
}
