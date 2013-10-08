/* +AMDG */
/*
 * +AMDG  This document is humbly dedicated to the
 * Immaculate Heart of Mary for her prayers and to the
 * Sacred Heart of Jesus for His mercy.
 *
 */
/*
 * dozdate:  parses either the current date or a
 * user-specified date and outputs it in dozenal format,
 * either conventional or TGM.
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

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "conv.h"
#include "process_date.h"
#include "error_codes.h"
#include "get_symmdate.h"

#define SIZE 256
#define MAXNUM 1000
#define NEITHER 0 		/* begin symm output and input vars */
#define OUT 1
#define IN 2
#define BOTH 3				/* end symm output and input vars */

int padding(char *s, int numpad, char charpad);

int main(int argc, char *argv[])
{
	char c; int i;
	int opterr = 0;
	char *date = NULL; char *format = NULL;
	char buffer[MAXNUM];
	char buffer2[MAXNUM];
	char dateline[MAXNUM];
	struct tm *thetime;
	time_t curtime;
	int needfreef = 0;
	int fileflag = 0;
	int uflag = 0;
	int usesymm = NEITHER;
	int oldusesymm;
	FILE *fp;
	
	curtime = time(NULL);
	thetime = localtime(&curtime);

	while ((c = getopt(argc,argv,"vsSYuRcd:f:")) != -1) {
		switch (c) {
		case 'u':
			thetime = gmtime(&curtime);
			uflag = 1;
			break;
		case 'd':
			date = optarg;
			process_date(date,thetime,usesymm);
			get_symmdate(thetime,&usesymm);
			break;
		case 'f':
			if ((fp = fopen(optarg,"r")) == NULL) {
				fprintf(stderr,"dozdate:  error:  can't open "
				"file %s\n",optarg);
				exit(BAD_FILE);
			}
			fileflag = 1;
			break;
		case 'v':
			printf("dozdate v2.5\n");
			printf("Copyright (C) 2011  Donald P. Goodman III\n");
			printf("License GPLv3+:  GNU GPL version 3 or "
			"later <http://gnu.org/licenses/gpl.html>\n");
			printf("This is free software:  you are free "
			"to change and redistribute it.  There is NO "
			"WARRANTY, to the extent permitted by law.\n");
			return 0;
			break;
		case 'R':
			if ((format = malloc(sizeof(char)*20)) == NULL) {
				fprintf(stderr,"dozdate:  error:  insufficient memory\n");
				exit(INSUFF_MEM);
			}
			needfreef = 1;
			strcpy(format,"%a, %d %b %Y %T %z");
			break;
		case 'c': /* --rfc-3339 */
			if ((format = malloc(sizeof(char)*20)) == NULL) {
				fprintf(stderr,"dozdate:  error:  insufficient memory\n");
				exit(INSUFF_MEM);
			}
			needfreef = 1;
			strcpy(format,"%Y-%m-%d %T%z");
			break;
		case 's': /* use Symmetry 676 for output */
			if (usesymm == NEITHER)
				usesymm = OUT;
			else if (usesymm == IN)
				usesymm = BOTH;
			break;
		case 'S': /* use Symmetry 676 for input */
			if (usesymm == NEITHER)
				usesymm = IN;
			else if (usesymm == OUT)
				usesymm = BOTH;
			break;
		case 'Y': /* input and output Symm676 */
			usesymm = BOTH;
			break;
		case '?':
			return 1;
			break;
		default:
			break;
		}
	}
	if (argv[optind] != NULL && format == NULL)
		format = argv[optind];
	else if (needfreef == 0) {
		if ((format = malloc(sizeof(char)*3)) == NULL) {
			fprintf(stderr,"dozdate:  error:  insufficient memory\n");
			exit(INSUFF_MEM);
		}
		needfreef = 1;
		*format = '@'; *(format+1) = 'c'; *(format+2) = '\0';
	}
	if ((usesymm != NEITHER) && (date == NULL)) {
		oldusesymm = usesymm;
		get_symmdate(thetime,&usesymm);
		usesymm = oldusesymm;
	}
	strcpy(buffer,format);
	strcpy(buffer2,format);
	if (fileflag == 0) {
		tgmify(buffer,thetime);
		breakup(buffer,thetime,usesymm);
		if (thetime->tm_yday > 31)
			dectoirv(buffer,thetime);
		if ((usesymm == NEITHER) || (usesymm == IN)) {
			irvtojan(buffer,thetime);
		}
		printf("%s\n",buffer);
	} else {
		i = 0;
		while ((c = getc(fp)) != EOF) {
			oldusesymm = usesymm;
			dateline[i++] = c;
			if (dateline[i-1] == '\n') {
				dateline[i] = '\0';
				strcpy(buffer,buffer2);
				process_date(dateline,thetime,usesymm);
				get_symmdate(thetime,&usesymm);
				tgmify(buffer,thetime);
				breakup(buffer,thetime,usesymm);
				if (thetime->tm_yday > 31)
					dectoirv(buffer,thetime);
				if ((usesymm == NEITHER) || (usesymm == IN))
					irvtojan(buffer,thetime);
				printf("%s\n",buffer);
				usesymm = oldusesymm;
				if (uflag == 1)
					if ((usesymm == IN) || (usesymm == BOTH))
					thetime = gmtime(&curtime);
				else
					thetime = localtime(&curtime);
				i = 0;
			}
		}
		fclose(fp);
	}
	if (needfreef == 1)
		free(format);
	return 0;
}

