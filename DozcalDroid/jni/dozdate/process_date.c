/*
 * +AMDG
 */
/*
 * This document was begun on X Oct 11E7, the feast of St.
 * Francis Borgia, and it is humbly dedicated to him and to
 * the Immaculate Heart of Mary for their prayers, and to
 * the Sacred Heart of Jesus for His mercy.
 *
 */
/*
 * Parses the date strings for dozdate, if there is one.
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
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "conv.h"
#include "error_codes.h"

#define SIZE 256
#define NEITHER 0 		/* begin symm output and input vars */
#define OUT 1
#define IN 2
#define BOTH 3				/* end symm output and input vars */

/* global array of structs for days of week */
struct nameday {
	char *longname; 		/* long form */
	char *shortname;		/* abbreviation */
	int num;				/* number (0-6) */
} weekdays[] = {
	"Sunday", "Sun", 0,
	"Monday", "Mon", 1,
	"Tuesday", "Tue", 2,
	"Wednesday", "Wed", 3,
	"Thursday", "Thu", 4,
	"Friday", "Fri", 5,
	"Saturday", "Sat", 6,
};
struct monthdays {
	char *longname; char *shortname;
	int num;
} months[] = {
	"January", "Jan", 0,
	"February", "Feb", 1,
	"March", "Mar", 2,
	"April", "Apr", 3,
	"May", "May", 4,
	"June", "Jun", 5,
	"July", "Jul", 6,
	"August", "Aug", 7,
	"September", "Sep", 8,
	"October", "Oct", 9,
	"November", "Nov", 10,
	"December", "Dec", 11,
	"Irvember", "Irv", 12,
};

/* governing function, calls others */
int process_date(char *s,struct tm *thetime,int usesymm)
{
	int i,j,k;
	char *monpointer;
	int month;

	k = parse_for_year(s,thetime);
	if (k == 0) {
		thetime->tm_mon = 0;
		thetime->tm_mday = 1;
	}
	month = parse_for_alpha_month(s,thetime);
	if (month == -1)
		month = parse_for_hyphen_month(s,thetime);
	if (month == -1)
		month = parse_for_slash_month(s,thetime);
	if (month < 0)
		i = parse_for_weekday(s,thetime);
	j = parse_sexa_time(s,thetime);
	if (j == -1)
		j = parse_tgm_time(s,thetime);
	if (month == -1 && i == -1 && j == -1) {
		thetime->tm_mon = 0;
		thetime->tm_mday = 1;
	} else if (month >= 0) {
		thetime->tm_mon = month;
	}
	if ((usesymm == NEITHER) || (usesymm == OUT)) {
		thetime->tm_wday = dayofweek(thetime->tm_year+1900,
			thetime->tm_mon+1,thetime->tm_mday);
		thetime->tm_yday = ydays_from_date(thetime);
	}
	if ((usesymm == IN) || (usesymm == BOTH)) {
	} else
		errorcheck(s,thetime);
	return 0;
}

/* seeks a TGM time in the date string; if found, returns 0
 * and installs in struct; otherwise, returns -1 */
int parse_tgm_time(char *s, struct tm *thetime)
{
	int i, j;
	char *hourpoint = NULL;
	char tim[6] = "0000";

	j = 0;
	for (i=0; s[i] != '\0'; ++i)
		if (s[i] == ';')
			hourpoint = (i > 1) ? &s[i-2] : &s[i-1];
	if (hourpoint == NULL)
		return -1;
	while (*hourpoint != '\0' && *hourpoint != ';') {
		if (isdigit(*hourpoint) || *hourpoint=='X' || *hourpoint=='E')
			tim[j++] = *(hourpoint++);
		else
			++hourpoint;
		tim[j] = '\0';
	}
	thetime->tm_hour = (int)doztodec(tim);
	++hourpoint; j=0;
	while ((isdigit(*hourpoint) || *hourpoint=='X' ||
	*hourpoint=='E') && (j <= 3) && *hourpoint != '\0') {
		tim[j++] = *(hourpoint++);
		tim[j] = '\0';
	}
	if (j < 4) { /* pad with zeroes if less than four digits of Tims */
		tim[4] = '\0';
		for (j = 0; j < 4; ++j)
			if (!isdigit(tim[j]) && tim[j] != 'X' && tim[j] != 'E')
				tim[j] = '0';
	}
	thetime->tm_sec = timtosec(tim,thetime);
	return 0;
}

