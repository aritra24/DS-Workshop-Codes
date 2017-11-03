typedef struct node
{
	int data;
	struct node *prev, *next;
}node;

int isEmpty(node *first)
{
	if(first == NULL)
		return 1;
	return 0;
}

node * insertRear(node *first,int x)
{
	if(isEmpty(first))
	{
		node *temp = (node *)malloc(sizeof(node));
		temp->data = x;
		temp->prev = temp;
		temp->next = temp;
		first = temp;
		return first;
	}

	node *temp = first->prev;
	temp->next = (node *)malloc(sizeof(node));
	node *temp2 = temp;
	temp = temp->next;
	temp->prev = temp2;
	temp->data = x;
	temp->next = first;
	return first;
}

node * insertFront(node *first, int x)
{
	if(isEmpty(first))
		return insertRear(first, x);
	node *temp = (node *)malloc(sizeof(node));
	temp->data = x;
	temp->prev = first->prev;
	node *temp2 = first->prev;
	temp2->next = temp;
	temp->next = first;
	first->prev = temp;
	return temp;
}

node * delete(node *first, int x)
{
	node *temp = first;
	if(isEmpty(first))
		return NULL;

	while(temp->next != first && temp->data != x)
	{
		temp = temp->next;
	}
	if(first->data == x)
	{
		first = first->next;
	}
	if(temp->data == x)
	{
		node *prev = temp->prev;
		prev->next = temp->next;
		free(temp);
	}
	else if(temp->next->data = x)
	{
		node *prev = temp;
		temp = temp->next;
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
	node *temp=first;
	while(temp->next != first)
	{
		printf("%d <--> ",temp->data);
		temp = temp->next;
	}
	printf("%d <--> \n",temp->data);
}