/* after TGM units have been handled, takes out the regular
 * date units and handles them one by one */
int breakup(char *s, struct tm *thetime, int usesymm)
{
	int i, j, k;
	char tmp[SIZE];
	char tmp2[SIZE];

	for (i=0; s[i] != '\0'; ++i) {
		if (s[i] == '%') {
			k = i;
			for (j=0; !isalpha(s[i]); ++j, ++i)
				tmp[j] = s[i];
			tmp[j++] = s[i];
			tmp[j] = '\0';
			if ((tmp[j-1] == 'b') && (thetime->tm_yday >= 364)
				&& ((usesymm == OUT) || (usesymm == BOTH))) {
				thetime->tm_mon = 0;
			}
			strftime(tmp2,SIZE,tmp,thetime);
			tokenize(tmp2);
			dateinsert(s,tmp2,j-1);
		}
	}
	return 0;
}

/* inserts the normal date conversion (%alpha) into the
 * final string */
dateinsert(char *s, char *t, int pos)
{
	int i;
	size_t len, len2;

	len = strlen(t);
	len2 = strlen(s);
	for (i=0; s[i] != '%'; ++i);
	memmove(s+i+len-pos,s+i+1,len2-i);
	memcpy(s+i,t,len);

	return 0;
}

/* tokenizes and converts the results of %alpha commands and
 * sends them back to caller */
int tokenize(char *s)
{
	char *tok = NULL;
	int i; int j = 0;
	char *tokchars = " ,.:;\t\n\'\"/!#$%^&*()%";
	char number[MAXNUM];
	char num[MAXNUM];

	strcpy(num,s);
	tok = strtok(num,tokchars);
	while (tok != NULL) {
		for (i=0; *(tok+i) != '\0'; ++i)
			number[i] = *(tok+i);
		number[i] = '\0';
		for (i=0; number[i] == '0'; ++i);
		if (isdigit(number[i]))
			dectodoz(number+i,(double) atoi(number));
		convert(number,s,tok);
		number[0] = '\0';
		tok = strtok(NULL,tokchars);
	}
	return 0;
}

/* does the actual converting of each token processed by
 * tokenize() */
