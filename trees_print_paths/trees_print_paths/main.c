//
//  main.c
//  trees_print_paths
//
//  Created by Neeraj Kumbhar on 4/10/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};


struct node *Newnode(int data)
{
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right= NULL;
    
    return newnode;
}

void printPreTree(struct node *root)
{
    if(root)
    {
        printf(" %d ", root->data);
        printPreTree(root->left);
        printPreTree(root->right);
    }
    
}


void PrintpathsRecursive(struct node *root, int paths[], int pathlen)
{
    if(root == NULL)
        return;
    
    paths[pathlen] = root->data;
    pathlen++;
    
    
    
    if(root->left == NULL && root->right == NULL)
    {
        printf("\n");
        int pathvalue = 0;
        for(int i=0; i<pathlen; i++)
        {
            pathvalue = pathvalue + paths[i];
            printf(" %d ", paths[i]);
        }
        printf("\nPath Value = %d", pathvalue);
        printf("\n");
    }
    else
    {
        PrintpathsRecursive(root->left, paths, pathlen);
        PrintpathsRecursive(root->right, paths, pathlen);
    }
        
}

void printPaths(struct node *root)
{
    int paths[100];
    PrintpathsRecursive(root, paths, 0);
}

bool printAncestors(struct node *root, int target)
{
    
    if(root == NULL)
        return false;
    
    if(root->data == target)
        return  true;
    
    if(printAncestors(root->left, target) || printAncestors(root->right, target))
    {
        printf(" %d ", root->data);
        return  true;
    }
    
    return false;
}



int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
        
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}


int main(int argc, const char * argv[]) {
    
    struct node *root = Newnode(1);
    root->left = Newnode(2);
    root->right = Newnode(3);
    root->left->left= Newnode(4);
    root->left->left->left= Newnode(6);
    root->left->right = Newnode(5);
    
    printPreTree(root);
    
    printPaths(root);
    
    printf("\nHeight of tree is %d ", height(root));
    
    printf("\nAncestors of 6 are ");
    printAncestors(root, 6);
    
    return 0;
}
