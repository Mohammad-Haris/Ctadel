#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

void main()
{
	int whitesquare = 219, input;
	bool check = true;
	printf("Enter even values only. Odd valued checker board won't look like a checker board\n");
	printf("Enter the order of the checker board e.g. 8x8, 10x10 etc: ");
	scanf_s("%d", &input);
	if (input > 20)
	{
		printf("Warning: The generated checker board might not show up properly on the console\n");
	}
	printf("\n");
	for (int row = 0; row < input; row++)
	{
		for (int column = 0; column < input; column++)
		{
			if (check)
			{
				printf("%c", whitesquare); check = !check;
			}
			else
			{
				printf(" "); check = !check;
			}
		}
		printf("\n");  check = !check;
	}
	getchar(); getchar();
}