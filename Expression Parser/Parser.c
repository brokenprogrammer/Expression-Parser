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

#include "Parser.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include "EPMath.h"

void doIt(char string[], int size, Stack **OpStack,Stack **OperandStack){
    char newstring[size];
    strcpy(newstring, string);
    
    printf("String working with: %s\n", newstring);
    
    char *p = newstring;
    
    while (*p) { // While there are more characters to process...
        switch (*p) {
            case '+':
                printf("PLUSS\n");
                pushBinaryOp(OpStack, binaryOperation, Add, '+');
                break;
            case '-':
                printf("MINUS\n");
                pushBinaryOp(OpStack, binaryOperation, Sub, '-');
                break;
                
            default:
                break;
        }
        if (isdigit(*p)) { // Upon finding a digit, ...
            long val = strtol(p, &p, 10); // Read a number, ...
            printf("%ld\n", val); // and print it.
            pushOperand(OperandStack, operand, (int)val);
        } else { // Otherwise, move on to the next character.
            p++;
        }
    }
}

/**
 * parseExpression parses a string of mathematical expressions and puts all the
 * individual values into a Stack data structure.
 *
 * @param string - The string to parse
 * @param size - The size of the string
 * @param OpStack - Pointer to the pointer of the stack data structure that
 * the parsed values should be stored to.
 */
void parseExpression(char* string, int size, Stack **OpStack, Stack **OperandStack) {
    //Allocates a new string and copies the string from the parameters into
    //the new allocated string.
    char *newstring = malloc(strlen(string) + 1);
    strcpy(newstring, string);
    
    int opPos = 0;
    
    char* pch;
    printf ("Splitting string \"%s\" into tokens:\n", newstring);
    pch = strtok(newstring, " ");
    while (pch != NULL)
    {
        printf ("%s %lu\n",pch, strlen(pch));
        
        switch (*pch) {
            case '+':
                printf("PLUSS\n");
                if (strlen(pch) > 1) {
                    //parseNested(pch, strlen(pch), OpStack, OperandStack);
                    doIt(pch, 6, OpStack, OperandStack);
                } else {
                    pushBinaryOp(OpStack, binaryOperation, Add, '+');
                }
                opPos = opPos + 1;
                break;
            case '-':
                printf("Minus\n");
                pushBinaryOp(OpStack, binaryOperation, Sub, '-');
                opPos = opPos + 1;
                break;
            case '/':
                printf("Divide\n");
                pushBinaryOp(OpStack, binaryOperation, Divide, '/');
                opPos = opPos + 1;
                break;
            case '*':
                printf("Multiply\n");
                pushBinaryOp(OpStack, binaryOperation, Multiply, '*');
                opPos = opPos + 1;
                break;
            default:
                if (isdigit(*pch)) {
                    pushOperand(OperandStack, operand, convertNumVal(pch));
                    printf("Converted Value: %i, Pushed value: %f\n", convertNumVal(pch), (*OperandStack)->operand);
                    opPos = opPos + 1;
                } else {
                    printf("Dropped unknown value: %s", pch);
                }
                break;
        }
        pch = strtok (NULL, " ");
    }
    free(newstring);
}

/**
 * convertNumVal converts a string of numbers into an integer value.
 *
 * @param string - The string to convert to a number.
 *
 * @returns A number that was converted from a string. Returns 0 if 
 * an error occured.
 */
int convertNumVal(char *string) {
    errno = 0;
    char *end;
    
    long int newLongInt = strtol(string, &end, 10);
    int newInt;
    
    /* Check for various possible errors */
    if ((errno == ERANGE && (newLongInt == LONG_MAX || newLongInt == LONG_MIN))
        || (errno != 0 && newLongInt == 0)) {
        perror("strtol");
        return 0;
    }
    
    
    if (newInt <= INT32_MAX && newInt >= INT32_MIN) {
        newInt = (int)newLongInt;
        return newInt;
    }
    printf("Is Integer %i\n", newInt);
    return 0;
}

void parseNested(char string[], unsigned long size, Stack **OpStack, Stack **OperandStack) {
    char newNum[] = "";
    int lastWasNum = 0;
    
    for (int x = 0; x < size; x++) {
        switch (string[x]) {
            case '+':
                printf("PLUSS\n");
                if (lastWasNum) {
                    printf("PUSHING NUM: %i\n", convertNumVal(newNum));
                    pushOperand(OperandStack, operand, convertNumVal(newNum));
                    lastWasNum = 0;
                    strcpy(newNum, "");
                }
                pushBinaryOp(OpStack, binaryOperation, Add, '+');
                break;
            case '-':
                printf("MINUS\n");
                if (lastWasNum) {
                    printf("PUSHING NUM: %i\n", convertNumVal(newNum));
                    pushOperand(OperandStack, operand, convertNumVal(newNum));
                    lastWasNum = 0;
                    strcpy(newNum, "");
                }
                pushBinaryOp(OpStack, binaryOperation, Sub, '-');
                break;
            default:
                if (isdigit(string[x])) {
                    lastWasNum = 1;
                    unsigned long len = strlen(newNum);
                    newNum[len] = string[x];
                    printf("%c\n", newNum[len]);
                    newNum[len+1] = '\0';
                }
                break;
        }
    }
    
    if (lastWasNum) {
        printf("PUSHING NUM: %i\n", convertNumVal(newNum));
        pushOperand(OperandStack, operand, convertNumVal(newNum));
        lastWasNum = 0;
        //strcpy(newNum, "");
    }
    
    pushOperand(OperandStack, operand, 120);
}