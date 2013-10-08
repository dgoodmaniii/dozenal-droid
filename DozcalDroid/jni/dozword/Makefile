# +AMDG
# This document was begun on 7 February 2010, Sexagesima
# Sunday, and it is humbly dedicated to the Immaculate Heart
# of Mary for her prayers, and to the Sacred Heart of Jesus
# for His mercy.

dozword : dozword.c
	gcc -o dozword dozword.c

doc : dozword.1
	rman -fHTML dozword.1 > dozword_man.html

prefix = /usr/local
bindir = /usr/local/bin
mandir = /usr/local/share/man/man1

install : dozword dozword.1
	cp ./dozword $(bindir)
	cp ./dozword.1 $(mandir)

uninstall :
	rm $(bindir)/dozword
	rm $(mandir)/dozword.1
