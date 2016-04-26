
//
//  main.c
//  queue_array
//
//  Created by Neeraj Kumbhar on 4/1/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.


#include <stdio.h>
#include <limits.h>

struct Queue {
    
    int size, front, rear;
    unsigned capacity;
    int *arr;
};

struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = queue->capacity - 1;
    queue->arr = (int *) malloc(sizeof(int) * queue->capacity);
    return queue;
}

int isFull(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue *queue, int item)
{
    
        if(isFull(queue))
            return;
    
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size = queue->size + 1;
    
    printf("\nItem enqueued is %d ", item);
    
}

int dequeue(struct Queue *queue)
{
    int item;
    if(isEmpty(queue))
        return  INT_MIN;
    
    item = queue->arr[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return  item;
}



int main(int argc, const char * argv[]) {
    
    
    struct Queue *Q = createQueue(20);
    
    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    enqueue(Q, 40);
    
    printf("\n!!! Item Dequeued = %d", dequeue(Q));
    printf("\n!!! Item Dequeued = %d", dequeue(Q));

    enqueue(Q, 50);
    printf("\n!!! Item Dequeued = %d", dequeue(Q));
    
    printf("\n");
    return 0;
}
