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

/**
 * parseExpression
 */
void parseExpression(char* string, int size, Stack **OpStack) {
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
                
                /*OpStack[opPos] = malloc(sizeof(opStack));
                OpStack[opPos]->opType = binaryOperation;
                OpStack[opPos]->BinaryOperation = Add;*/
                opPos = opPos + 1;
                break;
            case '-':
                printf("Minus\n");
                /*OpStack[opPos] = malloc(sizeof(opStack));
                OpStack[opPos]->opType = binaryOperation;
                OpStack[opPos]->BinaryOperation = Sub;*/
                opPos = opPos + 1;
                break;
            case '/':
                printf("Divide\n");
                /*OpStack[opPos] = malloc(sizeof(opStack));
                OpStack[opPos]->opType = binaryOperation;
                OpStack[opPos]->BinaryOperation = Divide;*/
                opPos = opPos + 1;
                break;
            case '*':
                printf("Multiply\n");
                /*OpStack[opPos] = malloc(sizeof(opStack));
                OpStack[opPos]->opType = binaryOperation;
                OpStack[opPos]->BinaryOperation = Multiply;*/
                opPos = opPos + 1;
                break;
            default:
                if (isdigit(*pch)) {
                    /*OpStack[opPos] = malloc(sizeof(opStack));
                    OpStack[opPos]->opType = operand;
                    OpStack[opPos]->operand = convertNumVal(pch);*/
                    //printf("Curr num: %i\n", OpStack[opPos]->operand);
                    opPos = opPos + 1;
                }
                break;
        }
        
        pch = strtok (NULL, " ");
    }
    
    free(newstring);
}

/**
 * convertNumVal
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