int convert(char *number, char *theans, char *tok)
{
	int i,j;
	size_t len1, len2;
	char *spot;
	int newspot;

	len1 = strlen(tok);
	len2 = strlen(number);
	spot = strstr(theans,tok);
	newspot = theans - spot;
	if (len1 > len2) {
		memmove(number+(len1-len2),number,len2+1);
		for(i=0; i<(len1-len2); ++i)
			number[i] = '0'; /* FIXME:  Sometimes should be space */
		len2 = strlen(number);
	}
	memcpy(spot,number,len2);
	return 0;
}

/* converts seconds to Tims */
int sectotim(char *s, struct tm *thetime)
{
	int tim;
	char tmp[SIZE];
	char tmp2[SIZE];
	int minutes;
	int seconds;

	strftime(tmp,SIZE,"%S",thetime);
	strftime(tmp2,SIZE,"%M",thetime);
	minutes = atoi(tmp2) * 60;
	seconds = atoi(tmp);
	tim = (minutes + seconds) * 5.76;
	dectodoz(s,(double)tim);
	return 0;
}

/* handles the TGM conversion characters (@alpha); converts
 * them to TGM; calls tgminsert to stick them into the
 * string */
int tgmify(char *s, struct tm *thetime)
{
	int i,j,k;
	char tmp[SIZE];
	char tmp2[SIZE];
	size_t len;
	int numpad = 0;
	char charpad = '0';

	len = strlen(s);
	for (i=0; s[i] != '\0'; ++i) {
		if (s[i] == '@') {
/*			for (j=i; !isalpha(s[j]) && (j-i) <= 4; ++j) {*/
			for (j=i; (isdigit(s[j]) || ispunct(s[j]) || s[j] ==
			'X' || s[j] == 'E') && (j-i) <= 4; ++j) {
				if (isdigit(s[j]) || s[j] == 'X' || s[j] == 'E') {
					for (j=j,k=0; isdigit(s[j]) || s[j] == 'X' ||
					s[j] == 'E'; ++j,++k)
						tmp[k] = s[j];
					tmp[k] = '\0';
					numpad = (int)doztodec(tmp);
					--j;
				} else if ((ispunct(s[j]) || s[j] == '0') && s[j] != '@') {
					charpad = s[j];
				}
			}
			switch (s[j]) {
			case 'c': /* time:  day date mon year hours Tims */
				if (thetime->tm_mon == 12)
					thetime->tm_mon = 0;
				strftime(tmp,SIZE,"%a %d %b %Y ",thetime);
				tokenize(tmp);
				strftime(tmp2,SIZE,"%H",thetime);
				tokenize(tmp2);
				padding(tmp2,numpad,charpad);
				strcat(tmp,tmp2);
				strcat(tmp,";@t");
				strftime(tmp2,SIZE," %Z",thetime);
				strcat(tmp,tmp2);
				padding(tmp,numpad,charpad);
				tgminsert(s,tmp,j-i);
				break;
			case 'Y': /* dozenal year */
				strftime(tmp,SIZE,"%Y",thetime);
				tokenize(tmp);
				padding(tmp,numpad,charpad);
				tgminsert(s,tmp,j-i);
				break;
			case 'C': /* zentury without year */
				strftime(tmp,SIZE,"%Y",thetime);
				tokenize(tmp);
				tmp[2] = '\0';
				padding(tmp,numpad,charpad);
				tgminsert(s,tmp,j-i);
				break;
			case 'y': /* year without zentury */
				strftime(tmp,SIZE,"%Y",thetime);
				tokenize(tmp);
				reverse(tmp);
				tmp[2] = '\0';
				reverse(tmp);
				padding(tmp,numpad,charpad);
				tgminsert(s,tmp,j-i);
				break;
			case 't': /* number of Tims since last hour */
				sectotim(tmp,thetime);
				len = strlen(tmp);
				if (numpad == 0) {
					numpad = 4;
					charpad = '0';
				}
				padding(tmp,numpad,charpad);
				tgminsert(s,tmp,j-i);
				break;
			case 'm': /* number of quaduaTims, to two places */
				sectotim(tmp,thetime);
				padding(tmp,4,'0');
				tmp[2] = '\0';
				if (numpad == 0) {
					numpad = 2;
					charpad = '0';
				}
				padding(tmp,numpad,charpad);
				tgminsert(s,tmp,j-i);
				break;
			case 'H': /* hours; 00--1E */
				strftime(tmp,SIZE,"%H",thetime);
				tokenize(tmp);
				padding(tmp,numpad,charpad);
				tgminsert(s,tmp,j-i);
				break;
			case 'k': /* hours:  0-1E */
				strftime(tmp,SIZE,"%H",thetime);
				dectodoz(tmp,(double)atoi(tmp));
				padding(tmp,numpad,charpad);
				tgminsert(s,tmp,j-i);
				break;
			case 'T': /* time:  hours;Tims  "long time" */
				strftime(tmp,SIZE,"%H",thetime);
				tokenize(tmp);
				padding(tmp,numpad,charpad);
				strcat(tmp,";@t");
				tgminsert(s,tmp,j-i);
				break;
			case 's': /* "short time":  hours;Tims to 2 place */
				strftime(tmp,SIZE,"%H",thetime);
				tokenize(tmp);
				padding(tmp,numpad,charpad);
				strcat(tmp,";@m");
				tgminsert(s,tmp,j-i);
				break;
			default:
				fprintf(stderr,"dozdate:  no valid TGM "
				"conversion unit found\n");
				exit(BAD_CONV_CODE);
				break;
			}
			numpad = 0;
			charpad = '0';
		}
	}
	return 0;
}

