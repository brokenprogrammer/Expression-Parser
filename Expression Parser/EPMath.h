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

#ifndef EPMath_h
#define EPMath_h

#include <stdio.h>

/*
 * Add
 * Adds two values and returns their sum.
 *
 * @param a - Value 1.
 * @param b - Value 2.
 */
double Add(double a, double b);

/*
 * Sub
 * Subtracts two values and returns their difference.
 *
 * @param a - Value 1.
 * @param b - Value 2.
 */
double Sub(double a, double b);

/*
 * Divide
 * Divides two values and returns their quotient.
 *
 * @param a - Value 1.
 * @param b - Value 2.
 */
double Divide(double a, double b);

/*
 * Multiply
 * Multiplies two values and returns their product.
 *
 * @param a - Value 1.
 * @param b - Value 2.
 */
double Multiply(double a, double b);

#endif /* EPMath_h */
