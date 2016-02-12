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

double calculate(Stack **OpStack, Stack **OperandStack, double result, char* string) {
    double result2;
    /*if (!isEmpty(*OpStack)) {
        switch ((*OpStack)->opType) {
            case operand:
                if ((*OpStack)->operand != 0) {
                    //PUSHING OPERAND INTO THE OPERANDSTACK
                    if (isEmpty(*OperandStack)) {
                        *OperandStack = initWithOperand((*OpStack)->operand);
                    } else {
                        pushOperand(OperandStack, operand, (*OpStack)->operand);
                    }
                    calculate(&(*OpStack)->next, &(*OperandStack), result, "");
                }
                break;
            case constant:
                calculate(&(*OpStack)->next, &(*OperandStack), ((*OpStack)->operand), "");
                break;
            case unaryOperation:
                calculate(&(*OpStack)->next, &(*OperandStack), ((*OpStack)->UnaryOperation(result)), "");
                break;
            case binaryOperation:
                display(*OperandStack);
                calculate(&(*OpStack)->next, &(*OperandStack), (*OpStack)->BinaryOperation(pop(OperandStack), pop(OperandStack)), "");
                break;
        }
    }*/
    
   /* while (current != NULL) {
        if (current->opType == operand) {
            if (isEmpty(*OperandStack)) {
                *OperandStack = initWithOperand((*OpStack)->operand);
            } else {
                pushOperand(OperandStack, operand, (*OpStack)->operand);
            }
        }
        current = current->next;
    }*/
    printf("OperandStack POPULATED\n");
    display(*OperandStack);
    
    Stack *current2 = *OpStack;
    while (current2 != NULL) {
        if (current2->opType == binaryOperation) {
            int val1 = pop(&(*OperandStack));
            int val2 = pop(&(*OperandStack));
            printf("Preforming operation between %i and %i\n", val1, val2);
            result2 += current2->BinaryOperation(val1, val2);
        }
        current2 = current2->next;
    }
    
    
    return result2;
}