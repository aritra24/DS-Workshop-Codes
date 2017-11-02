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
		temp->next = temp;
		first = temp;
		return first;
	}
	node *temp = first;

	while(temp->next != first)
	{
		temp = temp->next;
	}

	temp->next = (node *)malloc(sizeof(node));
	temp = temp->next;
	temp->data = x;
	temp->next = first;
	return first;
}

node * insertFront(node *first, int x)
{
	if(isEmpty(first))
	{
		return insertRear(first,x);
	}
	node *temp = first;

	while(temp->next != first)
	{
		temp = temp->next;
	}
	node *temp2 = (node *)malloc(sizeof(node));
	temp2->data = x;
	temp2->next = first;
	temp->next = temp2;	
	return temp2;
}

node * delete(node *first, int x)
{
	node *prev = NULL;
	node * temp = first;
	if(isEmpty(first))
		return NULL;
	while(temp->next != first && temp->data != x)
	{
		prev = temp;
		temp = temp->next;
	}

	if(temp->data == x)
	{
		prev->next = temp->next;
		free(temp);
	}
	else if(temp->next->data = x)
	{
		prev = prev->next;
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
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("%d -> ",temp->data);
	printf("end\n");
}