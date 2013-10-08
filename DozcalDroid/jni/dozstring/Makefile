# +AMDG
# This document was begun on 26 January 11E9, the feast of
# St. Martina, Virgin and Martyr; and it is humbly dedicated
# her and to the Immaculate Heart of Mary for their prayers,
# and to the Sacred Heart of Jesus for His mercy.

dozstring : main.o conv.h conv.o doz.o dec.o
	gcc -g -lm main.o conv.o doz.o dec.o -o dozstring

main.o : main.c conv.h conv.o doz.o dec.o
	gcc -g -c main.c

doz.o : conv.c conv.h doz.c dec.o
	gcc -lm -std=c99 -g -c doz.c

dec.o : conv.o conv.h dec.c
	gcc -g -c dec.c

conv.o : conv.c conv.h
	gcc -g -c conv.c

doc : dozstring.1
	rman -fHTML dozstring.1 > dozstring_man.html

prefix = /usr/local
bindir = /usr/local/bin
mandir = /usr/local/share/man/man1

install : dozstring dozstring.1
	cp ./dozstring $(bindir)
	cp ./dozstring.1 $(mandir)

uninstall :
	rm $(bindir)/dozstring
	rm $(mandir)/dozstring.1
