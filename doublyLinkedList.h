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
		temp->prev = NULL;
		temp->next = NULL;
		first = temp;
		return first;
	}
	node *temp = first;

	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = (node *)malloc(sizeof(node));
	node *temp2 = temp;
	temp = temp->next;
	temp->prev = temp2;
	temp->data = x;
	temp->next = NULL;
	return first;
}

node * insertFront(node *first, int x)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data = x;
	temp->prev = NULL;
	temp->next = first;
	first->prev = temp;
	return temp;
}

node * deleteFirst(node *first)
{
	if(isEmpty(first))
		return NULL;
	node *temp = first;
	first = first->next;
	first->prev = NULL;
	free(temp);
	return first;
}

node * deleteLast(node *first)
{
	node *temp = first;
	if(isEmpty(first))
		return NULL;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp = temp->prev;
	free(temp->next);
	temp->next = NULL;
	return first;
}

node * delete(node *first, int x)
{
	node * temp = first;
	if(isEmpty(first))
		return NULL;
	while(temp != NULL && temp->data != x)
	{
		temp = temp->next;
	}

	if(temp != NULL)
	{
		node temp2=temp->prev;
		temp2->next = temp->next;
		free(temp);
	}
	return first;
}

node * reverse(node *first)
{
	node *current = first, *Next = first->next;
	while(next != NULL)
	{
		current->next = current->prev;
		current->prev = next;
		Next = Next->next;
	}
	return current;
}

void display(node *first)
{
	if(isEmpty(first))
	{
		printf("Empty\n");
		return;
	}
	node *temp=first;
	while(temp != NULL)
	{
		printf("%d <--> ",temp->data);
		temp = temp->next;
	}
	printf("end\n");
}