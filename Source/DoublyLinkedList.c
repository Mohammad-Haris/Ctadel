#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define ZERO 0

struct dll
{
	int data;
	struct dll *prev;
	struct dll *next;
};

struct dll *head = ZERO;
void createList(struct dll **);
void displayList(struct dll **);
void insertAtStart(struct dll **);
void insertAtEnd(struct dll **);
void deleteFromStart(struct dll **);
void deleteFromEnd(struct dll **);
void insertAfterNode(struct dll **);
void insertAfterData(struct dll **);
void deleteNode(struct dll **);

void main()
{
	int choice;
	printf("\n\nENTER\n\n1-----CREATE LIST\n\n2-----DISPLAY LIST\n\n3-----INSERT AT START\n\n4-----INSERT AT END\n\n5-----DELETE FROM START\n\n6-----DELETE FROM END\n\n7-----INSERT AFTER NODE\n\n8-----INSERT AFTER DATA\n\n9-----DELETE SPECIFIC NODE\n\n10----EXIT");
	while (1)
	{
		printf("\n\nEnter your choice: ");
		scanf_s("%d", &choice);
		switch (choice)
		{
			case 1:
				createList(&head);
				break;
			case 2:
				displayList(&head);
				break;
			case 3:
				insertAtStart(&head);
				break;
			case 4:
				insertAtEnd(&head);
				break;
			case 5:
				deleteFromStart(&head);
				break;
			case 6:
				deleteFromEnd(&head);
				break;
			case 7:
				insertAfterNode(&head);
				break;
			case 8:
				insertAfterData(&head);
				break;
			case 9:
				deleteNode(&head);
				break;
			case 10:
				exit(0);
			default:
				printf("Wrong input. Please enter one from the menu above.");
				break;
		}
	}
}
void createList(struct dll **head)
{
	struct dll *point, *temp;
	point = (struct dll *)malloc(sizeof(struct dll));
	printf("Enter integer data: ");
	scanf_s("%d", &point->data);
	if (*head == ZERO)
	{
		*head = point;
		point->next = ZERO;
		point->prev = ZERO;
	}
	else
	{
		temp = *head;
		while (temp->next != ZERO)
			temp = temp->next;
		temp->next = point;
		point->prev = temp;
		point->next = ZERO;
	}
}
void displayList(struct dll **head)
{
	struct dll *temp, *point;
	point = (struct dll *)malloc(sizeof(struct dll));
	if (*head == ZERO)
		printf("\nNo list exists.\n");
	else
	{
		temp = *head;
		while (temp != ZERO)
		{
			if (temp->next == ZERO)
				point = temp;
			printf(" %d ", temp->data);
			temp = temp->next;
		}
	}
}
void insertAtStart(struct dll **head)
{
	struct dll *point;
	point = (struct dll *)malloc(sizeof(struct dll));
	printf("Enter integer data: ");
	scanf_s("%d", &point->data);
	if (*head == ZERO)
	{
		*head = point;
		point->next = ZERO;
		point->prev = ZERO;
	}
	else
	{
		point->next = *head;
		point->prev = ZERO;
		(*head)->prev = point;
		*head = point;
	}
}
void insertAtEnd(struct dll **head)
{
	struct dll *point, *temp;
	point = (struct dll *)malloc(sizeof(struct dll));
	printf("Enter integer data: ");
	scanf_s("%d", &point->data);
	if (*head == ZERO)
	{
		*head = point;
		point->next = ZERO;
		point->prev = ZERO;
	}
	else
	{
		temp = *head;
		while (temp->next != ZERO)
			temp = temp->next;
		temp->next = point;
		point->prev = temp;
		point->next = ZERO;
	}
	return;
}
void deleteFromStart(struct dll **head)
{
	struct dll *temp;
	if (*head == ZERO)
		printf("\nNo list exists");
	if ((*head)->next == ZERO)
		*head = ZERO;
	else
	{
		temp = *head;
		*head = temp->next;
		if (temp->next != ZERO)
		{
			(*head)->prev = ZERO;
			free(temp);
		}
	}
	return;
}
void deleteFromEnd(struct dll **head)
{
	struct dll *temp;
	if (*head == ZERO)
		printf("No list exists.");
	if ((*head)->next == ZERO)
		*head = ZERO;
	else
	{
		temp = *head;
		while (temp->next != ZERO)
			temp = temp->next;
		temp->prev->next = ZERO;
		free(temp);
	}
	return;
}
void insertAfterNode(struct dll **head)
{
	struct dll *point, *temp;
	int loop, count;
	if (*head == ZERO)
		printf("No list exits.");
	else
	{
		temp = *head;
		loop = 1;
		printf("\nEnter position  of the node after which you want to insert data: ");
		scanf_s("%d", &count);
		while (temp != ZERO && loop <= count - 1)
		{
			temp = temp->next;
			loop++;
		}
		if (temp != ZERO)
		{
			point = (struct dll *)malloc(sizeof(struct dll));
			printf("Enter integer data: ");
			scanf_s("%d", &(point->data));
			point->next = temp->next;
			temp->next = point;
			point->prev = temp;
			point->next->prev = point;
		}
		else
			printf("Insertion failed.");
	}
	return;
}
void deleteNode(struct dll **head)
{
	struct dll *point, *temp;
	int loop, count, size;
	printf("Enter the node you want delete: ");
	scanf_s("%d", &count);
	if (*head == ZERO)
		printf("List empty.\n");	
	else
	{
		if (count == 1)
		{
			deleteFromStart(head);
			return;
		}
		temp = *head; size = 1;
		while (temp->next != ZERO)
		{
			temp = temp->next;
			size++;
		}
		if (count == size)
		{
			deleteFromEnd(head);
			return;
		}
		if (count > size)		
			printf("Deletion failed.");		
		else
		{
			temp = *head;
			loop = 1;
			while (temp->next != ZERO && loop < count)
			{
				temp = temp->next;
				loop++;
			}
			point = temp->prev;
			point->next = temp->next;
			temp->next->prev = point;
			free(temp);
		}
	}
	return;
}
void insertAfterData(struct dll **head)
{
	struct dll *point, *temp;
	int data;
	if (*head == ZERO)
		printf("No list exists.");
	else
	{
		temp = *head;
		printf("Enter the data after which you want to insert: ");
		scanf_s("%d", &data);
		while (temp != ZERO && temp->data != data)
			temp = temp->next;
		if (temp != ZERO)
		{
			point = (struct dll *)malloc(sizeof(struct dll));
			printf("Enter integer data: ");
			scanf_s("%d", &(point->data));
			if (temp->next != ZERO)
			{
				point->next = temp->next;
				temp->next = point;
				point->prev = temp;
				point->next->prev = point;
			}
			else
			{
				temp->next = point;
				point->prev = temp;
				point->next = ZERO;
			}
		}
		else
			printf("Data not present in list.\n");
	}
	return;
}