/* +AMDG */
/*
 * This document was begun on 13 January 2010, the
 * commemoration of the Baptism of Our Lord, and it is
 * humbly dedicated to the Immaculate Heart of Mary for her
 * prayers, and to the Sacred Heart of Jesus, for His mercy.
 */
/*
 * The main function for the decimal-to-dozenal convert.
 *
 * (C) Copyright 2010, 2011  Donald P. Goodman III
 *
 * This file is part of doz.
 *
 * doz is free software:  you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any
 * later version.
 *
 * doz is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with doz.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>
#include<float.h>
#include "conv.h"

int main(int argc, char *argv[])
{
	int c;
	int i = 0;
	char doznum[MAXLINE];
	int places = 4; /* post-zenimal digits of accuracy */
	char expnot = 0; /* exponential notation flag; default no */

	while (--argc > 0 && (*++argv)[0] == '-') {
		if (isdigit(argv[0][1]) || argv[0][1] == '.')
			break; /* negative numbers are not optional args */
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
			case 'v':
				printf("doz v3.0\n");
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
		doz(doznum,*argv,places,expnot);
		return 0;
	}
	while (getword(doznum,MAXLINE) != EOF)
		doz(doznum,doznum,places,expnot);
	return 0;
}
