//
//  main.c
//  BST using recursion
//
//  Created by Neeraj Kumbhar on 2/16/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


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
            printf("LEFT = %d ", (*head)->left->data);
        else
            printf("left = Null");
        
        if((*head)->right!= NULL)
            printf("RIGHT = %d ", (*head)->right->data);
        else
            printf("right = Null");
        
    }
    else
    {
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


void printInOrder(struct node *head)
{
    if(head)
    {
        printInOrder(head->left);
        printf(" %d ", (head)->data);
        printInOrder(head->right);
    }
}



//void printpreorderNonRecursive(struct node *root)
//{
//    struct Stack *S = CreateStack();
//    
//    while(1)
//    {
//        while (root)
//        {
//            printf("%d", root->data);
//            Push(S, root);
//            root = root->left;
//        }
//        
//        if(IsEmptyStack(S))
//            break;
//        root = Pop(S);
//        root=root->right;
//        
//    }
//}



int main(int argc, const char * argv[]) {
    
    
    int arr[8] = {5,2,8,1,6,9,3,4};
    struct node *root;
    
    for(int i=0; i< 8; i++)
    {
        struct node *new= (struct node*)malloc(sizeof(struct node));
        new->left=NULL;
        new->right=NULL;
        new->data=arr[i];
        createTree(&root, new);
    }
    
    int p;
    printf("\nEnter a node");
    scanf("%d", &p);
    
    struct node *new= (struct node*)malloc(sizeof(struct node));
    new->left=NULL;
    new->right=NULL;
    new->data=p;
   // printTree(&root, new);
    
    printf("\nPre order traversal is:\n");
    printPreOrder(root);
    
    printf("\In order traversal is:\n");
    printInOrder(root);
    
   // printf("\nPre Order traversal (Non recursive) is:\n");
   // printpreorderNonRecursive(root);
    
    
   // findDepth(root);
    
    
    
    
    return 0;
}
