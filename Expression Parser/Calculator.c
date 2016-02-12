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

#include "Calculator.h"

double calculate(Stack **OpStack, Stack **OperandStack) {
    double result = 0;
    
    Stack *current = *OpStack;
    for (; current; current = current->next) {
        switch (current->opType) {
            case binaryOperation:
                result += current->BinaryOperation(pop(OperandStack), pop(OperandStack));
                printf("Current result: %f\n", result);
                break;
                
            default:
                printf("Something else than an operation was found here..\n");
                break;
        }
    }
    
    return result;
}