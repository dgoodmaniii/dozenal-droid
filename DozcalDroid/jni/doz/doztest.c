#include<stdio.h>
#include<float.h>
#include<math.h>
#include<string.h>

void reverse(char *s)
{
	int i, j;
	char tmp;
	size_t length;

	length = strlen(s) - 1;
	for (i=0, j=length; i<j; ++i, --j) {
		tmp = *(s+i);
		*(s+i) = *(s+j);
		*(s+j) = tmp;
	}
}

char dozenify(char num)
{
	switch (num) {
	case 0: case 1: case 2: case 3: case 4: case 5: case 6:
	case 7: case 8: case 9:
		return (num % 10) + '0';
	case 10: 
		return 'X'; 
	case 11:
		return 'E';
	}
}

int dectodoz(char *doznum, double decnum)
{
	int i = 0; int sign = 0; int j = 0;
	double wholedec; /* whole number portion of decnum */
	double partholder; /* someplace for modf to dump integral */

	if (decnum < 0) {
		decnum = -decnum;
		sign = 1;
	}
	partholder = modf(decnum,&wholedec);
	decnum -= wholedec;
	while (wholedec >= 12) {
		*(doznum+(i++)) = dozenify(fmod(wholedec,12.0));
		wholedec /= 12;
	}
	*(doznum+(i++)) = dozenify(fmod(wholedec,12));
	if (sign == 1)
		*(doznum+(i++)) = '-';
	*(doznum+i) = '\0';
	reverse(doznum);
	if (decnum > 0) {
		*(doznum+(i++)) = ';';
		for (i=i; i <= DBL_MAX_10_EXP; ++i) {
			*(doznum+i) = dozenify((int)(decnum * 12));
			decnum = modf(decnum*12,&partholder);
		}
		*(doznum+i) = '\0';
	}
	return 0;
}

int main(void)
{
	char doznum[2000] = "";
	double decnum = 0.33333333333333333333333333333333333;

	dectodoz(doznum,decnum);
	printf("%s\n",doznum);
	return 0;
}
