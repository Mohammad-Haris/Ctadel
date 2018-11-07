
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
	int count = 0;
	FILE* f;
	errno_t error;
	if (argc < 2)
	{
		return 0;
	}
	error = fopen_s(&f, argv[1], "r");
	if (error != 0)
	{	
		printf("Error: No such file exists. Please enter complete file path with extension.");
		exit(1);
	}
	else
	{
		fseek(f, 0, SEEK_SET);
		char read; 
		while (1)
		{
			fscanf_s(f, "%c", &read, 1);
			if (feof(f)!=0)
			{
				break;
			}
			count++;
		}
	}
	count = count;
	printf("\nFile size in bytes: %d \n", count);
	return 0;
}