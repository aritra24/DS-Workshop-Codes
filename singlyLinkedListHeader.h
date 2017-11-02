typedef struct node
{
	int data;
	struct node *next;
}node;


int isEmpty(node *first)
{
	if(first->next == NULL)
		return 1;
	return 0;
}

node * insertRear(node *first,int x)
{
	node *temp = first;

	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = (node *)malloc(sizeof(node));
	temp = temp->next;
	temp->data = x;
	temp->next = NULL;
	return first;
}

node * insertFront(node *first, int x)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data = x;
	temp->next = first->next;
	first->next = temp;
	return first;
}

node * deleteFirst(node *first)
{
	if(isEmpty(first))
		return NULL;
	node *temp = first->next;
	first->next = temp->next;
	free(temp);
	return first;
}

node * deleteLast(node *first)
{
	node *prev = first;
	node *temp = first->next;
	if(isEmpty(first))
		return NULL;
	while(temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	free(temp);
	return first;
}

node * delete(node *first, int x)
{
	node *prev = NULL;
	node * temp = first;
	if(isEmpty(first))
		return NULL;
	while(temp != NULL && temp->data != x)
	{
		prev = temp;
		temp = temp->next;
	}

	if(temp != NULL)
	{
		prev->next = temp->next;
		free(temp);
	}
	return first;
}

void display(node *first)
{
	if(isEmpty(first))
	{
		printf("Empty\n");
		return;
	}
	node *temp=first->next;
	while(temp != NULL)
	{
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("End\n");
}