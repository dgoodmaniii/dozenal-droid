# +AMDG  This testing document was begun on 10 Oct 11E7, a
# feria, and it is humbly dedicated to the Immaculate Heart
# of Mary, for her prayers, and to the Sacred Heart of
# Jesus, for His mercy.

echo "last Sun:  `./dozdate -d\"last Sun\"`";
echo "last Mon:  `./dozdate -d\"last Mon\"`";
echo "last Tue:  `./dozdate -d\"last Tue\"`";
echo "last Wed:  `./dozdate -d\"last Wed\"`";
echo "last Thu:  `./dozdate -d\"last Thu\"`";
echo "last Fri:  `./dozdate -d\"last Fri\"`";
echo "last Sat:  `./dozdate -d\"last Sat\"`";

echo "Sun:  `./dozdate -d\"Sun\"`";
echo "Mon:  `./dozdate -d\"Mon\"`";
echo "Tue:  `./dozdate -d\"Tue\"`";
echo "Wed:  `./dozdate -d\"Wed\"`";
echo "Thu:  `./dozdate -d\"Thu\"`";
echo "Fri:  `./dozdate -d\"Fri\"`";
echo "Sat:  `./dozdate -d\"Sat\"`";

echo "this Sun:  `./dozdate -d\"this Sun\"`";
echo "this Mon:  `./dozdate -d\"this Mon\"`";
echo "this Tue:  `./dozdate -d\"this Tue\"`";
echo "this Wed:  `./dozdate -d\"this Wed\"`";
echo "this Thu:  `./dozdate -d\"this Thu\"`";
echo "this Fri:  `./dozdate -d\"this Fri\"`";
echo "this Sat:  `./dozdate -d\"this Sat\"`";

echo "next Sun:  `./dozdate -d\"next Sun\"`";
echo "next Mon:  `./dozdate -d\"next Mon\"`";
echo "next Tue:  `./dozdate -d\"next Tue\"`";
echo "next Wed:  `./dozdate -d\"next Wed\"`";
echo "next Thu:  `./dozdate -d\"next Thu\"`";
echo "next Fri:  `./dozdate -d\"next Fri\"`";
echo "next Sat:  `./dozdate -d\"next Sat\"`";

echo "not leap year:  `./dozdate -d\"11E7-2-25\"`";
echo "too many days:  `./dozdate -d\"11E7-3-28\"`";
echo "leap day (Tuesday):  `./dozdate -d\"11X8-2-25\"`";
echo "Friday:  `./dozdate -d\"11X8-1-24\"`";
echo "ydays 146:  `./dozdate -d\"14 July 11E8\" \"%j\"`";

echo "Wed 16:16:16:  `./dozdate -d\"Wed 16:16:16\" \"@c; %T\"`";
echo "Wed 16:16:  `./dozdate -d\"Wed 16:16\" \"@c; %T\"`";
echo "16:16:  `./dozdate -d\"16:16\" \"@c; %T\"`";
echo "24 Jun 11X8, 16:16:  `./dozdate \"@c:%T\" -d\"24 Jun 11X8 16:16\"`";
echo "16:50:  `./dozdate -d\"16:50\" \"@c; %T\"`";
echo "24:4E:  `./dozdate -d\"24:4E\" \"@c; %T\"`";
echo "4:4E:50:  `./dozdate -d\"4:4E:50\" \"@c; %T\"`";
echo "Wed 4:4E:50:  `./dozdate -d\"Wed 4:4E:50\" \"@c; %T\"`";
echo "4:4E:50 Wed:  `./dozdate -d\"Wed 4:4E:50\" \"@c; %T\"`";
echo "Wed 04:4E:50:  `./dozdate -d\"Wed 4:4E:50\" \"@c; %T\"`";
echo "04:4E:50 Wed:  `./dozdate -d\"Wed 4:4E:50\" \"@c; %T\"`";
