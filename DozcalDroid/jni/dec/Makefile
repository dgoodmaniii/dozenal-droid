# +AMDG
#
# This document was begun on 13 January 2009, the
# commemoration of the Baptism of Our Lord, and it is humbly
# dedicated to the Immaculate Heart of Mary for her prayers,
# and to the Sacred Heart of Jesus for His mercy.
#
# Makefile for the decimal to dozenal converter.

dec : main.o conv.h conv.o dec.o
	gcc -lm -o dec main.o conv.o dec.o

main.o : conv.h main.c conv.o dec.o
	gcc -c main.c

conv.o : conv.c conv.h
	gcc -c conv.c

dec.o : conv.o conv.h dec.c
	gcc -c dec.c

doc : dec.1
	rman -fHTML dec.1 > dec_man.html

prefix = /usr/local
bindir = /usr/local/bin
mandir = /usr/local/share/man/man1

install : dec dec.1
	cp ./dec $(bindir)
	cp ./dec.1 $(mandir)

uninstall :
	rm $(bindir)/dec
	rm $(mandir)/dec.1
