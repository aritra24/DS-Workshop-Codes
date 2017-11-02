typedef struct node
{
	int data;
	struct node *next;
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
	temp = temp->next;
	temp->data = x;
	temp->next = NULL;
	return first;
}

node * insertFront(node *first, int x)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data = x;
	temp->next = first;
	return temp;
}

node * deleteFirst(node *first)
{
	if(isEmpty(first))
		return NULL;
	node *temp = first;
	first = first->next;
	free(temp);
	return first;
}

node * deleteLast(node *first)
{
	node *prev = NULL;
	node *temp = first;
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

node * reverse(node *first)
{
	node *prev = NULL, *current = NULL, *next = first;
	while(next != NULL)
	{
		prev = current;
		current = next;
		next = next->next;
		current->next = prev;
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
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("end\n");
}