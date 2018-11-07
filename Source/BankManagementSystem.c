#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>


struct bank
{
	int accountnumber;
	int basic_amount;
	char name[30];
	char account_type;
	char cnic[20];
	char address[40];
	char pass[20];
};

void welcome()
{
	printf("\n\n");
	Sleep(500);
	printf("\t\t^-^-^-^-^-^-^-^-^-^-^\n");
	Sleep(500);
	printf("\t\t^      BANK         ^\n");
	Sleep(500);
	printf("\t\t^                   ^\n");
	Sleep(500);
	printf("\t\t^                   ^\n");
	Sleep(500);
	printf("\t\t^                   ^\n");
	Sleep(500);
	printf("\t\t^   MANAGEMENT      ^\n");
	Sleep(500);
	printf("\t\t^                   ^\n");
	Sleep(500);
	printf("\t\t^                   ^\n");
	Sleep(500);
	printf("\t\t^                   ^\n");
	Sleep(500);
	printf("\t\t^     SYSTEM        ^\n");
	Sleep(500);
	printf("\t\t^                   ^\n");
	Sleep(500);
	printf("\t\t^-^-^-^-^-^-^-^-^-^-^\n");
}

void readModify(struct bank *p)
{
	printf("\nEnter account holder name: ");
	scanf_s("%s", &p->name[0], (unsigned)_countof(p->name));
	printf("Account type C/S: ");
	scanf_s(" %c", &p->account_type, 1);
	printf("Enter CNIC#: ");
	scanf_s("%s", &p->cnic[0], (unsigned)_countof(p->cnic));
	printf("Enter address: ");
	scanf_s("%s", &p->address[0], (unsigned)_countof(p->address));
	printf("Please enter your password: ");
	scanf_s("%s", &p->pass[0], (unsigned)_countof(p->pass));
	printf("Your account has been successfully modified.\n");
}

void read(struct bank *p)
{
	printf("Enter Account Number:");
	scanf_s("%d", &p->accountnumber);
	printf("Enter Account Holder Name:");
	scanf_s("%s", &p->name, (unsigned)_countof(p->name));
	printf("Account Type (C/S):");
	scanf_s(" %c", &p->account_type, 1);
	printf("Enter CNIC#:");
	scanf_s("%s", &p->cnic[0], (unsigned)_countof(p->cnic));
	printf("Enter Address:");
	scanf_s("%s", &p->address[0], (unsigned)_countof(p->address));
	printf("Enter Basic Amount:");
	scanf_s("%d", &p->basic_amount);
	printf("Enter your password:");
	scanf_s("%s", &p->pass, (unsigned)_countof(p->address));
	printf("\n");
	Sleep(500);
	printf("**************");
	Sleep(500);
	printf("CONGRATULATIONS");
	Sleep(500);
	printf("**************\n");
	printf("Your ");
	Sleep(500);
	printf("account ");
	Sleep(500);
	printf("has ");
	Sleep(500);
	printf("been ");
	Sleep(500);
	printf("Sucessfully ");
	Sleep(500);
	printf("Created\n");
}

void print(struct bank *p)
{
	printf("Account number is: ");
	printf("%d\n", p->accountnumber);
	printf("\n");
	printf("Account Holder Name: ");
	printf("%s", &p->name);
	printf("\n");
	printf("Account Type: ");
	printf("%c", p->account_type);
	printf("\n");
	printf("CNIC#: ");
	printf("%s", &p->cnic);
	printf("\n");
	printf("Basic Amount: ");
	printf("%d\n", p->basic_amount);
	printf("\n");
	printf("ADDRESS: ");
	printf("%s", p->address);
}

