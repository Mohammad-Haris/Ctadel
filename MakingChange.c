
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 0;

int* arrayscan(int size);
int checkarr(int* arr, int size);
void sortarr(int* arr, int size);
void makechange(int* arr, int money, int loop);

int main()
{
	int* change, coins, end, amount;
	printf("Enter the number of coins available: ");
	scanf_s("%d", &coins);
	printf("\n");
	change = arrayscan(coins);
	end = checkarr(change, coins);
	if (end != 0)
		return 0;
	sortarr(change, coins);
	printf("Enter the amount for which you need change: ");
	scanf_s("%d", &amount);
	printf("\n");
	if (amount <= 0)
	{
		printf("Amount less than 0. What were you thinking?\n");
		return 0;
	}
	printf("Coins needed for optimal change: ");
	makechange(change, amount, coins - 1);
	return 0;
}

int* arrayscan(int size)
{
		int value, *arr;
		arr = (int*)malloc(sizeof(int)*size);
		printf("Enter the coins available, 1<=coin<=50; 1 cent is necessary: \n");
		for (int loop = 0; loop < size; loop++)
		{
			scanf_s("%d", &value);
			arr[loop] = value;
		}
		return arr;		
}

int checkarr(int* arr, int size)
{
	int one=0;
	for (int loop = 0; loop < size; loop++)
	{
		if (arr[loop] < 1 || arr[loop]>50)
		{
			printf("Re-run the program, moron.\n");
			return -1;
		}
		if (arr[loop] == 1)
			one = 1;
		if (loop == size - 1 && one != 1)
		{
			printf("Why didn't you enter 1 as value? Why? Re-run the program now.\n");
			return -1;
		}
	}
	return 0;
}

void sortarr(int* arr, int size)
{
	if (size == 0)
		return;
	int temp;
	for (int loop = 0; loop < size-1; loop++)
	{
		if (arr[loop]>arr[loop+1])
		{
			temp = arr[loop+1];
			arr[loop+1] = arr[loop];
			arr[loop] = temp;
		}
	}
	sortarr(arr, size - 1);
}

void makechange(int* arr, int money, int loop)
{
	if (money <= 0)
		return;
		if (arr[loop] <= money)
		{
			if (money-arr[loop]==0)
			{
				printf("%d\n", arr[loop]);
				makechange(arr, money - arr[loop], loop);
			}
			else
			{
				printf("%d + ", arr[loop]);
				makechange(arr, money - arr[loop], loop);
			}
		}
		else
		{
			makechange(arr, money, loop-1);
		}
}