/* converts tims to seconds; returns seconds, installs
 * minutes into struct */
int timtosec(char *s,struct tm *thetime)
{
	double tim;
	int sec;
	int min;

	tim = doztodec(s);
	sec = round(tim *	0.1736111111111111111111111111111111111111111111);
	thetime->tm_min = (int)(sec / 60);
	sec -= (thetime->tm_min * 60);
	return sec;
}

/* parse for hyphen notation; if found, return number of the
 * month, of -1 if an error; look for date, install it in
 * struct if found, install 1 if not */
int parse_for_hyphen_month(char *s, struct tm *thetime)
{
	int i, j;
	int month = -1;
	char *monthspot = NULL; char *dayspot = NULL;
	int flag = 0;
	char monthnum[3] = "";
	char daynum[3] = "";

	j = 0;
	for (i=0; s[i] != '\0'; ++i) {
		if (s[i] == '-' && flag == 0) {
			flag = 1;
			monthspot = &s[i+1];
		} else if (s[i] == '-' && flag == 1) {
			flag = 0;
			dayspot = &s[i+1];
		}
	}
	if (monthspot != NULL) {
		while (*monthspot != '\0' && *monthspot != '-' &&
		!isspace(*monthspot) && !ispunct(*monthspot)) {
			if (isdigit(*monthspot) || *monthspot=='X' ||
			*monthspot == 'E')
				monthnum[j++] = *monthspot;
			monthnum[j] = '\0';
			++monthspot;
		}
	}
	j=0;
	if (dayspot != NULL) {
		while (*dayspot != '\0' && *dayspot != '-' &&
		!isspace(*dayspot) && !ispunct(*dayspot)) {
			if (isdigit(*dayspot) || *dayspot=='X' ||
			*dayspot == 'E')
				daynum[j++] = *dayspot;
			daynum[j] = '\0';
			++dayspot;
		}
	}
	if (monthnum[0] != '\0')
		month = (int)doztodec(monthnum) - 1;
	if (daynum[0] != '\0')
		thetime->tm_mday = (int)doztodec(daynum);
	else if (daynum[0] != '\0' && month != -1)
		thetime->tm_mday = 1;
	return month;
}

/* parse for slash notation; if found, return number of the
 * month, of -1 if an error; look for date, install it in
 * struct if found, install 1 if not */
int parse_for_slash_month(char *s, struct tm *thetime)
{
	int i; int j = 0;
	char *monthspot = NULL;
	char *dayspot = NULL;
	int month = -1;
	char monthnum[3] = "";
	char daynum[3] = "";

	for (i=0; s[i] != '\0'; ++i) {
		if (s[i] == '/') {
			monthspot = dayspot = &s[i];
			break;
		}
	}
	if (monthspot != NULL) {
		if (i > 1)
			monthspot -= 2;
		else
			monthspot -= 1;
		while (monthspot < dayspot) {
			if (isdigit(*monthspot) || *monthspot == 'X' || *monthspot == 'E')
				monthnum[j++] = *monthspot;
			++monthspot;
		}
		monthnum[j] = '\0';
	}
	if (dayspot != NULL) {
		if (*(dayspot+1) != '\0')
			++dayspot;
		j = 0;
		while (*dayspot != '/' && j <= 1) {
			if (isdigit(*dayspot) || *dayspot == 'X' || *dayspot == 'E')
				daynum[j++] = *dayspot;
			++dayspot;
		}
	}
	if (monthnum[0] != '\0')
		month = (int)doztodec(monthnum) - 1;
	if (daynum[0] != '\0')
		thetime->tm_mday = (int)doztodec(daynum);
	else if (month != -1)
		thetime->tm_mday = 1;
	return month;
}

