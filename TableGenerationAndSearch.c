#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

void main()
{
	int arraysize;
	printf("\nEnter the number of the terms of the table: ");
	scanf_s("%d", &arraysize);
	int *x = malloc(arraysize * sizeof(int));
	int *y = malloc(arraysize * sizeof(int));
	printf("\n\nEnter the respective values of the variables x and y: \n\n");
	for (int loop = 0; loop < arraysize; loop++)
	{
		printf("x: ");
		scanf_s("%d", &x[loop]);
		printf("y: ");
		scanf_s("%d", &y[loop]);
	}
	printf("\n");
	char check = '1';
	bool valuefound = false;
	while (check == '1')
	{
		printf("\nEnter the value of the x to find the respective value of y: ");
		int search, value = 0;
		scanf_s("%d", &search);
		for (int loop = 0; loop < arraysize; loop++)
		{
			if (x[loop] == search)
			{
				valuefound = true;
				value = y[loop];
				printf("\n\n The respective value of the variable y is: %d", value);
			}
		}				
		if (!valuefound)
			printf("\n\nx is not present with the specific value within the table");
		printf("\n\n Do you want to continue?\n\n Press 1 to continue and any other key to exit: ");
		scanf_s("%c", &check, 1);	//special character buffer catch
		scanf_s("%c", &check, 1);
	}
}