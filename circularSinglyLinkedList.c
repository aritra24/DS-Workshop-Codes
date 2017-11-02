#include <stdio.h>
#include <stdlib.h>

#include "circularSinglyLinkedList.h"
int main()
{
	int x,y;
	node *first = NULL;
	while(1)
	{
		printf("Enter your choice. 1 for insertfront, 2 for insertrear, 3 \
for delete, 4 for display  anything else for exit\n");
		scanf("%d",&x);

		switch(x)
		{
			case 1: printf("Enter what to insert front \n"); scanf("%d",&y); first = insertFront(first,y);break;
			case 2: printf("Enter what to insert back \n"); scanf("%d",&y); first = insertRear(first,y);break;
			case 3: printf("delete what \n"); scanf("%d",&y); first = delete(first,y);break;
			case 4: display(first);break;
			default: exit(0);
		}

	}
	return 0;
}