/* parses our current sexagesimal time, if found; return 0
 * if found, -1 if not */
int parse_sexa_time(char *s, struct tm *thetime)
{
	int i,j,k;
	char hour[3] = "";
	char min[3] = "";
	char sec[3] = "";
	char *minpoint = NULL; char *secpoint = NULL;
	char *hourpoint = NULL;
	int flag = 0;

	for (i=0; s[i] != '\0'; ++i) {
		if (s[i] == ':' && flag == 0) {
			minpoint = &s[i+1];
			if (i > 1)
				hourpoint = &s[i-2];
			else
				hourpoint = &s[i-1];
			flag = 1;
		} else if (s[i] == ':' && flag == 1) {
			secpoint = &s[i+1];
			break;
		}
	}
	if (hourpoint != NULL) {
		j=0;
		while (*hourpoint != ':' && *hourpoint != '\0' && j < 2)
			if (isdigit(*hourpoint) || *hourpoint == 'X' ||
			*hourpoint == 'E')
				hour[j++] = *(hourpoint++);
			else
				++hourpoint; ++j;
		hour[j] = '\0';
		if (hour[0] != '\0')
			thetime->tm_hour = (int)doztodec(hour);
	}
	if (minpoint != NULL) {
		j=0;
		while (*minpoint != ':' && *minpoint != '\0' && j < 2)
			if ((isdigit(*minpoint) || *minpoint == 'X' ||
			*minpoint == 'E') && (j <= 1))
				min[j++] = *(minpoint++);
			else
				++minpoint; ++j;
		min[j] = '\0';
		if (min[0] != '\0')
			thetime->tm_min = (int)doztodec(min);
	}
	if (secpoint != NULL) {
		j=0;
		while (*secpoint != ':' && *secpoint != '\0' & j < 2)
			if ((isdigit(*secpoint) || *secpoint == 'X' ||
			*secpoint == 'E') && (j <= 1))
				sec[j++] = *(secpoint++);
			else
				++secpoint; ++j;
		sec[j] = '\0';
		if (sec[0] != '\0')
			thetime->tm_sec = (int)doztodec(sec);
	}
	if (hourpoint == NULL)
		thetime->tm_hour = 0;
	if (minpoint == NULL)
		thetime->tm_min = 0;
	if (secpoint == NULL)
		thetime->tm_sec = 0;
	if (hourpoint == NULL)
		return -1;
	return 0;
}

/* calculate ydays from the date; return ydays; redundant,
 * but harmless, the relative date options were used */
int ydays_from_date(struct tm *thetime)
{
	int i;
	int ydays = 0;

	switch (thetime->tm_mon) {
	case 0:  ydays += 0; break;
	case 1:  ydays += 31; break;
	case 2:  ydays += 59; break;
	case 3:  ydays += 90; break;
	case 4:  ydays += 120; break;
	case 5:  ydays += 151; break;
	case 6:  ydays += 181; break;
	case 7:  ydays += 212; break;
	case 8:  ydays += 243; break;
	case 9:  ydays += 273; break;
	case 10:  ydays += 304; break;
	case 11:  ydays += 334; break;
	default:
		fprintf(stderr, "dozdate:  error:  %d is an invalid "
		"month\n",thetime->tm_mon-1);
		exit(BAD_MONTH);
		break;
	}
	if ((leapyear(0,thetime->tm_year+1900)) && (thetime->tm_mon > 1))
		++ydays;
	return ydays + thetime->tm_mday - 1;
}

