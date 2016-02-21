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
    
    newStack->size = 1;
    newStack->opType = operand;
    newStack->operand = val;
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
void pushOperand(Stack **head, OpEnum opType,  int val) {
    if (isEmpty(*head)) {
        
        (*head) = initWithOperand(val);
        
        return;
    }
    
    Stack *newStack = (Stack *) malloc(sizeof(Stack));
    
    newStack->opType = opType;
    newStack->operand = val;
    
    newStack->next = *head;
    if (!isEmpty(*head)) {
        newStack->size = newStack->next->size + 1;
    } else {
        newStack->size = 1;
    }
    *head = newStack;
}

/**
 * pushUnaryOp 
 * Pushes a new function pointer to a Unary Operation to the top of the stack.
 *
 * @param **head - Pointer to the pointer of head, we use pointer to pointers to
 * make it easier by letting us change the entire head Stack from this function.
 * @param opType - The opType value which will later when looping through the
 * linked list be used with a switch statement to check what each value is
 * in the Stack.
 * @param (*BinaryOperation) - A pointer to a function, this will be a pointer
 * to a binary operation function.
 * @param symbol - Char value to place in the Stack structures data property.
 */
void pushUnaryOp(Stack **head, OpEnum opType, double (*UnaryOperation)(double a), char symbol) {
    if (isEmpty(*head)) {
        
        //TODO: MAKE FIX LIKE FOR PUSHOPERAND
        
        return;
    }
    Stack *newStack = (Stack *) malloc(sizeof(Stack));
    
    newStack->opType = opType;
    newStack->UnaryOperation = UnaryOperation;
    newStack->symbol = symbol;
    
    newStack->next = *head;
    if (!isEmpty(*head)) {
        newStack->size = newStack->next->size + 1;
    } else {
        newStack->size = 1;
    }
    *head = newStack;
}

/**
 * pushBinaryOp pushes a new function pointer to the top of the stack. The 
 * function will act as an math operation that needs two values like 1 + 2
 * Since the Stack structure is a LIFO(Last In First Out) the value pushed
 * is stored into a new Stack structure and the old head Stack (Top) is getting
 * replace with the new Stack created.
 * That makes it so that the new Stack is the new top pointing to the old top.
 *
 * @param **head - Pointer to the pointer of head, we use pointer to pointers to
 * make it easier by letting us change the entire head Stack from this function.
 * @param opType - The opType value which will later when looping through the
 * linked list be used with a switch statement to check what each value is
 * in the Stack.
 * @param (*BinaryOperation) - A pointer to a function, this will be a pointer
 * to a binary operation function.
 * @param symbol - Char value to place in the Stack structures data property. This
 * char will act as a operator like + - * and /
 */
void pushBinaryOp(Stack **head, OpEnum opType,
                  double (*BinaryOperation)(double a, double b), char symbol) {
    
    if (isEmpty(*head)) {
        
        //TODO: MAKE FIX LIKE FOR PUSHOPERAND
        
        return;
    }
    
    Stack *newStack = (Stack *) malloc(sizeof(Stack));
    
    newStack->opType = opType;
    newStack->BinaryOperation = BinaryOperation;
    newStack->symbol = symbol;
    
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
 * empty. Returns an integer number if the top of the stack is an
 * operand. Returns char symbol of the top of the stack is not an operand.
 */
int pop(Stack **head){
    if (isEmpty(*head)) {
        return -1;
    }
    
    Stack *newStack = (*head)->next;
    int retval;
    
    switch ((*head)->opType) {
        case operand:
            retval = (*head)->operand;
            break;
        case constant:
            retval = (*head)->symbol;
            break;
        case unaryOperation:
            retval = (*head)->symbol;
            break;
        case binaryOperation:
            retval = (*head)->symbol;
            break;
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
 * Stack is empty. Returns an integer number if the top of the stack is an 
 * operand. Returns char symbol of the top of the stack is not an operand.
 */
int peek(Stack **head) {
    if (!isEmpty(*head)) {
        if ((*head)->opType == operand) {
            return (*head)->operand;
        } else {
            return (*head)->symbol;
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
        if (current->opType == operand) {
            printf("Stack Data: %f, Stack Size: %i\n", current->operand, current->size);
        } else if (current->opType == binaryOperation) {
            printf("Stack BinaryOperationResult: %c  %f, Stack Size: %i\n", current->symbol, current->BinaryOperation(10, 10), current->size);
        }
        current = current->next;
    }
}

/**
 * reverseStack loops through the entire Stacks linked list and placing all the
 * content into a new created Stack, that way reversing the content of the
 * Stack.
 *
 * @param **head - The target Stack to loop through its linked elements. And 
 * place in reversed order.
 */
void reverseStack(Stack **head) {
    Stack *newStack = (Stack *) malloc(sizeof(Stack));
    
    while (*head) {
        switch ((*head)->opType) {
            case operand:
                if ((*head)->operand != 0) {
                    pushOperand(&newStack, operand, (*head)->operand);
                }
                break;
            case constant:
                
                break;
            case unaryOperation:
                pushUnaryOp(&newStack, unaryOperation, (*head)->UnaryOperation, (*head)->symbol);
                break;
            case binaryOperation:
                pushBinaryOp(&newStack, binaryOperation, (*head)->BinaryOperation, (*head)->symbol);
                break;
        }
        pop(head);
    }
    
    *head = newStack;
}