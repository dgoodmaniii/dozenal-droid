/*
 * +AMDG
 */
/*
 * This document was begun on 12 Oct 11E7, the feast of St.
 * Callistus, Pope and Martyr; and it is humbly dedicated to
 * him and to the Immaculate Heart of Mary for their
 * prayers, and to the Sacred Heart of Jesus for His mercy.
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

/* define error codes */

#define BAD_MDAY 1 /* stated month doesn't have that many days */
#define BAD_LEAP_YEAR 2 /* gave leap year, but it isn't one */
#define BAD_MONTH 3 /* invalid month given */
#define BAD_CONV_CODE 4 /* used an unrecognized conversion code */
#define INSUFF_MEM 5 /* insufficient memory for format string */
#define BAD_FILE 6 /* can't open requested file */
#define BAD_HOUR 7 /* hour isn't a sensible number */
#define BAD_MIN 8 /* minute isn't a sensible number */
#define BAD_SEC 9 /* minute isn't a sensible number */
#define BAD_YEAR 10 /* year is too large or too small */
