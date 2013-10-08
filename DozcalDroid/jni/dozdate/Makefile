# +AMDG
#
# This document was begun on 13 January 2009, the
# commemoration of the Baptism of Our Lord, and it is humbly
# dedicated to the Immaculate Heart of Mary for her prayers,
# and to the Sacred Heart of Jesus for His mercy.
#
# Makefile for the decimal to dozenal converter.

dozdate: main.o conv.h conv.o doz.o dec.o
	gcc -std=c99 -g -lm -o dozdate main.o conv.o doz.o dec.o process_date.o get_symmdate.o

main.o : conv.h main.c conv.o doz.o process_date.o process_date.h get_symmdate.h get_symmdate.o
	gcc -g -lm -c main.c

get_symmdate.o : get_symmdate.c conv.o get_symmdate.h
	gcc -g -lm -c get_symmdate.c

process_date.o : process_date.c conv.o process_date.h
	gcc -g -lm -c process_date.c conv.o

doz.o : conv.o conv.h doz.c
	gcc -g -std=c99 -lm -c doz.c

dec.o : conv.o conv.h dec.c
	gcc -g -c dec.c

conv.o : conv.c conv.h
	gcc -g -lm -c conv.c

doc : dozdate.1
	rman -fHTML dozdate.1 > dozdate_man.html

prefix = /usr/local
bindir = /usr/local/bin
mandir = /usr/local/share/man/man1

install : dozdate.1
	cp ./dozdate $(bindir)
	cp ./dozdate.1 $(mandir)

uninstall :
	rm $(bindir)/dozdate
	rm $(mandir)/dozdate.1