/* processes the padding for the units; takes the string
 * containing the result, the total number of characters,
 * and the character with which the string should be padded */
int padding(char *s, int numpad, char charpad)
{
	int i,j;
	size_t len;

	if (numpad == 0)
		return 0;
	if (charpad == '[')
		charpad = ' ';
	len = strlen(s);
	j = numpad - len;
	if (j > 0) {
		memmove(s+j,s,len+1);
		for (i=0; i<j; ++i)
			s[i] = charpad;
	}
	return 0;
}

/* inserts the TGM results into the string */
int tgminsert(char *full, char *insert, int inspoint)
{
	size_t len, lenfull;
	int i, j;

	len = strlen(insert);
	lenfull = strlen(full);
	for (i=0; full[i] != '@'; ++i);
	memmove(full+i+len-inspoint,full+i+1,lenfull+1);
	memcpy(full+i,insert,len);
	return 0;
}

/* replace December with Irvember if month == 10 */
int dectoirv(char *buffer,struct tm *thetime)
{
	char *monthstart;

	if (monthstart = strstr(buffer,"January")) {
		memmove(monthstart+1,monthstart,strlen(monthstart)+1);
		*monthstart = 'I';
		*(monthstart+1) = 'r';
		*(monthstart+2) = 'v';
		*(monthstart+3) = 'e';
		*(monthstart+4) = 'm';
		*(monthstart+5) = 'b';
		*(monthstart+6) = 'e';
		*(monthstart+7) = 'r';
	} else if (monthstart = strstr(buffer,"Jan")) {
		*monthstart = 'I';
		*(monthstart+1) = 'r';
		*(monthstart+2) = 'v';
	}
	thetime->tm_mon = 12;
	return 0;
}

/* replace Irvember with January if needed */
int irvtojan(char *buffer,struct tm *thetime)
{
	char *monthstart;

	if (monthstart = strstr(buffer,"Irvember")) {
		memmove(monthstart,monthstart+1,strlen(monthstart)+1);
		*monthstart = 'J';
		*(monthstart+1) = 'a';
		*(monthstart+2) = 'n';
		*(monthstart+3) = 'u';
		*(monthstart+4) = 'a';
		*(monthstart+5) = 'r';
		*(monthstart+6) = 'y';
	} else if (monthstart = strstr(buffer,"Irv")) {
		*monthstart = 'J';
		*(monthstart+1) = 'a';
		*(monthstart+2) = 'n';
	}
	return 0;
}
