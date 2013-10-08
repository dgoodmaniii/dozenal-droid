/* +AMDG */
/*
 * This document was begun on 15 January 2010, the feast of
 * St. Paul the Hermit, and it is humbly dedicated to him
 * and to the Immaculate Heart of Mary for their prayers,
 * and to the Sacred Heart of Jesus for His mercy.
 */
/*
 * The main routine for the dozdc program.  Parses options
 * and gets things rolling.
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
#include<math.h>
#include "conv.h"
#include "dozdc.h"
#include "stack.h"
#include<float.h>

int runcalc(int places, char expnot);
double operate(int operator, int *places, char *print);
double commandcalc(char *word, int type, int places, char expnot);

int main(int argc, char *argv[])
{
	char expnot = 0;
	int places = 4;
	char c;
	char word[MAXLINE];
	int type = NUM;
	char print = NOTPRINT;
	double answer;

	while (--argc > 0 && (*++argv)[0] == '-') {
		while (c = *++argv[0])
			switch (c) {
			case '1': case '2': case '3': case '4': case '5':
			case '6': case '7': case '8': case '9': case '0':
			case '.':
				break;
			case 'k':
				if (isdozdig(*++argv[0])) {
					places = dozprecis(argv[0]);
				} else if (*(argv+1) == NULL) {
					fprintf(stderr,"doz:  invalid precision quantity\n");
					exit(1);
				} else if (isdozdig(*(argv+1)[0])) {
					places = dozprecis(*(argv+1));
					--argc, ++argv;
				} else {
					fprintf(stderr,"doz:  invalid precision quantity\n");
					exit(1);
				}
				if (places < 0) {
					fprintf(stderr,"doz:  invalid precision quantity\n");
					exit(1);
				}
				break;
			case 'e':
				expnot = 1;
				break;
			case 'd':
				operate(DEGREES,&places,&print);
				break;
			case 'r':
				operate(RADIANS,&places,&print);
				break;
			case 'z':
				operate(ZENIPI,&places,&print);
				break;
			case 'v':
				printf("dozdc v3.1\n");
				printf("Copyright (C) 2010, 2011  Donald P. Goodman III\n");
				printf("License GPLv3+:  GNU GPL version 3 or "
				"later <http://gnu.org/licenses/gpl.html>\n");
				printf("This is free software:  you are free "
				"to change and redistribute it.  There is NO "
				"WARRANTY, to the extent permitted by law.\n");
				return 0;
				break;
			default:
				fprintf(stderr,"doz:  illegal option \"%c\"\n",c);
				break;
			}
	}
	if (argc >= 1) {
		char s[MAXLINE+1];
		strcpy(s,*argv);
		s[strlen(s)+1] = '\0';
		s[strlen(s)] = ' ';
		while ((type = commandops(s,word)) != EOF)
			answer = commandcalc(word, type, places, expnot);
		sprintf(word,"%.*f",DBL_MAX_10_EXP,answer);
		doz(word,word,places,expnot);
		clean();
		return 0;
	}
	while (runcalc(places,expnot) != EOF);
	clean();
	return 0;
}

double commandcalc(char *word, int type, int places, char expnot)
{
	int operator;
	char s[MAXLINE];
	double answer;
	char print = NOTPRINT;

	if (type == NUM) {
		push(doztodec(word));
	} else if (type == OP) {
		operator = getop(word);
		if (operator == -1)
			fprintf(stderr,"dozdc:  unknown operator %s\n",word);
		else
			answer = operate(operator,&places,&print);
	}
	return answer;
}

int runcalc(int places, char expnot)
{
	int i;
	int type;
	int operator;
	char s[MAXLINE];
	double answer;
	char print = NOTPRINT;

	while ((type = gettype(s)) != EOF) {
		if (type == NUM) {
			push(doztodec(s));
		} else if (type == OP) {
			operator = getop(s);
			if (operator == -1)
				fprintf(stderr,"dozdc:  unknown operator %s\n",s);
			else
				answer = operate(operator,&places,&print);
		}
		if (print == PRINT) {
			sprintf(s,"%.*f",DBL_MAX_10_EXP,answer);
			doz(s,s,places,expnot);
			print = NOTPRINT;
		}
	}
	return EOF;
}
