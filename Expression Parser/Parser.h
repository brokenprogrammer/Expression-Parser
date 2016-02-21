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

#ifndef Parser_h
#define Parser_h

#include <stdio.h>
#include "Stack.h"

/**
 * parseExpression parses a string of mathematical expressions and puts all the
 * individual values into a Stack data structure.
 *
 * @param string - The string to parse
 * @param size - The size of the string
 * @param OpStack - Pointer to the pointer of the stack data structure that
 * the parsed values should be stored to.
 * @param OperandStack - Pointer to the pointer of the stack data structure that
 * the parsed operands should be stored to.
 */
void parseExpression(char* string, int size, Stack **OpStack, Stack **OperandStack);

/**
 * parseNested parses a string of mathematical expressions and puts all the
 * individual values into a Stack data structure. This function parses nested
 * expressions that is not separated with a space for example "+15-20".
 *
 * @param string - The string to parse
 * @param size - The size of the string
 * @param OpStack - Pointer to the pointer of the stack data structure that
 * the parsed values should be stored to.
 * @param OperandStack - Pointer to the pointer of the stack data structure that
 * the parsed operands should be stored to.
 */
void parseNested(char string[], unsigned long size, Stack **OpStack, Stack **OperandStack);


/*
 * parseCommandlineArgs parses all the arguments passed into the application
 * and puts all the mathematical expressions found in the arguments into Stack
 * data structures.
 *
 * @param args - The number of arguments passed to the application.
 * @param argv - An array of arguments in the char type.
 * @param OpStack - Pointer to the pointer of the stack data structure that
 * the parsed operators should be stored to.
 * @param OperandStack - Pointer to the pointer of the stack data structure that
 * the parsed operands should be stored to.
 */
void parseCommandlineArgs(int args, const char *argv[], Stack** OpStack, Stack **OperandStack);

/*
 * parsePolishNotation parses all the arguments passed into the application
 * and puts all the mathematical expressions found in the arguments into a Stack
 * data structure.
 *
 * @param args - The number of arguments passed to the application.
 * @param argv - An array of arguments in the char type.
 * @param OpStack - Pointer to the pointer of the stack data structure that
 * the parsed values should be stored to.
 */
void parsePolishNotation(char string[], unsigned long size, Stack **OpStack);

/**
 * convertNumVal converts a string of numbers into an integer value.
 *
 * @param string - The string to convert to a number.
 *
 * @returns A number that was converted from a string. Returns 0 if
 * an error occured.
 */
int convertNumVal(char *string);

#endif /* Parser_h */
