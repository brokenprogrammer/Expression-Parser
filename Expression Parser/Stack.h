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

#ifndef Stack_h
#define Stack_h

#include <stdio.h>

/*
 * Operations Enum
 * Every linked stack will contain an Operation enumeration to tell what
 * each stack contains.
 */
typedef enum Operations {
    operand,
    constant,
    unaryOperation,
    binaryOperation
}OpEnum;

/*
 * Stack Structure
 * This is a stack data structure that is made specifically for this
 * Expression Parser. It contains an Operation Enum to tell if there is for 
 * example an operand or an operation contained in the Stack. If it contains
 * an operation it also contains a function pointer to that operation.
 */
typedef struct Stack {
    int size;
    int isOperator;
    
    OpEnum opType;
    
    double operand;
    double constant;
    char symbol;
    
    double (*UnaryOperation)(double a);
    double (*BinaryOperation)(double a, double b);
    
    struct Stack *next;
}Stack;

/*
 * initWithOperand
 * Initializes a new Stack by allocating a new pointer with
 * the ammount of memory a Stack needs.
 *
 * @param val - Value to place in the Stack structures data property.
 *
 * @returns pointer to the just initialized Stack structure(object).
 */
Stack* initWithOperand(int val);

/*
 * pushOperand
 * Pushes a new int value to the top of the stack. 
 *
 * @param **head - Pointer to the pointer of head, we use pointer to pointers to
 * make it easier by letting us change the entire head Stack from this function.
 * @param val -  Integer value to place in the Stack structures data property.
 * This integer will act as an operand that can be used in evaluations.
 */
void pushOperand(Stack **head, OpEnum opType,  int val);

/*
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
void pushUnaryOp(Stack **head, OpEnum opType, double (*UnaryOperation)(double a), char symbol);

/*
 * pushBinaryOp
 * Pushes a new function pointer to a Binary Operation to the top of the stack.
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
void pushBinaryOp(Stack **head, OpEnum opType, double (*BinaryOperation)(double a, double b), char symbol);

/*
 * pop
 * Removes the first element of the Stack. And returns the value.
 *
 * @param **head - Pointer to the pointer of head, we use pointer to pointers to
 * make it easier by letting us change the entire head Stack from this function.
 * @param val - Value to place in the Stack structures data property.
 *
 * @returns The data value from the removed Stack. Returns -1 if the Stack is
 * empty. Returns an integer number if the top of the stack is an
 * operand. Returns char symbol of the top of the stack is not an operand.
 */
int pop(Stack **head);

/*
 * peek
 * Lets the caller view the value of the element at the
 * top of the stack without removing it.
 *
 * @param **head - Pointer to the pointer of head, we use pointer to pointers to
 * make it easier by letting us change the entire head Stack from this function.
 *
 * @returns The data value found on the top of the Stack. Returns -1 if the
 * Stack is empty. Returns an integer number if the top of the stack is an
 * operand. Returns char symbol of the top of the stack is not an operand.
 */
int peek(Stack **head);

/*
 * deleteStack
 * Lets the caller delete their entire Stack
 * structure by calling this function.
 *
 * @param **head - Pointer to the pointer of head, we use pointer to pointers to
 * make it easier by letting us change the entire head Stack from this function.
 */
void deleteStack(Stack **head);

/*
 * isEmpty
 * Checks if the Stack passed into the parameters is empty.
 *
 * @param *head - The Stack to check if empty or not.
 *
 * @returns 1 if the Stack is empty. Returns 0 if the Stack is not empty.
 */
int isEmpty(Stack *head);

/*
 * display
 * Loops through the entire Stacks linked list priting out every
 * data property found while looping through the entire list of linked Stacks.
 *
 * @param *head - The target Stack to loop through its linked elements.
 */
void display(Stack *head);

void reverseStack(Stack **head);
#endif /* Stack_h */
