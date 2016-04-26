//
//  main.c
//  LinkedListCreate
//
//  Created by Neeraj Kumbhar on 2/9/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    
    int data;
    struct node *next;
};

/* adding node at the front
void push(struct node **head_ref, int new_data)
{
    
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
*/


// adding node in the end
void push(struct node **head_ref, int data)
{
    
    struct node *new_node  = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    
    struct node *last = *head_ref;
    
    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    
    
    while(last->next != NULL)
        last = last->next;
    
    
    last->next = new_node;
    return;
}


void deleteNode(struct node **head_ref, int key)
{
    
    struct node *temp = *head_ref, *prev;

    // if the head itself has the key make the head point to the temp->next and delete the temp
    if(temp!=NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp!=NULL && temp->data != key) {
        prev=temp;
        temp = temp->next;
    }
    
    if(temp == NULL)
        return;
    
    prev->next = temp->next;
    free(temp);
    
}

void deleteList(struct node **head){
    
    struct node *p, *q;
    q = *head;
    
    
    while(q)
    {
        p = q->next;
        free(q);
        q = p;
    }
    
    *head = NULL;
    
}

void printList(struct node *node)
{
    while(node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int IsLinkedListOrorEven(struct node *head){
    
    while(head && head->next)
        head = head->next->next;
    
    if(!head)
        return 0; // even
    return 1;
}

void printListfromend(struct node *head)
{
    
    if(!head)
        return;
    printListfromend(head->next);
    printf(" %d ", head->data);

}


bool search(struct node* head, int x)
{
    if (head == NULL)
        return false;
    
    if (head->data == x)
        return true;
    
    return search(head->next, x);
}


//sorted list
void removeduplicates(struct node* head)
{
    struct node* current  = head;
    struct node* temp;
    
    while(current->next != NULL)
    {
        if(current->data == current->next->data)
        {
            temp = current->next->next;
            free(current->next);
            current->next = temp;
        }
        else
        {
            current = current->next;
        }
    }
}



void Reverse(struct node **head_ref)
{
    struct node *first;
    struct node *last;
    
    first = *head_ref;
    last = first->next;
    
    if(last == NULL)
        return;
    
    Reverse(&last);
    first->next->next = first;
    
    first->next = NULL;
    
    *head_ref = last;
    
}


int main(int argc, const char * argv[]) {
    
    struct node *head = NULL;
    
    printf("Creating:");
    push(&head, 1);
    push(&head, 3);
    push(&head, 6);
    push(&head, 13);
    push(&head, 13);
    push(&head, 32);

    
    printf("\nPrinting:");
    printList(head);
   
    printf("\nPrinitng from the end..");
    printListfromend(head);
    
    search(head, 3)? printf("\nYes element found") : printf("\nNo element not found");
    
    int x;
    x = IsLinkedListOrorEven(head);
    
    if(x==1)
        printf("\nODD");
    else
        printf("\nEVEN");
    printf("\n");

    removeduplicates(head);
    printf("\nPrinting after removing duplicates(sorted list):");
    printList(head);
    
    
    Reverse(&head);
    printf("\nLinkedlist reverse using recursion");
    printList(head);
    
    
    
    printf("\n");
    printf("\nAfter delete..");
    deleteNode(&head,3);
    printList(head);
    
//   deleteList(&head);
//   printf("\nAfter delete..");
//   printList(head);
     return 0;
}
