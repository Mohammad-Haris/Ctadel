#include <stdio.h>

void main()
{
	long int high, low, step;
	char unit;
	printf("High and low limit= 2,000,000,000\n");
	printf("Step size should be at most limit/50\n");
	printf("Please enter the high and low respectively: \n");
	scanf_s("%ld %ld", &high, &low);
	printf("Please enter step size. Step size should be less than %d: \n", (-1)*low > high ? (-1)*low/50 : high/50);
	scanf_s("%ld", &step);
	printf("Select temperature unit (c(centigrade) or f(farenheit)): \n");
	scanf_s(" %c", &unit, 1);
	if (step > ((-1) * low > high ? (-1) * low/50 : high/50))
	{
		printf("Step too much big\n");
	}
	else
	{
		if (unit == 'f' || unit == 'F' || unit == 'c' || unit == 'C')
		{
			if (unit == 'f' || unit == 'F')
			{
				long int cent, loop;
				printf("Farenheit		Centigrade\n");
				for (loop = low; loop <= high; loop = loop + step)
				{
					cent = ((loop - 32) * 5) / 9;
					printf("%d			%d\n", loop, cent);
				}
				printf("Program end :)");
			}
			else
			{
				long int faren, loop;
				printf("Centigrade		Farenheit\n");
				for (loop = low; loop <= high; loop = loop + step)
				{
					faren = ((loop * 9) / 5) + 32;
					printf("%d			%d\n", loop, faren);
				}
				printf("Program end :)");
			}
		}
		else
		{
			printf("Unit not specified correctly\n");
		}
	}
}
