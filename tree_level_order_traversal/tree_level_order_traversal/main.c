//
//  main.c
//  tree_level_order_traversal
//
//  Created by Neeraj Kumbhar on 4/9/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

struct node{

    int data;
    struct node *left;
    struct node *right;
    
};

struct node * newNode(int data)
{
    struct node *node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left=NULL;
    node->right=NULL;
    
    return node;
}

void enqueue(


int main(int argc, const char * argv[]) {

    return 0;
}
