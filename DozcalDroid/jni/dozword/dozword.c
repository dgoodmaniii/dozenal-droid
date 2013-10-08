/*
 * +AMDG  This program was begun on 14 November 2008, the
 * feast of St. Josaphat, and it is humbly dedicated to him
 * and to the Immaculate Heart of Mary for their prayers,
 * and to the Sacred Heart of Jesus for His mercy.
 *
 * dozword:  inputs a dozenal number and outputs a verbal
 * representation thereof, according to TGM's
 * specifications.
 *
 * (C) Copyright 2010, 2011  Donald P. Goodman III
 *
 * This file is part of dozword.
 *
 * dozword is free software:  you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any
 * later version.
 *
 * dozword is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with dozword.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <string.h>

char error(int argc);
char printwords(char *number);
char printnumword(char *number, char first);
char printexp(int currplace);

/* check for errors, send number to word function, quit */

int main(int argc, char *argv[])
{
	if (error(argc))
		return 1; 
	
	*argv++;
	if (strcmp(*argv,"-v") == 0) {
		printf("dozword v3.0\n");
		printf("Copyright (C) 2010, 2011  Donald P. Goodman III\n");
		printf("License GPLv3+:  GNU GPL version 3 or "
		"later <http://gnu.org/licenses/gpl.html>\n");
		printf("This is free software:  you are free "
		"to change and redistribute it.  There is NO "
		"WARRANTY, to the extent permitted by law.\n");
		return 0;
	}
	printwords(*argv);
	printf("\n");

	return 0;
}

/* check for errors in input */

char error(int argc)
{
	if (argc < 2) {
		printf("Usage:  dozword <dozenal number>\n");
		return 1;
	} else if (argc > 2) {
		printf("Too many arguments.  Usage:  dozword <dozenal number>\n");
		return 1;
	} else {
		return 0; }
}

/* prints the number word */

char printnumword(char *number, char first)
{
	if (*number == '0')
		;
	else if (*number == '1')
		printf("%cne",(first) ? 'O' : 'o' );
	else if (*number == '2')
		printf("%cwo",(first) ? 'T' : 't' );
	else if (*number == '3')
		printf("%chree",(first) ? 'T' : 't' );
	else if (*number == '4')
		printf("%cour",(first) ? 'F' : 'f' );
	else if (*number == '5')
		printf("%cive",(first) ? 'F' : 'f' );
	else if (*number == '6')
		printf("%cix",(first) ? 'S' : 's' );
	else if (*number == '7')
		printf("%ceven",(first) ? 'S' : 's' );
	else if (*number == '8')
		printf("%cight",(first) ? 'E' : 'e' );
	else if (*number == '9')
		printf("%cine",(first) ? 'N' : 'n' );
	else if (*number == 'X')
		printf("%cen",(first) ? 'T' : 't' );
	else if (*number == 'E')
		printf("%clv",(first) ? 'E' : 'e' );
	return 0;
}

/* prints the exponent level appropriate for current number */

char printexp(int currplace)
{
	if (currplace == 2)
		printf("zen ");
	else if (currplace == 3)
		printf("duna ");
	else if (currplace == 4)
		printf("trina ");
	else if (currplace == 5)
		printf("quedra ");
	else if (currplace == 6)
		printf("quen ");
	else if (currplace == 7)
		printf("hes ");
	else if (currplace == 8)
		printf("sev ");
	else if (currplace == 9)
		printf("ak ");
	else if (currplace == 10)
		printf("neen ");
	else if (currplace == 11)
		printf("dex ");
	else if (currplace == 12)
		printf("lef ");
	else if (currplace == 13)
		printf("zennil ");
	else if (currplace == 14)
		printf("zenzen ");
	else if (currplace == 15)
		printf("zenduna ");
	return 0;
}

/* print the words for the number */

char printwords(char *number)
{
	int maxlength, numlength;
	int i;
	char first = 1;

	for (i=0; number[i] != ';' && number[i] != '\0'; ++i);
	maxlength = numlength = i;
	for (i=0; i <= maxlength; i++) {
		printnumword(number+i,first);
		first = 0;
		printexp(numlength);
		--numlength;
	}
}
