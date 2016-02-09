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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"
#include "Parser.h"

int main(int argc, const char * argv[]) {
    // insert code here....
    printf("Hello, World!\n");
    
    Stack *root = initWithOperand(5);
    
    pushOperand(&root, 5);
    pushOperand(&root, 10);
    pushOperand(&root, 15);
    
    display(root);
    
    printf("Popping top of the stack: %i\n", pop(&root));
    printf("Popping top of the stack: %i\n", pop(&root));
    printf("Popping top of the stack: %i\n", pop(&root));
    printf("Popping top of the stack: %i\n", pop(&root));
    printf("Popping top of the stack: %i\n", pop(&root));
    printf("Popping top of the stack: %i\n", pop(&root));
    
    display(root);
    if(isEmpty(root)) {
        printf("The Stack is empty\n");
    }
    
    pushOperand(&root, 100);
    
    if(!isEmpty(root)) {
        printf("The Stack is not empty\n");
    }
    
    printf("Peeking on the top of the stack: %i\n", peek(&root));
    
    pop(&root);
    
    printf("Peeking on the top of the stack: %i\n", peek(&root));
    
    pushOperand(&root, 10);
    pushOperand(&root, 20);
    pushOperand(&root, 30);
    
    display(root);
    
    deleteStack(&root);
    
    display(root);
    
    for (int x = 0; x < 10000; x++) {
        pushOperand(&root, x);
    }
   
    deleteStack(&root);
    
    pushOperand(&root, 55);
    pushOperand(&root, 155);
    display(root);
    
    pushOperator(&root, 'b');
    
    
    Stack *operationStack = initWithOperand(0);
    
    parseExpression("55 + 5 / 3", 10, &operationStack);
    
    return 0;
}