/* ensures that weekday given matches the dates, etc. */
int errorcheck(char *s, struct tm *thetime)
{
	char *weekday, *oweekday;
	char *month;
	char number[SIZE];
	int i;

	/* verify that year is an acceptable value */
	if (thetime->tm_year+1900 > 2699 || thetime->tm_year+1900 < 1700) {
		fprintf(stderr,"dozdate:  error:  year is too large; "
		"only dates between 0E98 and 168E\ncan be "
		"calculated\n");
		exit(BAD_YEAR);
	}
	/* fill some useful variables for error-checking */
	for (i=0; thetime->tm_wday != weekdays[i].num; ++i);
	weekday = weekdays[i].longname;
	oweekday = weekdays[dayofweek(thetime->tm_year+1900,
		thetime->tm_mon+1,thetime->tm_mday)].longname;
	for (i=0; thetime->tm_mon != months[i].num; ++i);
	month = months[i].longname;
	/* check for mday error */
	if ((thetime->tm_mon == 0 && thetime->tm_mday > 31) ||
	(thetime->tm_mon == 1 && thetime->tm_mday > 29) ||
	(thetime->tm_mon == 2 && thetime->tm_mday > 31) ||
	(thetime->tm_mon == 3 && thetime->tm_mday > 30) ||
	(thetime->tm_mon == 4 && thetime->tm_mday > 31) ||
	(thetime->tm_mon == 5 && thetime->tm_mday > 30) ||
	(thetime->tm_mon == 6 && thetime->tm_mday > 31) ||
	(thetime->tm_mon == 7 && thetime->tm_mday > 31) ||
	(thetime->tm_mon == 8 && thetime->tm_mday > 30) ||
	(thetime->tm_mon == 9 && thetime->tm_mday > 31) ||
	(thetime->tm_mon == 10 && thetime->tm_mday > 30) ||
	(thetime->tm_mon == 11 && thetime->tm_mday > 31)) {
		dectodoz(number,(double)thetime->tm_mday);
		fprintf(stderr,"dozdate:  error:  %s does not have "
		"%s days\n",month,number);
		exit(BAD_MDAY);
	} else if ((thetime->tm_mon == 1) && (thetime->tm_mday == 29)) {
		if (!leapyear(0,thetime->tm_year+1900)) {
			dectodoz(number,(double)thetime->tm_year+1900);
			fprintf(stderr,"dozdate:  error:  %s is not a "
			"leap year\n",number);
			exit(BAD_LEAP_YEAR);
		}
	}
	/* check for weekday error; fix if necessary */
	if (thetime->tm_wday != dayofweek(thetime->tm_year+1900,
	thetime->tm_mon+1,thetime->tm_mday)) {
		if (strstr(s,"Sun") || strstr(s,"Mon") ||
		strstr(s,"Tue") || strstr(s,"Wed") || strstr(s,"Thu")
		|| strstr(s,"Fri") || strstr(s,"Sat"))
			fprintf(stderr,"dozdate:  weekday \"%s\" does not "
			"match the date \"%d %s %d\";\nsetting to the correct "
			"weekday, \"%s\"\n",weekday,thetime->tm_mday,
			month,thetime->tm_year+1900,oweekday);
		thetime->tm_wday = dayofweek(thetime->tm_year+1900,
			thetime->tm_mon+1,thetime->tm_mday);
	}
	if (thetime->tm_hour > 23) {
		fprintf(stderr,"dozdate:  error:  hour is too "
		"large\n");
		exit(BAD_HOUR);
	}
	if (thetime->tm_min > 59) {
		fprintf(stderr,"dozdate:  error:  minute is too "
		"large\n");
		exit(BAD_MIN);
	}
	if (thetime->tm_sec > 60) {
		fprintf(stderr,"dozdate:  error:  second is too "
		"large\n");
		exit(BAD_SEC);
	}
}

/* ensures that weekday given matches the dates, etc.,
 * specifically for the symmetry calendar */
