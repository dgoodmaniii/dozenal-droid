/*
	* +AMDG
	* This document was begun on 26 January 11E9, the feast of
	* St. Martina, Virgin and Martyr; and it is humbly dedicated
	* her and to the Immaculate Heart of Mary for their prayers,
	* and to the Sacred Heart of Jesus for His mercy.
*/
/*
 * A program for converting arbitrary decimal numbers, up to
 * and including floating point and exponential notation,
 * into dozenal.
 *
 * (C) Copyright 2010, 2011  Donald P. Goodman III
 *
 * This file is part of dozstring.
 *
 * dozstring is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * dozstring is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General
 * Public License along with dozstring. If not, see
 * <http://www.gnu.org/licenses/>.
*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "conv.h"

#define MAXLINE 1000
#define BAD_OPT 1
#define TOO_LONG 2

int main(int argc, char *argv[])
{
	char c;
	char tenchar = 'X';
	char elvchar = 'E';
	char padchar = '0';
	char newline = 0;
	char starprint = 0;
	char decnum[MAXLINE];
	char doznum[MAXLINE];
	char *convstring = NULL;
	double decimal;
	int i; int j; int k;

	while ((c = getopt(argc,argv,"c:vsnx:e:p:")) != -1) {
		switch (c) {
		case 's':
			starprint = 1;
			break;
		case 'n':
			newline = 1;
			break;
		case 'x':
			tenchar = *optarg;
			break;
		case 'e':
			elvchar = *optarg;
			break;
		case 'p':
			padchar = *optarg;
			break;
		case 'v':
			printf("dozstring v1.0\n");
			printf("Copyright (C) 2013  Donald P. Goodman III\n");
			printf("License GPLv3+:  GNU GPL version 3 or "
			"later <http://gnu.org/licenses/gpl.html>\n");
			printf("This is free software:  you are free "
			"to change and redistribute it.  There is NO "
			"WARRANTY, to the extent permitted by law.\n");
			return 0;
			break;
		case 'c':
			if (strlen(optarg) >= MAXLINE) {
				fprintf(stderr,"dozstring:  error:  requested "
				"string to convert is too long\n");
				exit(TOO_LONG);
			} else {
				convstring = optarg;
			}
			break;
		case '?':
			return BAD_OPT;
			break;
		default:
			break;
		}
	}
	i = 0;
	if (convstring != NULL) {
		int k = -1;
/*		for (j = 0; convstring[j] != '\0'; ++j) {*/
		do {
			k += 1;
			c = convstring[k];
			switch (c) {
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
			case '.':
				if ((c == '.') && (i == 0))
					printf("%c",c);
				else
					decnum[i++] = c;
				break;
			default:
				decnum[i] = '\0';
				if (c == '*') {
					printf("%s",decnum);
					if (starprint == 0)
						printf("%c",c);
					i = 0;
					continue;
				}
				if (i > 0) {
					decimal = atof(decnum);
					dectodoz(doznum,decimal);
					for (j = 0; doznum[j] != '\0'; ++j);
					if (i > j) {
						reverse(doznum);
						while (j < i)
							doznum[j++] = padchar;
						doznum[j] = '\0';
						reverse(doznum);
					} else if (j > i) {
						doznum[i-1] = '\0';
					}
					if (tenchar != 'X') {
						for (i = 0; doznum[i] != '\0'; ++i) {
							if (doznum[i] == 'X')
								doznum[i] = tenchar;
						}
					}
					if (elvchar != 'E') {
						for (i = 0; doznum[i] != '\0'; ++i) {
							if (doznum[i] == 'E')
								doznum[i] = elvchar;
						}
					}
					printf("%s",doznum);
					printf("%c",c);
					i = 0;
				} else {
					printf("%c",c);
				}
				break;
			}
		} while (convstring[k] != '\0');
		if (newline == 1)
			printf("\n");
		return 0;
	}
	while ((c = getchar()) != EOF) {
		switch (c) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		case '.':
			if ((c == '.') && (i == 0))
				printf("%c",c);
			else
				decnum[i++] = c;
			break;
		default:
			decnum[i] = '\0';
			if (c == '*') {
				printf("%s",decnum);
				if (starprint == 0)
					printf("%c",c);
				i = 0;
				continue;
			}
			if (i > 0) {
				decimal = atof(decnum);
				dectodoz(doznum,decimal);
				for (j = 0; doznum[j] != '\0'; ++j);
				if (i > j) {
					reverse(doznum);
					while (j < i)
						doznum[j++] = padchar;
					doznum[j] = '\0';
					reverse(doznum);
				} else if (j > i) {
					doznum[i-1] = '\0';
				}
				if (tenchar != 'X') {
					for (i = 0; doznum[i] != '\0'; ++i) {
						if (doznum[i] == 'X')
							doznum[i] = tenchar;
					}
				}
				if (elvchar != 'E') {
					for (i = 0; doznum[i] != '\0'; ++i) {
						if (doznum[i] == 'E')
							doznum[i] = elvchar;
					}
				}
				printf("%s",doznum);
				printf("%c",c);
				i = 0;
			} else {
				printf("%c",c);
			}
			break;
		}
	}
	if (newline == 1)
		printf("\n");
	return 0;
}

