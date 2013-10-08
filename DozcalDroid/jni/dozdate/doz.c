/* +AMDG */
/* This program was begun on 2 January 2009, the ninth day
 * of Christmas, and it is humbly dedicated to the
 * Immaculate Heart of Mary for her prayers, and to the
 * Child Jesus for His mercy.
 */
/*
 * A program for converting arbitrary decimal numbers, up to
 * and including floating point and exponential notation,
 * into dozenal.
 *
 * (C) Copyright 2011  Donald P. Goodman III
 *
 * This file is part of dozdate.
 *
 * dozdate is free software:  you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any
 * later version.
 *
 * dozdate is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with dozdate.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include "conv.h"

char dozenify(char num);
int dectodoz(char *doznum, double decnum);
int dozprecis(char *s);
int expnotate(char *s);
int negexp(char *s, int zenspot);
int posexp(char *s, int zenspot);

int doz(char *s, char *t, int places, int expnot)
{
	double decnum;
	int i;
	int precise;
	size_t length;

	decnum = atof(t);
	if (decnum > (DBL_MAX)) {
		fprintf(stderr,"doz:  requested value too high; "
		"reducing to highest possible value, %f\n",DBL_MAX);
		decnum = DBL_MAX-1;
	} else if (decnum < -DBL_MAX) {
		fprintf(stderr,"doz:  requested value too low; "
		"increasing to lowest possible value, %f\n",-DBL_MAX);
		decnum = -DBL_MAX+1;
	}
	dectodoz(s, decnum);
	if (expnot == 1)
		expnotate(s);
	for (i=0; s[i] != ';' && s[i] != '\0'; ++i)
		putchar(s[i]);
	if (s[i] == ';') {
		precise = i + places;
		for (i=i; i <= precise && s[i] != '\0'; ++i)
			putchar(s[i]);
		if (expnot == 1 && s[i] != '\0') {
			for (i=0; s[i] != 'e'; ++i);
			if (s[i+1] == 'e')
				++i;
			for (i=i; s[i] != '\0'; ++i)
				putchar(s[i]);
		}
	}
	putchar('\n');
	return 0;
}

int expnotate(char *s)
{
	int zenspot = 1; /* ensures new zenimal point in right place */

	if (*s == '-')
		zenspot = 2;
	if (s[zenspot] == ';')
		negexp(s,zenspot);
	else
		posexp(s,zenspot);
	return 0;
}

int posexp(char *s, int zenspot)
{
	int i=0;
	char zensuf[5]; /* to cat onto the string */
	char *orig; /* pointer to original zenimal spot */

	orig = strchr(s,';');
	if (orig == NULL) {
		i = strlen(s) - zenspot;
		s[strlen(s)+1] = '\0';
		memmove(s+zenspot+1,s+zenspot,strlen(s+zenspot));
		*(s+zenspot) = ';';
	} else {
		i = orig - s - zenspot;
		s[strlen(s)+1] = '\0';
		memmove(orig,orig+1,strlen(orig+1));
		s[strlen(s)+1] = '\0';
		memmove(s+zenspot+1,s+zenspot,strlen(s+zenspot));
		*(s+zenspot) = ';';
	}
	strcat(s,"e");
	dectodoz(zensuf,i);
	strcat(s,zensuf);
	return 0;
}

int negexp(char *s, int zenspot)
{
	int i = 0;
	int origspot = 0; /* where zenimal is originally */
	char zensuf[5]; /* to cat onto the string */
	char *orig; /* pointer to original zenimal point */

	orig = strchr(s,';'); /* can't be null, or would be posexp */
	origspot = orig - s + 1;
	if (s[zenspot-1] == '0') {
		memmove(s+zenspot+1,s+zenspot,strlen(s+zenspot+1));
		for (i=0;s[i]=='0'||s[i]==';'||s[i]=='-';++i); /* first non-zero */
		if (*s == '-')
			memmove(s+1,s+i,strlen(s+i));
		else
			memmove(s,s+i,strlen(s+i));
		memmove(s+zenspot,s+zenspot-1,strlen(s+zenspot));
		*(s+zenspot) = ';';
	} else if (s[zenspot] == ';') {
		origspot = 0;
		i = 0;
	} else { /* FFF */
		for (i=0;s[i]=='0'||s[i]==';'||s[i]=='-';++i); /* first non-zero */
	}
	strcat(s,"e");
	dectodoz(zensuf,origspot-i);
	strcat(s,zensuf);
	return 0;
}

int dozprecis(char *s)
{
	int i;
	int precis;

	if (s == NULL)
		return -1;
	for (i=0; i <= strlen(s) - 1; ++i)
		if (!isdozdig(*(s+i)))
			return -1;
	precis = (int)doztodec(s);
	if (precis > DBL_MAX_10_EXP) {
		fprintf(stderr,"doz:  requested precision too high; "
			"truncating to maximum %d\n",DBL_MAX_10_EXP);
		return DBL_MAX_10_EXP;
	}
	return precis;
}

char dozenify(char num)
{
	switch (num) {
	case 0: case 1: case 2: case 3: case 4: case 5: case 6:
	case 7: case 8: case 9:
		return (num % 10) + '0';
	case 10: 
		return 'X'; 
	case 11:
		return 'E';
	}
}

int dectodoz(char *doznum, double decnum)
{
	int i = 0; int sign = 0; int j = 0;
	double wholedec; /* whole number portion of decnum */
	double partholder; /* someplace for modf to dump integral */

	if (decnum < 0) {
		decnum = -decnum;
		sign = 1;
	}
	partholder = modf(decnum,&wholedec);
	decnum -= wholedec;
	while (wholedec >= 12) {
		*(doznum+(i++)) = dozenify(fmod(wholedec,12.0));
		wholedec /= 12;
	}
	*(doznum+(i++)) = dozenify(fmod(wholedec,12));
	if (sign == 1)
		*(doznum+(i++)) = '-';
	*(doznum+i) = '\0';
	reverse(doznum);
	if (decnum > 0) {
		*(doznum+(i++)) = ';';
		for (i=i; i <= DBL_MAX_10_EXP; ++i) {
			decnum = modf(decnum*12,&partholder);
			*(doznum+i) = dozenify(partholder);
		}
		*(doznum+i) = '\0';
	}
	return 0;
}
