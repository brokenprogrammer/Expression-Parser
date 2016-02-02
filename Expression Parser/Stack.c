//
//  Stack.c
//  Expression Parser
//
//  Created by Oskar Mendel on 2/2/16.
//  Copyright © 2016 Oskar Mendel. All rights reserved.
//

#include "Stack.h"
#include "stdlib.h"

Stack* Init(int val) {
    Stack *newStack = (Stack *) malloc(sizeof(Stack));
    
    if(newStack == NULL) {
        return NULL;
    }
    
    newStack->data = val;
    newStack->next = NULL;
    
    return newStack;
}

void push(Stack **head, int val) {
    Stack *newStack = (Stack *) malloc(sizeof(Stack));
    
    newStack->data = val;
    newStack->next = *head;
    *head = newStack;
}

int pop(Stack **head){
    Stack *newStack = NULL;
    
    if (*head == NULL) {
        return -1;
    }
    
    newStack = (*head)->next;
    int retval = (*head)->data;
    free(*head);
    *head = newStack;
    
    return retval;
}

int peek(Stack **head) {
    if (!isEmpty(*head)) {
        return (*head)->data;
    }
    return -1;
}

int isEmpty(Stack *head) {
    
    if (head == NULL) {
        return 1;
    }
    
    return 0;
}

void Display(Stack *head) {
    Stack *current = head;
    
    while (current != NULL) {
        printf("Stack Data: %i\n", current->data);
        current = current->next;
    }
}