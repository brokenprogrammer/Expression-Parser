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
#include <ctype.h>

typedef enum Operations {
    operand,
    constant,
    unaryOperation,
    binaryOperation
}OpEnum;

typedef struct opStack {
    OpEnum opType;
    
    int operand;
    double constant;
    //Function pointer unary operation
    //Function pointer binary operation
    
} opStack;

void parseExpression(char* string, int size) {
    char *newstring = malloc(strlen(string) + 1);
    strcpy(newstring, string);
    
    char* pch;
    printf ("Splitting string \"%s\" into tokens:\n", newstring);
    pch = strtok(newstring, " ");
    while (pch != NULL)
    {
        printf ("%s %lu\n",pch, strlen(pch));
        if (isdigit(*pch)) {
            convertVal(pch);
        }
        pch = strtok (NULL, " ");
    }
    
    free(newstring);
}

int convertVal(char *string) {
    printf("Is Integer\n");
    return 0;
}