int symm_errorcheck(char *s, struct tm *thetime)
{
	char *weekday, *oweekday;
	char *month;
	char number[SIZE];
	int i;

	/* verify that year is an acceptable value */
	if (thetime->tm_year+1900 > 2699 || thetime->tm_year+1900 < 1700) {
		fprintf(stderr,"dozdate:  error:  year is too large; "
		"only dates between 0E98 and 168E\ncan be "
		"calculated\n");
		exit(BAD_YEAR);
	}
	/* fill some useful variables for error-checking */
	for (i=0; thetime->tm_wday != weekdays[i].num; ++i);
	weekday = weekdays[i].longname;
	oweekday = weekdays[dayofweek(thetime->tm_year+1900,
		thetime->tm_mon+1,thetime->tm_mday)].longname;
	for (i=0; thetime->tm_mon != months[i].num; ++i);
	month = months[i].longname;
	/* check for mday error */
	if ((thetime->tm_mon == 0 && thetime->tm_mday > 30) ||
	(thetime->tm_mon == 1 && thetime->tm_mday > 31) ||
	(thetime->tm_mon == 2 && thetime->tm_mday > 30) ||
	(thetime->tm_mon == 3 && thetime->tm_mday > 30) ||
	(thetime->tm_mon == 4 && thetime->tm_mday > 31) ||
	(thetime->tm_mon == 5 && thetime->tm_mday > 30) ||
	(thetime->tm_mon == 6 && thetime->tm_mday > 30) ||
	(thetime->tm_mon == 7 && thetime->tm_mday > 31) ||
	(thetime->tm_mon == 8 && thetime->tm_mday > 30) ||
	(thetime->tm_mon == 9 && thetime->tm_mday > 30) ||
	(thetime->tm_mon == 10 && thetime->tm_mday > 31) ||
	(thetime->tm_mon == 11 && thetime->tm_mday > 30) ||
	(thetime->tm_mon == 12 && thetime->tm_mday > 7)) {
		dectodoz(number,(double)thetime->tm_mday);
		fprintf(stderr,"dozdate:  error:  %s does not have "
		"%s days\n",month,number);
		exit(BAD_MDAY);
	} else if ((thetime->tm_mon == 1) && (thetime->tm_mday == 29)) {
		if (!leapyear(0,thetime->tm_year+1900)) {
			dectodoz(number,(double)thetime->tm_year+1900);
			fprintf(stderr,"dozdate:  error:  %s is not a "
			"leap year\n",number);
			exit(BAD_LEAP_YEAR);
		}
	}
	/* check for weekday error; fix if necessary */
	if (thetime->tm_wday != dayofweek(thetime->tm_year+1900,
	thetime->tm_mon+1,thetime->tm_mday)) {
		if (strstr(s,"Sun") || strstr(s,"Mon") ||
		strstr(s,"Tue") || strstr(s,"Wed") || strstr(s,"Thu")
		|| strstr(s,"Fri") || strstr(s,"Sat"))
			fprintf(stderr,"dozdate:  weekday \"%s\" does not "
			"match the date \"%d %s %d\";\nsetting to the correct "
			"weekday, \"%s\"\n",weekday,thetime->tm_mday,
			month,thetime->tm_year+1900,oweekday);
		thetime->tm_wday = dayofweek(thetime->tm_year+1900,
			thetime->tm_mon+1,thetime->tm_mday);
	}
	if (thetime->tm_hour > 23) {
		fprintf(stderr,"dozdate:  error:  hour is too "
		"large\n");
		exit(BAD_HOUR);
	}
	if (thetime->tm_min > 59) {
		fprintf(stderr,"dozdate:  error:  minute is too "
		"large\n");
		exit(BAD_MIN);
	}
	if (thetime->tm_sec > 60) {
		fprintf(stderr,"dozdate:  error:  second is too "
		"large\n");
		exit(BAD_SEC);
	}
}

/* find a four-digit number; if doesn't start with ;,
 * assume it's the year, even if leading zeroes; return 0 if
 * found, -1 if not */
int parse_for_year(char *s, struct tm *thetime)
{
	int i, j;
	char yearnum[7] = "";
	int year = 0;
	size_t len;

	len = strlen(s);
	for (i=0; s[i] != '\0'; ++i) {
		j=0;
		yearnum[j++] = (i > 0) ? s[i-1] : '0';
		while ((isdigit(s[i]) || s[i]=='X' || s[i] == 'E') && i <= len) {
			yearnum[j++] = s[i++];
		}
		yearnum[j] = '\0';
		if ((j == 5) && (yearnum[0] != ';' && yearnum[0] != ':')) {
			memmove(yearnum,yearnum+1,5);
			year = (int)doztodec(yearnum);
		} else {
			yearnum[0] = '\0';
		}
	}
	if (year != 0) {
		thetime->tm_year = year - 1900;
		return 0;
	}
	return -1;
}

