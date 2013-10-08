/* +AMDG */
/*
 * This document was begun on 18 Jan MAXLEN-110, the commemoration
 * of St. Prisca, virgin and martyr; and it is humbly
 * dedicated to her and to the Immaculate Heart of Mary for
 * their prayers, and to the Sacred Heart of Jesus, for His
 * mercy.
 */
/*
 * The main routine for the dozenal measurement conversion
 * program.
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

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<float.h>
#include "tgmconv.h"
#include "conv.h"

#define MAXLEN 20

int getunit(char *s, char *inp);

int main(int argc, char *argv[])
{
	char inp[MAXLEN] = " ";
	char outp[MAXLEN] = " ";
	char doznum[MAXLINE] = "NUL";
	int places = 4;
	char expnot = 0;
	double value = 0.001928;
	int i = 0;
	char c;
	char nounit = 0;

/* I know, bletcherous goto; but I need it to break out of
 * the loop/loop/switch when I hit an argument */
	startopt:
	while (--argc > 0 && (*++argv)[0] == '-') {
		if (isdigit(argv[0][1]) || argv[0][1] == '.')
			break; /* negative numbers are not optional args */
		while (c = *++argv[0])
			switch (c) {
			case 'e':
				expnot = 1;
				break;
			case 'v':
				printf("tgmconv v3.0\n");
				printf("Copyright (C) 2010, 2011  Donald P. Goodman III\n");
				printf("License GPLv3+:  GNU GPL version 3 or "
				"later <http://gnu.org/licenses/gpl.html>\n");
				printf("This is free software:  you are free "
				"to change and redistribute it.  There is NO "
				"WARRANTY, to the extent permitted by law.\n");
				return 0;
				break;
			case 'h':
				helpfunc();
				return 0;
				break;
			case 'k':
				if (isdozdig(*++argv[0])) {
					places = dozprecis(argv[0]);
					if (places >= 0)
						goto startopt;
				} else if (*(argv+1) == NULL) {
					fprintf(stderr,"doz:  invalid precision quantity\n");
					exit(1);
				} else if (isdozdig(*(argv+1)[0])) {
					places = dozprecis(*(argv+1));
					--argc, ++argv;
					if (places >= 0)
						goto startopt;
				} else {
					fprintf(stderr,"doz:  invalid precision quantity\n");
					exit(1);
				}
				if (places < 0) {
					fprintf(stderr,"doz:  invalid precision quantity\n");
					exit(1);
				}
				break;
			case 'o':
				if (isalpha(*++argv[0]) || isdigit(*argv[0]) ||
				*argv[0] == '_') {
					strncpy(outp,*argv,MAXLEN-1);
					if (strlen(*argv) > (MAXLEN-1))
						outp[MAXLEN-1] = '\0';
					goto startopt;
				} else if (*(argv+1) == NULL) {
					fprintf(stderr,"tgmconv:  no output unit\n");
					exit(1);
				} else if (isalpha(*(argv+1)[0]) ||
				isdigit(*(argv+1)[0]) || *(argv+1)[0] == '_') {
					strncpy(outp,*argv+1,MAXLEN-1);
					if (strlen(*argv+1) > (MAXLEN-1))
						outp[MAXLEN-1] = '\0';
					--argc, ++argv;
					goto startopt;
				} else {
					fprintf(stderr,"tgmconv:  invalid output unit\n");
					exit(1);
				}
				break;
			case 'i':
				if (isalpha(*++argv[0]) || isdigit(*argv[0]) ||
				*argv[0] == '_') {
					strncpy(inp,*argv,MAXLEN-1);
					if (strlen(*argv) > (MAXLEN-1))
						inp[MAXLEN-1] = '\0';
					goto startopt;
				} else if (*(argv+1) == NULL) {
					fprintf(stderr,"tgmconv:  no input unit\n");
					exit(1);
				} else if (isalpha(*(argv+1)[0]) ||
				isdigit(*(argv+1)[0]) || *(argv+1)[0] == '_') {
					strncpy(inp,*argv+1,MAXLEN-1);
					if (strlen(*argv+1) > (MAXLEN-1))
						inp[MAXLEN-1] = '\0';
					--argc, ++argv;
					goto startopt;
				} else {
					fprintf(stderr,"tgmconv:  invalid input unit\n");
					exit(1);
				}
				break;
			default:
				fprintf(stderr,"tgmconv:  illegal option \"%c\"\n",c);
				break;
			}
	}
	if (argc >= 1) {
		if (*inp == ' ')
			getunit(*argv, inp);
		value = doztodec(*argv);
		value = getanswer(outp,inp,value);
		sprintf(doznum,"%.*f",DBL_MAX_10_EXP,value);
		doz(doznum,doznum,places,expnot);
		return 0;
	}
	while (getword(doznum,MAXLINE) != EOF) {
		if (*inp == ' ' || nounit == 1) {
			getunit(doznum, inp);
			nounit = 1;
		}
		value = doztodec(doznum);
		value = getanswer(outp,inp,value);
		sprintf(doznum,"%.*f",DBL_MAX_10_EXP,value);
		doz(doznum,doznum,places,expnot);
	}
	return 0;
}

