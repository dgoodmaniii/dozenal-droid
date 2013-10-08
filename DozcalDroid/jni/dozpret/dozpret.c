/*
 * +AMDG  This document was begun on 22 September 11E7, the
 * commemoration of Sts. Cyprian and Justina, VM, and it is
 * humbly dedicated to them and to the Immaculate Heart of
 * Mary for their prayers, and to the Sacred Heart of Jesus
 * for His mercy.
 *
 */
/*
 * Pretty-prints dozenal numbers output by the other dozenal
 * suite programs---or any text stream, really.
 *
 * (C) Copyright 2011  Donald P. Goodman III
 *
 * This file is part of dozpret.
 *
 * dozpret is free software:  you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any
 * later version.
 *
 * dozpret is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with dozpret.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "conv.h"

#define MAXLINE 1000

int main(int argc, char *argv[])
{
	int i;
	int xflag = 0;
	char transdec = 0, needfreesp = 0, needfreept = 0;
	char needfreeten = 0, needfreeelv = 0;
	char c;
	char *spacer = " ";
	char *zenpoint = ";";
	char *ten = "X";
	char *elv = "E";
	int spaces = 4;
	char number[MAXLINE];

	restart:
	while (--argc > 0 && (*++argv)[0] == '-') {
		if (isdigit(argv[0][1]) || argv[0][1] == '.')
			break; /* negative numbers are not optional args */
		while (c = *++argv[0])
			switch (c) {
			case '1': case '2': case '3': case '4': case '5':
			case '6': case '7': case '8': case '9': case '0':
			case ';': case 'X': case 'E':
				break;
			case 'f':
				transdec = 1;
				break;
			case 'x':
				xflag = 1;
				break;
			case 'l':
				if ((spacer = malloc(sizeof(char)*4)) == NULL) {
					fprintf(stderr,"dozpret:  insufficient memory\n");
					return 1;
				}
				*spacer = '\\'; *(spacer+1) = ','; *(spacer+2) = '\0';
				if ((ten = malloc(sizeof(char)*4)) == NULL) {
					fprintf(stderr,"dozpret:  insufficient memory\n");
					return 1;
				}
				*ten = '\\'; *(ten+1) = 'x'; *(ten+2) = '\0';
				if ((elv = malloc(sizeof(char)*4)) == NULL) {
					fprintf(stderr,"dozpret:  insufficient memory\n");
					return 1;
				}
				*elv = '\\'; *(elv+1) = 'e'; *(elv+2) = '\0';
				needfreesp = 1;
				needfreeten = 1;
				needfreeelv = 1;
				transdec = 1;
				break;
			case 'h': /* Hammond */
				if ((zenpoint = malloc(sizeof(char)*2)) == NULL) {
					fprintf(stderr,"dozpret:  insufficient memory\n");
					return 1;
				}
				*zenpoint = '\''; *(zenpoint+1) = '\0';
				needfreept = 1;
				break;
			case 'a':
				if ((spacer = malloc(sizeof(char)*2)) == NULL) {
					fprintf(stderr,"dozpret:  insufficient memory\n");
					return 1;
				}
				*spacer = ','; *(spacer+1) = '\0';
				needfreesp = 1;
				spaces = 3;
				break;
			case 'b':
				if ((ten = malloc(sizeof(char)*4)) == NULL) {
					fprintf(stderr,"dozpret:  insufficient memory\n");
					return 1;
				}
				*ten = 'T'; *(ten+1) = '\0';
				transdec = 1;
				needfreeten = 1;
				if ((zenpoint = malloc(sizeof(char)*2)) == NULL) {
					fprintf(stderr,"dozpret:  insufficient memory\n");
					return 1;
				}
				*zenpoint = '\''; *(zenpoint+1) = '\0';
				needfreept = 1;
				break;
			case 'p':
				if (needfreept == 1) {
					free(zenpoint);
					needfreept = 0;
				}
				if (*++argv[0] != '\0') {
					zenpoint = argv[0];
					goto restart;
				} else if (*(argv+1) == NULL) {
					fprintf(stderr,"dozpret:  invalid zenpoint character\n");
					return 1;
				} else if (*(argv+1)[0] != '-') {
					zenpoint = *(argv+1);
					--argc; ++argv;
					goto restart;
				} else {
					fprintf(stderr,"dozpret:  invalid zenpoint characters(s)\n");
					return 1;
				}
				break;
			case 's':
				if (needfreesp == 1) {
					free(spacer);
					needfreesp = 0;
				}
				if (*++argv[0] != '\0') {
					spacer = argv[0];
					goto restart;
				} else if (*(argv+1) == NULL) {
					fprintf(stderr,"dozpret:  invalid spacer character\n");
					return 1;
				} else if (*(argv+1)[0] != '-') {
					spacer = *(argv+1);
					--argc; ++argv;
					goto restart;
				} else {
					fprintf(stderr,"dozpret:  invalid spacer characters(s)\n");
					return 1;
				}
				break;
			case 't':
				if (needfreeten == 1) {
					free(ten);
					needfreeten = 0;
				}
				transdec = 1;
				if (*++argv[0] != '\0') {
					ten = argv[0];
					goto restart;
				} else if (*(argv+1) == NULL) {
					fprintf(stderr,"dozpret:  invalid ten character\n");
					return 1;
				} else if (*(argv+1)[0] != '-') {
					ten = *(argv+1);
					--argc; ++argv;
					goto restart;
				} else {
					fprintf(stderr,"dozpret:  invalid ten characters(s)\n");
					return 1;
				}
				break;
			case 'e':
				if (needfreeelv == 1) {
					free(elv);
					needfreeelv = 0;
				}
				transdec = 1;
				if (*++argv[0] != '\0') {
					elv = argv[0];
					goto restart;
				} else if (*(argv+1) == NULL) {
					fprintf(stderr,"dozpret:  invalid elv character\n");
					return 1;
				} else if (*(argv+1)[0] != '-') {
					elv = *(argv+1);
					--argc; ++argv;
					goto restart;
				} else {
					fprintf(stderr,"dozpret:  invalid elv characters(s)\n");
					return 1;
				}
				break;
			case 'n':
				if (*++argv[0] != '\0') {
					if (isdigit(*argv[0]))
						spaces = atoi(argv[0]);
					else
						fprintf(stderr,"dozpret:  invalid quantity\n");
					goto restart;
				} else if (*(argv+1) == NULL) {
					fprintf(stderr,"dozpret:  invalid quantity\n");
					return 1;
				} else if (*(argv+1)[0] != '-') {
					if (isdigit(*argv[0]))
						spaces = atoi(*(argv+1));
					else
						fprintf(stderr,"dozpret:  invalid quantity\n");
					--argc; ++argv;
					goto restart;
				} else {
					fprintf(stderr,"dozpret:  invalid quantity\n");
					return 1;
				}
				break;
			case 'v':
				printf("dozpret v1.0\n");
				printf("Copyright (C) 2011  Donald P. Goodman III\n");
				printf("License GPLv3+:  GNU GPL version 3 or "
				"later <http://gnu.org/licenses/gpl.html>\n");
				printf("This is free software:  you are free "
				"to change and redistribute it.  There is NO "
				"WARRANTY, to the extent permitted by law.\n");
				return 0;
				break;
			default:
				fprintf(stderr,"dozpret:  illegal option \"%c\"\n",c);
				break;
			}
	}
	if (argc >= 1) {
		if (strlen(*argv) >=MAXLINE)
			*argv[MAXLINE] = '\0';
		dozpret(*argv,spacer,zenpoint,spaces,xflag);
		if (transdec == 1)
			fixtrans(*argv,ten,elv);
		printf("%s\n",*argv);
	} else {
		while (getword(number,MAXLINE) != EOF) {
			dozpret(number,spacer,zenpoint,spaces,xflag);
			if (transdec == 1)
				fixtrans(number,ten,elv);
			printf("%s\n",number);
		}
	}
	if (needfreesp == 1)
		free(spacer);
	if (needfreept == 1)
		free(zenpoint);
	if (needfreeten == 1)
		free(ten);
	if (needfreeelv == 1)
		free(elv);
	return 0;
}

