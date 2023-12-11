#include <stdio.h>

int main()
{
	int store[10];
	int item;
	for (int i = 0; i < 10; i = i + 1)
	{
		scanf("%d", &item);
		store[i] = item;
	}
	int count = 0;

	for (int i = 0; i < 3; i = i + 1)
	{
		for (int j = 0; j < 3; j = j + 1)
		{
			printf("%d ,", store[count]);
			count = count + 1;
		}
		printf("\n");
	}

	printf("%d ,", store[count]);

	return 0;
}
