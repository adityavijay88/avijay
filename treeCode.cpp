#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <iostream>

using namespace std;

typedef struct Node{
    int val;
    struct Node *right;
    struct Node *left;
}node;

node *createNode(int value){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = value;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

node *LLtoTree(ListNode *head, int low, int high){
    if(low>high){return NULL;}
    int mid = low + (high-low)/2;
    node *left = LLtoTree(head, low,mid-1);
    node *parent = creatNode(head->val);
    head = head->next;
    node *right = LLtoTree(head, mid+1,high);
    parent->left = left;
    parent->right = right;
    return parent;
}
node *arrayToTree(int num[], int low, int high){
    if(low>high) return NULL;
    int mid = low + (high-low)/2;
    node *root = createNode(num[mid]);
    node *left = arrayToTree(num,low,mid-1);
    node *right = arrayToTree(num,mid+1,high);
    root->left = left;
    root->right = right;
    return root;
}
void inorder(node *root){
    if(root == NULL)return;
    if(root->left != NULL){
        inorder(root->left);
    }
    printf("%d\n",root->val);
    if(root->right != NULL){
        inorder(root->right);
    }
}
void DFS(node *root){
    if(root == NULL) return;
    printf("%d\n",root->val);
    if(root->left != NULL){
        DFS(root->left);
    }
    if(root->right != NULL){
        DFS(root->right);
    }
    
}


int main()
{
   int num[10] = {0,1,2,3,4,5,6,7,8,9};
   node *root = arrayToTree(num,0,9);
   printf("Inorder traversal is:\n");
   inorder(root);
   printf("DFS is:\n");
   DFS(root);
   return 0;
}
