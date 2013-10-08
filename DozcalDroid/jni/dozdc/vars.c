/* +AMDG */
/*
 * This document was begun on 23 January 2010, the feast of
 * St. Raymund of Penafort, and it is humbly dedicated to
 * him and to the Immaculate Heart of Mary for their
 * prayers, and to the Sacred Heart of Jesus for His mercy.
 */
/*
 * The variable-handling functions and structs for dozdc.
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

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<float.h>
#include "stack.h"

#define MAXVARS 50
#define MAXCHARS 30

struct var {
	char name[MAXCHARS]; /* name of the variable */
	double val; /* value of the variable */
};

static struct var vars[MAXVARS];
static int varindex = 0; /* variable stack index */

int dealvar(char *s)
{
	int i;

	for (i=0; i <= varindex; ++i) {
		if (!strcmp(s,vars[i].name)) {
			push(vars[i].val);
			return 0;
		}
	}
	newvar(s);
	return 0;
}

int newvar(char *s)
{
	if (varindex < MAXVARS) {
		strncpy(vars[varindex].name,s,MAXCHARS-1);
		if (strlen(s) > (MAXCHARS-1))
			vars[varindex].name[MAXCHARS] = '\0';
		vars[varindex].val = pop();
		++varindex;
	} else {
		fprintf(stderr,"dozdc:  too many variables; cannot "
		"save variable %s\n",s);
		return 1;
	}
	return 0;
}