/* looks for alpha month; returns month number if found, -1
 * if not; then seek date, install in thetime */
int parse_for_alpha_month(char *s, struct tm *thetime)
{
	int i, j; int month = -1;
	char *monthspot; char *copy;
	char datenum[5] = "";

	for (i=0; i <= 12; ++i)
		if ((monthspot = strstr(s,months[i].longname)) ||
		(monthspot = strstr(s,months[i].shortname))) {
			month = months[i].num;
			break;
		}
	copy = monthspot;
	if (month < 0)
		return month;
	j = 0;
	while (copy >= s) {
		if ((isdigit(*copy) || *copy == 'X' || *copy == 'E') && (j <= 1))
			datenum[j++] = *copy;
		if (ispunct(*copy))
			break;
		--copy;
	}
	datenum[j] = '\0';
	if (datenum[0] != '\0')
		reverse(datenum);
	if (datenum[0] == '\0') {
		copy = monthspot;
		j = 0;
		while (*copy != '\0' && *copy != ',') {
			if ((isdigit(*copy) || *copy == 'X' || *copy == 'E') && (j <= 1))
				datenum[j++] = *copy;
			++copy;
		}
		datenum[j] = '\0';
		if (!isspace(*copy) && !ispunct(*copy))
			datenum[0] = '\0';
	}
	if (datenum[0] == '\0')
		thetime->tm_mday = 1;
	else
		thetime->tm_mday = (int)doztodec(datenum);
	return month;
}

/* parses string for weekdays and related modifiers; if
 * weekday on its own, assume "this coming"; if "last", then
 * the week prior */
int parse_for_weekday(char *s, struct tm *thetime)
{
	int tmp, tmp2, i;
	int dayyear, maxdays;
	char *daypoint = NULL; /* point at weekday in s */
	char *lastpoint; /* if "last" or "next" is in string */

	tmp = thetime->tm_wday;	 /* tmp:  current weekday num */
	for (i=0; i <= 6; ++i) {
		if ((daypoint = strstr(s,weekdays[i].longname)) || 
		(daypoint = strstr(s,weekdays[i].shortname))) {
			tmp2 = weekdays[i].num;  /* tmp2:  new weekday num */
			break;
		}
	}
	if (daypoint == NULL)
		return -1;
	thetime->tm_wday = tmp2; /* new weekday into struct */
	if ((lastpoint = strstr(s,"last")) && (lastpoint <
	daypoint) && (lastpoint != NULL)) {
		if (tmp2 < tmp)
			dayyear = tmp2 - tmp;
		else
			dayyear = (7 - (abs(tmp - tmp2))) * -1;
		if (dayyear < 0) {
			thetime->tm_year -= 1;
			dayyear += (leapyear(thetime->tm_year+1900)) ? 366	: 367;
			thetime->tm_mon = 0;
		}
	} else {
		tmp2 = (tmp2 == 0) ? 7 : tmp2;
		if (tmp2 > tmp)
			dayyear = abs(tmp - tmp2);
		else
			dayyear = (7 - (abs(tmp - tmp2)));
		if ((lastpoint = strstr(s,"next")) && (lastpoint <
		daypoint) && (lastpoint != NULL))
			dayyear += 7;
	}
	maxdays = (leapyear(0,thetime->tm_year+1900)) ? 365 : 364;
	if (!leapyear(0,thetime->tm_year+1900))
		dayyear -= 1;
	dayyear += thetime->tm_yday;
/*	printf("MAXDAYS:  %d; DAYYEAR:  %d\n",maxdays,dayyear);*/
	if ((dayyear > (maxdays+1))) {
		dayyear -= maxdays;
		dayyear -= 3;
		thetime->tm_year += 1;
	}
	thetime->tm_yday = dayyear; /* put yday into struct */
	date_from_ydays(dayyear,thetime);
	return 0;
}

