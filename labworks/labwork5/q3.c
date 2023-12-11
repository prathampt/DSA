#include<stdio.h>

int main()
{
	char string[30];
	fgets(string,30,stdin);
	
	int i=0;
	int count;
	while(string[i]!='\0')
	{
		char c=string[i];
		int a=(int)c;
		if ((a==65)||(a==69)||(a==73)||(a==79)||(a==85)||(a==97)||(a==101)||(a==105)||(a==111)||(a==117))
		{
			count=count+1;
		}
		i=i+1;
	}
	
	printf("The number of vowels in the entered string are %d\n",count);
	return 0;
}

