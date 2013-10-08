/* +AMDG */
/*
 * This document was begun on 15 January 2010, the feast of
 * St. Paul the Hermit, and it is humbly dedicated to him
 * and to the Immaculate Heart of Mary for their prayers,
 * and to the Sacred Heart of Jesus for His mercy.
 */
/*
 * Basic library functions for the dozdc program.
 *
 * (C) Copyright 2010, 2011  Donald P. Goodman III
 *
 * This file is part of dozdc.
 *
 * dozdc is free software:  you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any
 * later version.
 *
 * dozdc is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with dozdc.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

/* define these for main.c and getop.c */
#define PRINT 1		/* print answer or not */
#define NOTPRINT 0

/* constants referring to numbers or operators */
#define NUM 0
#define OP 1

/* define constants for the various operators */
#define COMM -3 /* special; indicates a comment */
#define VAR -2 /* special; to indicate a variable */
#define ADD 0
#define SUBTRACT 1
#define MULT 2
#define DIVIDE 3
#define MOD 4
#define SQRT 5
#define POW 6
#define SIN 7
#define COS 8
#define TAN 9
#define EQUALS 10
#define PRECISION 11
#define PI 12
#define DEGREES 13
#define RADIANS 14
#define LN 15
#define LOGX 16
#define ASIN 17
#define ACOS 18
#define ATAN 19
#define LOG 20
#define FACTORIAL 21
#define EULER 22
#define PHI 23
#define EXP 24
#define ABS 25
#define QUIT 26
#define RECIPROCAL 27
#define LOGB 28
#define SINH 29
#define COSH 30
#define TANH 31
#define LDEXP 32
#define ZENIPI 33
#define DLG 34