void menu()
{
	printf("\n");
	puts("                ***** MAIN MENU *****           ");
	printf("\n\n");
	puts("\n1:\tCREATE NEW ACCOUNT");
	Sleep(500);
	puts("\n2:\tDEPOSIT AMMOUNT");
	Sleep(500);
	puts("\n3:\tWITHDRAW AMMOUNT");
	Sleep(500);
	puts("\n4:\tBALANCE INQUIRY");
	Sleep(500);
	puts("\n5:\tACCOUNT HOLDER LIST");
	Sleep(500);
	puts("\n6:\tCLOSE ACCOUNT");
	Sleep(500);
	puts("\n7:\tMODIFY ACCOUNT");
	Sleep(500);
	puts("\n8:\tTO EXIT");
	Sleep(500);
	printf("\n\n");
	printf("PLEASE ENTER YOUR CHOICE: ");
}

void main()
{
	FILE *f;
	errno_t err;
	struct bank object, object_list[100], temp;
	int input;
	long int stsize = sizeof(object);
	printf("\n");
	welcome();
	Sleep(1000);
	system("CLS");

	while (1)
	{
		printf("\t\t***** BANK MANAGEMENT SYSTEM *****\n");
		menu();
		scanf_s("%d", &input);

		switch (input)
		{
		case 1:
		{
			system("CLS");
			err = fopen_s(&f, "record.bin", "a");
			if (err != 0)
			{
				printf("Cannot open file. Make sure the record.bin file exists and is not being used by any other program.\n");
				break;
			}
			read(&object);
			fwrite(&object, sizeof(object), 1, f);
			fclose(f);
		} break;

		case 2:
		{
			int acc_no, deposit, size = 0, loop = 0, check;
			char pass[20];
			system("CLS");
			printf("Please Enter Your Account Number: ");
			scanf_s("%d", &acc_no);
			fflush(stdin);
			printf("\n");
			printf("Please Enter Your Password: ");
			scanf_s("%s", pass, (unsigned)_countof(pass));
			printf("\n");
			err = fopen_s(&f, "record.bin", "r+");
			if (err != 0)
			{
				printf("Cannot open file. Make sure the record.bin file exists and is not being used by any other program.\n");
				break;
			}
			while ((fread(&object, sizeof(object), 1, f)) == 1)
			{
				object_list[size] = object;
				size++;
			}
			for (loop = 0; loop < size; loop++)
			{
				check = strcmp(pass, object_list[loop].pass);
				if ((object_list[loop].accountnumber == acc_no) && (check == 0))
				{
					printf("Loading your record please wait .");
					printf(" .");
					Sleep(1000);
					printf(" .");
					Sleep(1000);
					printf(" .");
					Sleep(1000);
					printf(" .\n");
					system("CLS");
					printf("Your current status is: ");
					printf("\n\n");
					print(&object_list[loop]);
					printf("\n");
					Sleep(10000);
					system("CLS");

					puts("DEPOSIT YOUR MONEY.");
					printf("\n");
					printf("Hello Mr: ");
					puts(object_list[loop].name);
					printf("\n");
					printf("Your previous amount is: ");
					printf("%d RS", object_list[loop].basic_amount);
					printf("\n");
					printf("\n");
					printf("Please enter the amount you want to deposit: ");
					scanf_s("%d", &deposit);
					printf("\n");
					object_list[loop].basic_amount = object_list[loop].basic_amount + deposit;
					system("CLS");
					puts("YOUR STATUS HAS BEEN UPDATED SUCESSFULLY.");
					printf("\n");
					print(&object_list[loop]);
					printf("\n");
					break;
				}
			}
			fseek(f, 0, SEEK_SET);
			for (loop = 0; loop < size; loop++)
			{
				fwrite(&object_list[loop], sizeof(object_list[loop]), 1, f);
			}
			fclose(f);
		}break;

		case 3:
		{
			int acc_no, deposit, size = 0, loop;
			char pass[20];
			system("CLS");
			err = fopen_s(&f, "record.bin", "r+");
			if (err != 0)
			{
				printf("Cannot open file. Make sure the record.bin file exists and is not being used by any other program.\n");
				break;
			}
			rewind(f);
			printf("Please enter your account number: ");
			scanf_s("%d", &acc_no);
			fflush(stdin);
			printf("\n");
			puts("Please enter your password: ");
			scanf_s("%s", pass, (unsigned)_countof(pass));
			while (fread(&object, sizeof(object), 1, f) == 1)
			{
				object_list[size] = object;
				size++;
			}
			for (loop = 0; loop < size; loop++)
			{

				int check = strcmp(pass, object_list[loop].pass);
				if ((object_list[loop].accountnumber == acc_no) && (check == 0))
				{
					if ((object_list[loop].basic_amount <= 0))
					{
						puts("You have no amount in your account first deposit some money.");
						break;
					}
					printf("Loading your record please wait .");
					printf(" .");
					Sleep(1000);
					printf(" .");
					Sleep(1000);
					printf(" .");
					Sleep(1000);
					printf(" .\n");
					Sleep(1000);
					system("CLS");
					printf("Your current status is: ");
					printf("\n");
					print(&object_list[loop]);
					Sleep(4000);
					system("CLS");
					puts("WITHDRAW YOUR AMMOUNT.");
					printf("\n");
					printf("\n");
					printf("Your previous amount is=%d RS", object_list[loop].basic_amount);
					printf("\n");
					printf("\n");
					printf("\n");
					printf("\n");
					printf("Please enter the amount which you want to withdraw: ");
					scanf_s("%d", &deposit);
					if (deposit > object_list[loop].basic_amount)
					{
						puts("You can not withdraw this amount.");
						break;
					}
					object_list[loop].basic_amount = object_list[loop].basic_amount - deposit;
					system("CLS");
					printf("\n");
					puts("Your Status has been updated successfully.");
					printf("\n");
					print(&object_list[loop]);
					break;
				}
			}
			fseek(f, 0, SEEK_SET);
			for (loop = 0; loop < size; loop++)
			{
				fwrite(&object_list[loop], sizeof(object_list[loop]), 1, f);
			}
			fclose(f);
		}break;

		case 4:
		{
			int acc_no;
			puts("BALANCE INQUIRY.");
			printf("\n");
			char pass[20];
			system("CLS");
			err = fopen_s(&f, "record.bin", "r+");
			if (err != 0)
			{
				printf("Cannot open file. Make sure the record.bin file exists and is not being used by any other program.\n");
				break;
			}
			rewind(f);
			printf("Please enter your account number: ");
			scanf_s("%d", &acc_no);
			fflush(stdin);
			printf("Please enter your password: ");
			scanf_s("%s", pass, (unsigned)_countof(pass));
			printf("\n");
			while (fread(&object, sizeof(object), 1, f) == 1)
			{
				int check = strcmp(pass, object.pass);
				if (acc_no == object.accountnumber && check == 0)
				{
					printf("Loading your record please wait .");
					printf(" .");
					Sleep(1000);
					printf(" .");
					Sleep(1000);
					printf(" .");
					Sleep(1000);
					printf(" .\n");
					Sleep(1000);
					print(&object);
					break;
				}
			}
			fclose(f);
		}break;

		case 5:
		{
			int check = 0;
			err = fopen_s(&f, "record.bin", "r+");
			if (err != 0)
			{
				printf("Cannot open file. Make sure the record.bin file exists and is not being used by any other program.\n");
				break;
			}
			rewind(f);
			system("CLS");
			puts("Records: ");
			while (fread(&object, sizeof(object), 1, f) == 1)
			{
				printf("----------\n");
				printf("Account number: %d\n", object.accountnumber);
				printf("Name: %s\n", object.name);
				printf("Account type: %c\n", object.account_type);
				printf("Address: %s\n", object.address);
				printf("Amount: %d\n", object.basic_amount);
				printf("----------\n");
				check++;
			}
			if (check <= 0)
				printf("No account found in bank records.\n");
			fclose(f);
		}break;

		case 6:
		{
			int acc_no, found = 0;
			char pass[20];
			system("CLS");
			err = fopen_s(&f, "record.bin", "r");
			if (err != 0)
			{
				printf("Cannot open file. Make sure the record.bin file exists and is not being used by any other program.\n");
				break;
			}
			errno_t temp;
			FILE *f_temp;
			temp = fopen_s(&f_temp, "temp.bin", "w");
			if (temp != 0)
			{
				printf("Cannot open file. Make sure the record.bin file exists and is not being used by any other program.\n");
				break;
			}
			rewind(f);
			printf("Please enter your account number: ");
			scanf_s("%d", &acc_no);
			fflush(stdin);
			printf("\n");
			printf("Please enter your password: ");
			scanf_s("%s", pass, (unsigned)_countof(pass));
			printf("\n");
			while (fread(&object, sizeof(object), 1, f) == 1)
			{
				if (strcmp(pass, object.pass) == 0 && acc_no == object.accountnumber)
				{
					printf("A record was found and deleted.\n\n");
					found = 1;
				}
				else
					fwrite(&object, sizeof(object), 1, f_temp);
			}
			if (!found)
			{
				printf("No record(s) found with the requested data\n\n");
				fclose(f);
				fclose(f_temp);
				break;
			}
			Sleep(2000);
			fclose(f);
			fclose(f_temp);
			remove("record.bin");
			rename("temp.bin", "record.bin");
			system("CLS");
			printf("\n");
			puts("Deleting THE Required Account Plz Wait .");
			printf(" .");
			Sleep(1000);
			printf(" .");
			Sleep(1000);
			printf(" .");
			Sleep(1000);
			printf(" .\n");
			Sleep(1000);
			printf("\n");
			printf("\n");
			system("CLS");
			puts("Requested Account Has Been Closed.");
			printf("\n");
			puts("You can recieve your remaining amount of your account from our account office.");
			Sleep(3000);
		}break;

		case 7:
		{
			int acc_no, size = 0, loop;
			err = fopen_s(&f, "record.bin", "r+");
			if (err != 0)
			{
				printf("Cannot open file. Make sure the record.bin file exists and is not being used by any other program.\n");
				break;
			}
			char pass[20];
			system("CLS");
			rewind(f);
			printf("\nPlease enter your account number: ");
			scanf_s("%d", &acc_no);
			fflush(stdin);
			printf("Please enter your password: ");
			scanf_s("%s", pass, (unsigned)_countof(pass));
			printf("\n");
			while (fread(&object, sizeof(object), 1, f) == 1)
			{
				object_list[size] = object;
				size++;
			}
			for (loop = 0; loop < size; loop++)
			{
				int check = strcmp(pass, object_list[loop].pass);
				if (object_list[loop].accountnumber == acc_no && check == 0)
				{
					print(&object_list[loop]);
					printf("\n\nEnter new attributes.\n ");
					readModify(&temp);
					object_list[loop].accountnumber = object_list[loop].accountnumber;
					strcpy_s(object_list[loop].name, (unsigned)_countof(object_list[loop].name), temp.name);
					strcpy_s(object_list[loop].cnic, (unsigned)_countof(object_list[loop].cnic), temp.cnic);
					object_list[loop].account_type = temp.account_type;
					strcpy_s(object_list[loop].address, (unsigned)_countof(object_list[loop].address), temp.address);
					strcpy_s(object_list[loop].pass, (unsigned)_countof(object_list[loop].pass), temp.pass);
					puts("\nYour status has been updated.\n");
					Sleep(2000);
					system("CLS");
					print(&object_list[loop]);
					break;
				}
			}
			fseek(f, 0, SEEK_SET);
			for (loop = 0; loop < size; loop++)
			{
				fwrite(&object_list[loop], sizeof(object_list[loop]), 1, f);
			}
			fclose(f);
		}break;

		case 8:
		{
			exit(0);
		}
		default:
		{
			system("CLS");
			puts("Unknown Command.");
		}
		}
		puts("\n\nPress Enter to go to Main Menu");
		getchar(); getchar();
		system("CLS");
	}
}