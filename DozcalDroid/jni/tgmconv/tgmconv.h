/* +AMDG */
/*
 * This document was begun on 18 Jan 2010, the commemoration
 * of St. Prisca, virgin and martyr; and it is humbly
 * dedicated to her and to the Immaculate Heart of Mary for
 * their prayers, and to the Sacred Heart of Jesus, for His
 * mercy.
 */
/*
 * The library routines, especially the main structures, for
 * the dozenal measurement conversion program.
 *
 * (C) Copyright 2010, 2011  Donald P. Goodman III
 *
 * This file is part of tgmconv.
 *
 * tgmconv is free software:  you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any
 * later version.
 *
 * tgmconv is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with tgmconv.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

/* once we've got the units and the value, converts it,
 * returns the answer as double */
double getanswer(char *to, char *from, double value);
/* deal with compound units */
double parse(char *s);
/* by Lars Wirzenius at stackoverflow.com; public domain */
char *strrstr(char *s, char *t);
