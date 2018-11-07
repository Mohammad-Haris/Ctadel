
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int start = 0, end = 0;

double *scanarray(int length);
int checkarr(double *arr, int length);
void max_con_subseq(double *arr, double max, int first, int last, int comb);
double sumarray(double *arr, int first, int last);

int main()
{
	double *realnos, max; int size, check = -1;
		printf("Please enter the size of array: ");
		scanf_s("%d", &size); printf("\n");
		if (size <= 0)
		{
			printf("Array size should be greater than 0\n");
			return 0;
		}
		realnos = scanarray(size);
		check = checkarr(realnos, size);
		if (check != 0)
		{
			printf("Please re-run the program; You mistakenly/delibrately entered a character in the double array\n");
			return 0;
		}
		start = 0, end = size - 1;
		max = sumarray(realnos, 0, size - 1);
		max_con_subseq(realnos, max, 0, size - 1, size);
		printf("\nMax contiguous subsequence: ");
		for (int loop = start; loop <= end; loop++)
			printf("%lf	", realnos[loop]);
		printf("\n\n");
	return 0;
}

double *scanarray(int length)
{
	double *arr, check;
	arr = malloc(sizeof(double)*length);
	printf("Enter %d real numbers (Don't enter a character, or you'll have to re-run the program): \n", length);
	for (int loop = 0; loop < length; loop++)
	{
		check = scanf_s("%lf", &arr[loop]);
		if (check != 1)
			break;
	}
	return arr;
}

int checkarr(double *arr, int length)
{
	for (int loop = 0; loop < length; loop++)
	{
		if ((char)arr[loop] == '\0')
			return -1;
	}
	return 0;
}

void max_con_subseq(double *arr, double max, int first, int last, int comb)
{
	if (comb < 2)
		return;
	double sum = 0;
	for (int loop = 0; loop <= last; loop++)
	{
		if (loop + comb - 1 <= last)
			sum = sumarray(arr, loop, loop + comb - 1);
		if (max < sum && loop+comb-1<=last)
		{
			max = sum;
			start = loop; end = loop + comb - 1;
		}
	}
	max_con_subseq(arr, max, first, last, comb - 1);
}

double sumarray(double *arr, int first, int last)
{
	double sum = 0;
	for (int loop = first; loop <= last; loop++)
		sum = sum + arr[loop];
	return sum;
}