int dozpret(char *number,char *spacer,char *zenpoint, int spaces, int xflag)
{
	int i, j, k, len, both = 0;
	char fracpart[MAXLINE]; /* fractional part of number */

	if (strchr(number,';') == NULL)
		both = 1;
	if (*number == '-')
		++number;
	len = strlen(number);
	for (i=0; number[i] != ';' && i < len; ++i);
	if (both == 0) {
		strcpy(fracpart,number+i+1);
		number[i] = '\0';
	}
	if (xflag == 0)
		prettify(number,spacer,spaces);
	if (both == 1)
		return 0;
	reverse(fracpart); reverse(spacer);
	if (xflag == 0)
		prettify(fracpart,spacer,spaces);
	reverse(fracpart); reverse(spacer);
	if (strlen(number) + strlen(zenpoint) < MAXLINE) {
		strcat(number,zenpoint);
	} else {
		fprintf(stderr,"dozpret:  insufficient memory\n");
		exit(1);
	}
	if (strlen(number) + strlen(fracpart) < MAXLINE) {
		strcat(number,fracpart);
	} else {
		fprintf(stderr,"dozpret:  insufficient memory\n");
		exit(1);
	}
	return 0;
}

int prettify(char *number, char *spacer, int spaces)
{
	int i, j, k, len;
	size_t sepnum;

	len = i = strlen(number);
	sepnum = strlen(spacer);
	for (j=i,k=0; j>0; --j,++k) {
		if ((k % spaces == 0) && (k != 0)) {
			memmove(number+j+sepnum,number+j,len-j+1);
			memcpy(number+j,spacer,sepnum);
			len = strlen(number);
			i=i+sepnum;
		}
		if (number[j] == 'e')
			return 0;
	}
	return 0;
}

int fixtrans(char *number, char *ten, char *elv)
{
	int i, j, k;
	size_t lenstr,len,chunk;
	char *digit;
	char trans;

	len = strlen(number);
	for (i=0; i<=1; i++) {
		lenstr = (i == 0) ? strlen(ten) : strlen(elv);
		digit = (i == 0) ? ten : elv;
		trans = (i == 0) ? 'X' : 'E';
		for (j=0; number[j] != '\0'; ++j) {
			if (number[j] == trans) {
				chunk = strlen(number+j)+1;
				memmove(number+j+lenstr-1,number+j,chunk);
				memcpy(number+j,digit,lenstr);
			}
		}
	}
	return 0;
}
