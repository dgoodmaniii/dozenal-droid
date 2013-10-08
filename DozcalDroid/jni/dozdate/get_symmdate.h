/*
 * +AMDG
 * This document was begun on 18 Aug 11E8, the feast of St.
 * Bernard, and it is humbly dedicated to him to the
 * Immaculate Heart of Mary, for their prayers, and to the
 * Sacred Heart of Jesus for His mercy.
 *
*/
/*
 * Gets Julian date and converts to Symm676.
 *
 * (C) Copyright 2012  Donald P. Goodman III
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

long get_judate(struct tm *thetime);
long symnewyear(int symyear);
long get_judate(struct tm *thetime);
long symnewyear(int symyear);
int fixed_to_symyear(long judate,long *firstday);
int issymleapyear(int symyear);
int daysbfmonth(int symmonth);
int convtosym(struct tm *thetime, long judate, int symyear, int firstday);
int symm_errcheck(struct tm *thetime);
