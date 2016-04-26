//
//  main.c
//  reverse_linkedlist_recursion
//
//  Created by Neeraj Kumbhar on 3/9/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

//static void reverse(struct node** head_ref)
//{
//    struct node* prev   = NULL;
//    struct node* current = *head_ref;
//    struct node* next;
//    while (current != NULL)
//    {
//        next  = current->next;
//        current->next = prev;
//        prev = current;
//        current = next;
//    }
//    *head_ref = prev;
//}


void recursiveReverse(struct node** head_ref)
{
    struct node* first;
    struct node* rest;
    
    /* empty list */
    if (*head_ref == NULL)
        return;
    
    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;
    rest  = first->next;
    
    /* List has only one node */
    if (rest == NULL)
        return;
    
    /* reverse the rest list and put the first element at the end */
    recursiveReverse(&rest);
    first->next->next  = first;
    
    /* tricky step -- see the diagram */
    first->next  = NULL;
    
    /* fix the head pointer */
    *head_ref = rest;
}

void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}


int main()
{
    struct node* head = NULL;
    
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 85);
    
    printList(head);
//    reverse(&head);
    recursiveReverse(&head); // always pass by reference and not by value!
    printf("\n Reversed Linked list \n");
    printList(head);
    getchar();
}