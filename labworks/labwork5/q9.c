#include <stdio.h>
#include <string.h>

int main()
{
	int num;
	printf("Enter the number:-\n");
	scanf("%d", &num);
	float numdec = (float)num;
	int temp = num;
	char numoct[10];
	char numhex[10];

	int i = 0;
	while (temp != 0)
	{
		int a = temp % 8;
		switch (a)
		{
		case 0:
			numoct[i] = '0';
			break;
		case 1:
			numoct[i] = '1';
			break;
		case 2:
			numoct[i] = '2';
			break;
		case 3:
			numoct[i] = '3';
			break;
		case 4:
			numoct[i] = '4';
			break;
		case 5:
			numoct[i] = '5';
			break;
		case 6:
			numoct[i] = '6';
			break;
		case 7:
			numoct[i] = '7';
			break;
		}
		temp = temp / 8;
		i = i + 1;
	}

	int j = 0;
	while (num != 0)
	{
		int b = num % 16;
		switch (b)
		{
		case 0:
			numhex[j] = '0';
			break;
		case 1:
			numhex[j] = '1';
			break;
		case 2:
			numhex[j] = '2';
			break;
		case 3:
			numhex[j] = '3';
			break;
		case 4:
			numhex[j] = '4';
			break;
		case 5:
			numhex[j] = '5';
			break;
		case 6:
			numhex[j] = '6';
			break;
		case 7:
			numhex[j] = '7';
			break;
		case 8:
			numhex[j] = '8';
			break;
		case 9:
			numhex[j] = '9';
			break;
		case 10:
			numhex[j] = 'A';
			break;
		case 11:
			numhex[j] = 'B';
			break;
		case 12:
			numhex[j] = 'C';
			break;
		case 13:
			numhex[j] = 'D';
			break;
		case 14:
			numhex[j] = 'E';
			break;
		case 15:
			numhex[j] = 'F';
			break;
		}
		num = num / 16;
		j = j + 1;
	}
	int k, l;
	for (k = 0, l = i - 1; k < l; k = k + 1, l = l - 1)
	{
		char t = numoct[k];
		numoct[k] = numoct[l];
		numoct[l] = t;
	}
	for (k = 0, l = j - 1; k < l; k = k + 1, l = l - 1)
	{
		char t = numhex[k];
		numhex[k] = numhex[l];
		numhex[l] = t;
	}

	printf("The decimal representationn is:- %f\n", numdec);
	printf("The octal representation is:- %s\n", numoct);
	printf("the hexadecimal representation is :-%s\n", numhex);

	return 0;
}
