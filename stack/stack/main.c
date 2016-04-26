//
//  main.c
//  stack
//
//  Created by Neeraj Kumbhar on 2/17/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct stack
{
    int top;
    int size;
    char *array;
};

struct stack *createStack(int size)
{
    struct stack *S = malloc(sizeof(struct stack));
    
    S->top = -1;
    S->size = size;
    S->array= malloc(S->size * sizeof(char));
    
    
    return S;
}

int isEmpty(struct stack *S)
{
    if(S->top == -1)
        return 1; // empty
    else
        return 0;
    
}

int isFull(struct stack *S)
{
    if(S->top == S->size -1)
        return 1;  // full
    else
        return 0;
    
}

void push(struct stack *S, char data)
{
    if(isFull(S))
        printf("\nStack full");
    else
    {
        ++S->top;
        S->array[S->top] = data;
    }
}

char pop(struct stack *S)
{
    char a;
    if(isEmpty(S))
    {
        printf("\nStack emppy");
        return -1;
    }
    else
    {
        a = S->array[S->top];
        S->top--;
        return a;
    }
}



int main(int argc, const char * argv[]) {
    
    char array[9]={'3', '1', '+', '4', '1', '+', '+', '1', '*'};
    printf("Size of array: %d", sizeof(array));

    struct stack *S = createStack(sizeof(array));
 
    for(int i=0; i< 7; i++)
    {
        if(isdigit(array[i]))
        {
                printf("\n %c", array[i]);
                push(S, array[i]);
        }
        else
        {
            int a = pop(S) - '0';
            printf("\n A = %d", a);
            
            int b = pop(S) - '0';
            printf("\n B = %d", b);
            int result = 0;
        
            switch (array[i])
            {
            case '+':
                result = a + b;
                    
                break;
            case '-':
                result = b - a;
                break;
            case '/':
                result = a / b;
                break;
                
            case '*':
                result = a * b;
                break;
                
            default:
                break;
            }
            
            push(S,(result) + '0');
            printf("Result = %d ", result);

        }
    }
    
    printf("\n Result = %c ", pop(S));
    return 0;
}
