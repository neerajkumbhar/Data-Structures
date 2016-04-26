//
//  main.c
//  stack_implementation
//
//  Created by Neeraj Kumbhar on 3/31/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

struct stack{
    
    int top;
    unsigned capacity;
    int *array;
};

struct stack *createStack(int capacity)
{
    struct stack *stack = (struct stack*)malloc(sizeof(struct stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(sizeof(int)* stack->capacity);
    return stack;
}

int isFull(struct stack *stack)
{
    return (stack->top == stack->capacity -1);
}

int isEmpty(struct stack *stack)
{
    return (stack->top == -1);
}

void push(struct stack *stack, int item)
{
    if(isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("\vValue pushed = %d", item);
}

int pop(struct stack *stack)
{
    if(isEmpty(stack))
        return 0;
    int value = stack->array[stack->top--];
    return  value;
}



int main(int argc, const char * argv[]) {
   
    struct stack *stack = createStack(10);
    
        push(stack, 10);
        push(stack, 20);
        push(stack, 30);
        push(stack, 40);
    
    int value = pop(stack);
    printf("\n!!!Value popped = %d", value);
    pop(stack);
    printf("\n!!!Value popped again = %d",pop(stack));
    return 0;
}
