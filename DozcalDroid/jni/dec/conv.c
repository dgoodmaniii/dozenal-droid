/* +AMDG */
/*
 * This file was begun on 13 January 2009, the commemoration
 * of the Baptism of Our Lord, and it is humbly dedicated to
 * the Immaculate Heart of Mary for her prayers, and to the
 * Sacred Heart of Jesus for His mercy.
 */
/*
 * Contains the code for some basic routines for conversion
 * of dozenal numbers to decimal and vice-versa.  Part of
 * the dozenal package.
 *
 * (C) Copyright 2010, 2011  Donald P. Goodman III
 *
 * This file is part of dec.
 *
 * dec is free software:  you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any
 * later version.
 *
 * dec is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with dec.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *s)
{
	int i, j;
	char tmp;
	size_t length;

	length = strlen(s) - 1;
	for (i=0, j=length; i<j; ++i, --j) {
		tmp = *(s+i);
		*(s+i) = *(s+j);
		*(s+j) = tmp;
	}
}

int getword(char *s, int lim)
{
	int c, i;

	--lim;
	for (i=0; (c=getchar())!=EOF && c!='\n' && c!='\t' && c!=' '; ++i) {
		if (i < lim-1)
			*(s+i) = c;
		else if (i == lim)
			*(s+i) = '\0';
	}
	if (c == EOF)
		return EOF;
	if (i < lim)
		*(s+i) = '\0';
	return i;
}

int isdozdig(char c)
{
	switch (c) {
	case '0': case '1': case '2': case '3': case '4': case
	'5': case '6': case '7': case '8': case '9': case 'A':
	case 'a': case 'B': case 'b': case 'X': case 'x': case
	'E': case 'e': case 'T': case 't': case ';': case '-':
		return 1;
		break;
	default:
		return 0;
		break;
	}
}
