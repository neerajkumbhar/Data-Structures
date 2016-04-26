//
//  main.c
//  BST using recursion
//
//  Created by Neeraj Kumbhar on 2/16/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (a>b?a:b)
#define MAX 8


struct node
{
    int data;
    struct node *left;
    struct node *right;
    
};



void createTree(struct node ** head, struct node * new)
{
    
    if(!(*head))
    {
        *head = new;
        
        return;
    }
    else{
        if((*head)->data < new->data)
            createTree(&(*head)->right, new);
        else
            createTree(&(*head)->left, new);
    }
    
}


void printTree(struct node **head, struct node *new)
{
    
    if((*head)->data == new->data)
    {
        if((*head)->left!=NULL)
            printf("LEFT=%d", (*head)->left->data);
        else
            printf("left=null");
        
        if((*head)->right!=NULL)
            printf("RIGHT=%d", (*head)->right->data);
        else
            printf("right=null");
        
    }
    else{
        if((*head)->left!=NULL)
            printTree(&(*head)->left, new);
        if((*head)->right!=NULL)
            printTree(&(*head)->right, new);
    }
    
}



void printPreOrder(struct node *head)
{
    if(head)
    {
        printf(" %d ", (head)->data);
        printPreOrder(head->left);
        printPreOrder(head->right);
    }
}


int findDepth(struct node *root)
{
    int depthl = 0, depthr = 0;

        if(root == NULL)
            printf("\nDepth = 0");
    
        printf(" %d ", root->data);
    
        if(root->left)
        {
            printf("\nleft");
            depthl = 1 + findDepth(root->left);
        }
        else{
            printf("\nBack");
        
            depthl = 0;
        }
    
        if(root->right)
        {
            printf("\nright");
            depthr = 1 +  findDepth(root->right);
        }
        else{
            printf("\nBack");
        
            depthr = 0;
        }
        return max(depthl, depthr);
    
    
}




int main(int argc, const char * argv[]) {
    
 
    int arr[MAX] = {8,5,9,1,6,4,3,2};
    
    struct node *root;
    for(int i=0; i< MAX; i++)
    {
        struct node *new= (struct node*)malloc(sizeof(struct node));
        new->left=NULL;
        new->right=NULL;
        new->data=arr[i];
        createTree(&root, new);
    }

    int val = findDepth(root);
    
    printf("Depth = %d", val);
    

    
    
    
    
    
    
    return 0;
}
