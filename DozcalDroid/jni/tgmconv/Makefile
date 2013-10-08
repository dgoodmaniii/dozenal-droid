# +AMDG

tgmconv : main.o doz.o dec.o tgm.o conv.h tgmconv.h conv.o
	gcc -g -lm -o tgmconv main.o tgm.o doz.o dec.o conv.o

main.o : main.c tgmconv.h dec.o doz.o conv.h conv.c
	gcc -g -c main.c

tgm.o : tgm.c tgmconv.h conv.h conv.c
	gcc -g -c tgm.c

doz.o : doz.c conv.h conv.c
	gcc -g -lm -std=c99 -c doz.c

dec.o : dec.c conv.h conv.c
	gcc -g -c dec.c

conv.o : conv.c conv.h
	gcc -g -c conv.c

doc : tgmconv.1
	rman -fHTML tgmconv.1 > tgmconv_man.html

prefix = /usr/local
bindir = /usr/local/bin
mandir = /usr/local/share/man/man1

install : tgmconv tgmconv.1
	cp ./tgmconv $(bindir)
	cp ./tgmconv.1 $(mandir)

uninstall :
	rm $(bindir)/tgmconv
	rm $(mandir)/tgmconv.1
