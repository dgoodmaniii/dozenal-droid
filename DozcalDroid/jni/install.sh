#!/bin/bash
# +AMDG
# This document was begun on 7 February 2010, Sexagesima
# Sunday, and it is humbly dedicated to the Immaculate Heart
# of Mary for her prayers, and to the Sacred Heart of Jesus
# for His mercy.

cd doz;
make;
make doc;
make install;
cd ../dec;
make;
make doc;
make install;
cd ../dozdc;
make;
make gdozdc;
make doc;
make install;
cd ../tgmconv;
make;
make doc;
make install;
cd ../dozword;
make;
make doc;
make install;
cd ../dozpret;
make;
make doc;
make install;
cd ../dozdate;
make;
make doc;
make install;
cd ../dozstring;
make;
make doc;
make install;
