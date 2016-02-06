/**
 * Expression-Parser.
 * An Expression parser written in C capable of parsing advanced
 * math expressions.
 *
 * The MIT License (MIT)
 *
 * Copyright (C) 2016 The Expression-Parser Project
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "Stack.h"
#include "stdlib.h"

union expressionContent {
    int expressionOperand;
    char expressionOperator;
};

typedef struct Stack {
    union expressionContent data;
    int size;
    int isOperator;
    struct Stack *next;
}Stack;

/**
 * initWithData initializes a new Stack by allocating a new pointer with
 * the ammount of memory a Stack needs. Then after checking if the newly
 * created stack is NULL or not its values are initialized by using the value
 * from the parameters and setting the next Stack it points to to NULL.
 * This initial Stack will serve as the bottom of the stack so it will never
 * point to another Stack with its next property.
 * This initializes a stack that only accepts integers.
 *
 * @param val - Value to place in the Stack structures data property.
 *
 * @returns pointer to the just initialized Stack structure(object).
 */
Stack* initWithOperand(int val) {
    Stack *newStack = (Stack *) malloc(sizeof(Stack));
    
    if(newStack == NULL) {
        return NULL;
    }
    
    newStack->data.expressionOperand = val;
    newStack->size = 1;
    newStack->isOperator = 0;
    newStack->next = NULL;
    
    return newStack;
}

/**
 * initWithOperator initializes a new Stack by allocating a new pointer with
 * the ammount of memory a Stack needs. Then after checking if the newly
 * created stack is NULL or not its values are initialized by using the value
 * from the parameters and setting the next Stack it points to to NULL.
 * This initial Stack will serve as the bottom of the stack so it will never
 * point to another Stack with its next property.
 * This initializes a stack that only accepts chars.
 *
 * @param val - Value to place in the Stack structures data property.
 *
 * @returns pointer to the just initialized Stack structure(object).
 */
Stack* initWithOperator(char val) {
    Stack *newStack = (Stack *) malloc(sizeof(Stack));
    
    if(newStack == NULL) {
        return NULL;
    }
    
    newStack->data.expressionOperator = val;
    newStack->size = 1;
    newStack->isOperator = 1;
    newStack->next = NULL;
    
    return newStack;
}

/**
 * pushOperand is pushing a new int value to the top of the stack. 
 * Since the Stack structure is a LIFO(Last In First Out) the value pushed
 * is stored into a new Stack structure and the old head Stack (Top) is getting 
 * replace with the new Stack created. 
 * That makes it so that the new Stack is the new top pointing to the old top.
 *
 * @param **head - Pointer to the pointer of head, we use pointer to pointers to
 * make it easier by letting us change the entire head Stack from this function.
 * @param val -  Integer value to place in the Stack structures data property.
 * This integer will act as an operand that can be used in evaluations.
 */
void pushOperand(Stack **head, int val) {
    if (!isEmpty(*head) && (*head)->isOperator) {
        printf("Cannot push operator to operand stack.\n");
        return;
    }
    
    Stack *newStack = (Stack *) malloc(sizeof(Stack));
    
    newStack->data.expressionOperand = val;
    newStack->isOperator = 0;
    
    newStack->next = *head;
    if (!isEmpty(*head)) {
        newStack->size = newStack->next->size + 1;
    } else {
        newStack->size = 1;
    }
    *head = newStack;
}

/**
 * pushOperator is pushing a new char value to the top of the stack. 
 * Since the Stack structure is a LIFO(Last In First Out) the value pushed 
 * is stored into a new Stack structure and the old head Stack (Top) is getting
 * replace with the new Stack created. 
 * That makes it so that the new Stack is the new top pointing to the old top.
 *
 * @param **head - Pointer to the pointer of head, we use pointer to pointers to
 * make it easier by letting us change the entire head Stack from this function.
 * @param val - Char value to place in the Stack structures data property. This
 * char will act as a operator like + - * and /
 */
void pushOperator(Stack **head, char val) {
    if (!isEmpty(*head) && !(*head)->isOperator) {
        printf("Cannot push operand to operator stack.\n");
        return;
    }
    Stack *newStack = (Stack *) malloc(sizeof(Stack));
    
    newStack->data.expressionOperator = val;
    newStack->isOperator = 1;
    
    newStack->next = *head;
    if (!isEmpty(*head)) {
        newStack->size = newStack->next->size + 1;
    } else {
        newStack->size = 1;
    }
    *head = newStack;
}

/**
 * pop is removing the first element of the Stack. Since all Stacks are linked
 * through the next property pointing to the next Stack in the linked list it
 * can remove the current top and then make the new top become the next Stack
 * of the linked list.
 *
 * @param **head - Pointer to the pointer of head, we use pointer to pointers to
 * make it easier by letting us change the entire head Stack from this function.
 * @param val - Value to place in the Stack structures data property.
 *
 * @returns The data value from the removed Stack. Returns -1 if the Stack is
 * empty.
 */
int pop(Stack **head){
    if (isEmpty(*head)) {
        return -1;
    }
    
    Stack *newStack = (*head)->next;
    int retval;
    
    if ((*head)->isOperator) {
        retval = (*head)->data.expressionOperator;
    } else {
        retval = (*head)->data.expressionOperand;
    }
    free(*head);
    *head = newStack;
    
    return retval;
}

/**
 * peek is a function that lets the caller view the value of the element at the
 * top of the stack without removing it. 
 *
 * @param **head - Pointer to the pointer of head, we use pointer to pointers to
 * make it easier by letting us change the entire head Stack from this function.
 *
 * @returns The data value found on the top of the Stack. Returns -1 if the
 * Stack is empty.
 */
int peek(Stack **head) {
    if (!isEmpty(*head)) {
        if (!(*head)->isOperator) {
            return (*head)->data.expressionOperand;
        } else {
            return (*head)->data.expressionOperator;
        }
    }
    return -1;
}

/**
 * deleteStack is a function that lets the caller delete their entire Stack
 * structure by calling this function.
 *
 * @param **head - Pointer to the pointer of head, we use pointer to pointers to
 * make it easier by letting us change the entire head Stack from this function.
 */
void deleteStack(Stack **head) {
    Stack *newStack;
    while (!isEmpty(*head)) {
        newStack = (*head)->next;
        free(*head);
        *head = newStack;
    }
    free(*head);
}

/**
 * isEmpty checks if the Stack passed into the parameters is empty.
 *
 * @param *head - The Stack to check if empty or not.
 *
 * @returns 1 if the Stack is empty. Returns 0 if the Stack is not empty.
 */
int isEmpty(Stack *head) {
    
    if (head == NULL) {
        return 1;
    }
    
    return 0;
}

/**
 * display loops through the entire Stacks linked list priting out every
 * data property found while looping through the entire list of linked Stacks.
 *
 * @param *head - The target Stack to loop through its linked elements.
 */
void display(Stack *head) {
    Stack *current = head;
    
    while (current != NULL) {
        if (!current->isOperator) {
            printf("Stack Data: %i, Stack Size: %i\n", current->data.expressionOperand, current->size);
        }
        current = current->next;
    }
}