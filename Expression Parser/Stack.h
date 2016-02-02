//
//  Stack.h
//  Expression Parser
//
//  Created by Oskar Mendel on 2/2/16.
//  Copyright © 2016 Oskar Mendel. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>

typedef struct Stack {
    int data;
    struct Stack *next;
}Stack;

//Stack *head = NULL;
//Stack *tail = NULL;

Stack* Init(int val);

void Display(Stack *head);
void push(Stack **head, int val);
int pop(Stack **head);
int isEmpty(Stack *head);

#endif /* Stack_h */