int getunit(char *s, char *inp)
{
	int i, n = 0;

	while (isdozdig(*(s++)))
		continue;
	if (*s == '\0') {
		fprintf(stderr,"tgmconv:  no input unit specified;\n"
		"Usage:  tgmconv -i input unit value\n");
		exit(1);
	}
	for (i=0; ((inp[i] = s[i]) != '\0') && i < MAXLEN; ++i);
	inp[i] = '\0';
	*(s-1) = '\0';
	return 0;
}

int helpfunc(void)
{
	printf("tgmconv, v3.0.\n");
	printf("Usage:  tgmconv -i input unit -o output unit quantity\n");
	printf("Acceptable units:\n");
	printf("TGM:\n");
	printf("\tTm");
	printf("\tGf");
	printf("\tMz");
	printf("\tVl");
	printf("\tG\n");
	printf("\tSf");
	printf("\tVm");
	printf("\tDz");
	printf("\tVv");
	printf("\tMv\n");
	printf("\tMg");
	printf("\tTz");
	printf("\tPm");
	printf("\tWg");
	printf("\tPv\n");
	printf("\tVsd");
	printf("\tVsn");
	printf("\tFq");
	printf("\trGf");
	printf("\trVl\n");
	printf("\trG");
	printf("\tRMv");
	printf("\tRMg");
	printf("\tQMz");
	printf("\tKr\n");
	printf("\tPl");
	printf("\tOg");
	printf("\tGo");
	printf("\tQl");
	printf("\tKp\n");
	printf("\tMt");
	printf("\tFm");
	printf("\tFz");
	printf("\tGn");
	printf("\tLk\n");
	printf("\tMb");
	printf("\tPz");
	printf("\tQPz");
	printf("\tLp");
	printf("\tLd\n");
	printf("\tSz");
	printf("\tQLd");
	printf("\tCg");
	printf("\tCk");
	printf("\tCsp\n");
	printf("\tCdu");
	printf("\tTgr");
	printf("\tWsp");
	printf("\tFlo");
	printf("\tVsp\n");
	printf("\tAg");
	printf("\tRQl");
	printf("\tRy");
	printf("\tEdu");
	printf("\tIm\n");
	printf("\tQz");
	printf("\tDp");
	printf("\tEgr");
	printf("\tRFm");
	printf("\tMgr\n");
	printf("\tLq");
	printf("\tKn");
	printf("\tPGf");
	printf("\tLf");
	printf("\tOsp\n");
	printf("\tMlz");
	printf("\tSlz");
	printf("\tVlz");
	printf("\tMlv");
	printf("\tMlm\n");
	printf("\tWlz");
	printf("\tEul");
	printf("\tClz");
	printf("\tOlz\n");
	printf("Metric:\n");
	printf("\ts");
	printf("\tm");
	printf("\tang");
	printf("\tfm");
	printf("\tha\n");
	printf("\tg");
	printf("\tu");
	printf("\tDa");
	printf("\tL");
	printf("\tN\n");
	printf("\tdyn");
	printf("\tkgf");
	printf("\tPa");
	printf("\tbar");
	printf("\tJ\n");
	printf("\terg");
	printf("\teV");
	printf("\tW");
	printf("\tWh");
	printf("\tHz\n");
	printf("\trad");
	printf("\tA");
	printf("\tV");
	printf("\tohm");
	printf("\tmho\n");
	printf("\tS");
	printf("\tC");
	printf("\tF");
	printf("\tWb");
	printf("\tT\n");
	printf("\tH");
	printf("\tlm");
	printf("\tcd");
	printf("\tK");
	printf("\tAt\n");
	printf("\tmol\n");
	printf("Customary/Imperial:\n");
	printf("\tft");
	printf("\tyd");
	printf("\tin");
	printf("\tau");
	printf("\tly\n");
	printf("\tpc");
	printf("\trod");
	printf("\tmil");
	printf("\tfath");
	printf("\tfurl\n");
	printf("\tmi");
	printf("\tnmi");
	printf("\tkn");
	printf("\tacre");
	printf("\tlb\n");
	printf("\tst");
	printf("\toz");
	printf("\ttoni");
	printf("\ttonc");
	printf("\tcw\n");
	printf("\tst");
	printf("\tozt");
	printf("\tlbt");
	printf("\tgali");
	printf("\tgalc\n");
	printf("\tqti");
	printf("\tqtc");
	printf("\tpti");
	printf("\tptc");
	printf("\tcpi\n");
	printf("\tcpc");
	printf("\ttbsi");
	printf("\ttbsc");
	printf("\ttspi");
	printf("\ttspc\n");
	printf("\tflozi");
	printf("\tflozc");
	printf("\tlbf");
	printf("\tslug");
	printf("\tinHg\n");
	printf("\tbtu");
	printf("\thp");
	printf("\tRPM");
	printf("\tdeg");
	printf("\tmin\n");
	printf("\thr");
	printf("\tday");
	printf("\twk");
	printf("\tyr");
	printf("\tyrlp\n");
	printf("For more information, please see the man page, \n");
	printf("or go to http://dozenal.sourceforge.net/ and see \n");
	printf("the documentation.\n");
	return 0;
}
