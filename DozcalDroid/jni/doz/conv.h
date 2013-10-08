/* +AMDG */
/*
 * A header file for the conversion routines in the dozenal
 * package.  The basic conversion routines and a couple of
 * utility functions needed by both programs.
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

#define MAXLINE 1000

int doz(char *s, char *t, int places, int expnot);
double doztodec(char *s);
int dec(char *p, int places, char expnot);
void reverse(char *s);
int getword(char *s, int lim);
int isdozdig(char c);
