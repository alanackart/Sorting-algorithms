#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#define MAXN 1000000
int arr[MAXN];

using namespace std;
typedef struct node
{
    int data;
    struct node* right;
    struct node* left;
} node;


void insert(node** tree, int val)
{
    node *temp = NULL;
    if(!(*tree)) // node is empty
    {
        temp = (node*)malloc(sizeof(node)); // allocate the space of a node
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

void construct(node **tree, int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        insert(&(*tree), arr[i]);
    }
}
void print_inorder(node * tree)
{
    if (tree)
    {
        printf("%c",tree->data);
        print_inorder(tree->left);
        print_inorder(tree->right);
    }
}


void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}
