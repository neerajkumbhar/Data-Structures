//
//  main.c
//  queue_arrayImplementation
//
//  Created by Neeraj Kumbhar on 2/28/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

struct ArrayQueue{
    
    int rear, front;
    int capacity;
    int *array;
    
};

struct ArrayQueue *createQueue(int size)
{
    struct ArrayQueue *Q = malloc(sizeof(struct ArrayQueue));
    
    if(!Q)
        return NULL;
    
    Q->capacity = size;
    Q->rear = Q->front = -1;
    Q->array = malloc(sizeof(int)*Q->capacity);
    
    return Q;
    
}


int IsEmptyQueue(struct ArrayQueue *Q)
{
    if(Q->front == -1)
        return 1;
    else
        return 0;
}


int IsFullQueue(struct ArrayQueue *Q)
{
    if((Q->rear+1) % Q->capacity == Q->front)
        return 1;
    else
        return 0;
    
}

int QueueSize(struct ArrayQueue *Q)
{
    return (Q->capacity - Q->front + Q->rear +1 ) % Q->capacity;
}



void enqueue(struct ArrayQueue *Q, int data)
{
    
    if(IsFullQueue(Q))
    {
        printf("Queue is full");
    }
    else
    {
        Q->rear = (Q->rear +1) % Q->capacity;
        Q->rear = data;
        printf("\nAdded to the Queue: %d ", data);
    }
}

int dequeue(struct ArrayQueue *Q)
{
    int data = 0;
    
    if(IsEmptyQueue(Q))
    {
        printf("\nQueue is empty");
        return 0;
    }
    else
    {
        data = Q->array[Q->front];
        Q->front = (Q->front +1) % Q->capacity;
    }
    
    return data;
    
}



int main(int argc, const char * argv[]) {
    
    
    int array[7] = {1,2,3,4,5,6,7};
    
    struct ArrayQueue *Q = createQueue(7);
    
    enqueue(Q,array[0]);
    enqueue(Q,array[1]);
    enqueue(Q,array[2]);
    enqueue(Q,array[3]);
    
    
    int data = dequeue(Q);
    printf("Value dequed from the queue is: %d", data);
    
    enqueue(Q,array[6]);
    
   // printQueue(Q,array);
    
    
    return 0;
}