/* compute date from the number of days since Jan 1 */
int date_from_ydays(int dayyear, struct tm *thetime)
{
	int i, j;
	int month = 0;
	int day = 0;

	j = (leapyear(0,thetime->tm_year+1900)) ? 0 : 1;
	for (i=0; i <= dayyear+j; ++i)
		switch (i) {
			case 31: ++month; day = i; break;
			case 60: ++month; day = i; break;
			case 91: ++month;	day = i; break;
			case 121: ++month; day = i; break;
			case 152: ++month; day = i; break;
			case 182: ++month; day = i; break;
			case 213: ++month; day = i; break;
			case 244: ++month; day = i; break;
			case 274: ++month; day = i; break;
			case 305: ++month; day = i; break;
			case 335: ++month; day = i; break;
		}
	thetime->tm_mon = month;
	if (leapyear(0,thetime->tm_year+1900))
		day = dayyear - day + 0;
	else
		day = dayyear - day + 2;
	thetime->tm_mday = day;
	return 0;
}

/* calculate day of week */
int dayofweek(int year, int month, int day)
{
	struct centtab {
		int twocent;
		int firstday;
	} centuries[] = {
		17, 4,
		18, 2,
		19, 0,
		20, 6,
		21, 4,
		22, 2,
		23, 0,
		24, 6,
		25, 4,
		26, 2,
	};
	int theweekday = 0;		/* the answer */
	int thefirstday = 0;		/* the first day of the year */
	int tmp, cent;
	int i;

	if ((year >= 2600) || (year <= 1700)) {
		fprintf(stderr,"dozdate:  error:  year is too large; "
		"only dates between 0E98 and 168E\ncan be "
		"calculated\n");
		exit(BAD_YEAR);
	}
	cent = (int)year / 100;
	year = year - (cent * 100);
	for (i=0; centuries[i].twocent != cent; ++i);
	thefirstday = centuries[i].firstday;
	theweekday = (int)year / 4;
	switch (month) {
		case 1:
			if (leapyear(cent,year) == 1)
				theweekday = theweekday + thefirstday + year + 6;
			else
				theweekday = theweekday + thefirstday + year + 0;
			break;
		case 2:
			if (leapyear(cent,year) == 1)
				theweekday = theweekday + thefirstday + year + 2;
			else
				theweekday = theweekday + thefirstday + year + 3;
			break;
		case 3:
			theweekday = theweekday + thefirstday + year + 3; break;
		case 4:
			theweekday = theweekday + thefirstday + year + 6; break;
		case 5:
			theweekday = theweekday + thefirstday + year + 1; break;
		case 6:
			theweekday = theweekday + thefirstday + year + 4; break;
		case 7:
			theweekday = theweekday + thefirstday + year + 6; break;
		case 8:
			theweekday = theweekday + thefirstday + year + 2; break;
		case 9:
			theweekday = theweekday + thefirstday + year + 5; break;
		case 10:
			theweekday = theweekday + thefirstday + year + 0; break;
		case 11:
			theweekday = theweekday + thefirstday + year + 3; break;
		case 12:
			theweekday = theweekday + thefirstday + year + 5; break;
		default:
			fprintf(stderr,"dozdate:  error:  invalid month\n");
			exit(BAD_MONTH);
	}
	theweekday += day;
	theweekday %= 7;
	return theweekday;
}

/* determine if it's a leap year; return 1 if yes */
int leapyear(int cent, int year)
{
	cent *= 100;
	year += cent;
	if ((year % 4 == 0) && (year % 100 != 0))
		return 1;
	else if (year % 400 == 0)
		return 1;
	else
		return 0;
}

int printdate(struct tm *thetime)
{
	char *daystring;
	char *monthstring;
	int i;

	for (i=0; i <= 6; ++i)
		if (weekdays[i].num == thetime->tm_wday)
			daystring = weekdays[i].longname;
	for (i=0; i <= 11; ++i)
		if (months[i].num == thetime->tm_mon)
			monthstring = months[i].longname;
	printf("%s, %d %s %d\n",daystring,thetime->tm_mday,monthstring, 
		thetime->tm_year+1900);
}
