#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
	int val;
	struct List *next;
}
List;

List* createNode(int v)
{
	List *node = (List*)malloc(sizeof(List));
	node -> val = v;
	node -> next = NULL;
	return node;
}

List* createList(int n)
{
	List *head = NULL, *tail = NULL, *newN;
	int v;
	printf("Enter the elements of the list: \n");

	for (int i = 0; i < n; i++)
	{
		printf("Enter the value: ");
		scanf("%d", &v);
		newN = createNode(v);
		if (head == NULL)
			head = newN;
		else
			tail -> next = newN;
		tail = newN;
	}
	return head;
}

int listSize(List *head)
{
	int s = 0;
	while (head)
	{
		s++;
		head = head -> next;
	}
	return s;
}

List* delFromEnd(List *head, int pos)
{
	int l = listSize(head);
	int position = l - pos + 1;

	if (position < 1 || position > l)
	{
		printf("Invalid position or list is empty!\n");
		return head;
	}

	List *c, *p = head;
	if (position == 1)
	{
		head = head -> next;
		free(p);
		return head;
	}

	for (int i = 1; i < position - 1; i++)
	{
		p = p -> next;
	}
	c = p -> next;
	p -> next = c -> next;
	free(c);
	return head;
}

void printList(List *head)
{
	while (head)
	{
		printf("%d -> ", head -> val);
		head = head -> next;
	}
	printf("END\n");
}

int main()
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	List *head = createList(n);
	printf("Original list: ");
	printList(head);
	int v;
	printf("Enter the position to delete from the end: ");
	scanf("%d", &v);

	delFromEnd(head, v);
	printf("After deleting: ");
	printList(head);
}
