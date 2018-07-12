#include <stdio.h>
#include <stdbool.h>

#include "stack.h"

int main(void)
{
	int val;
	int capacity = 5;
	stack intStack;

	stackNew(&intStack,sizeof(int),capacity);
	for(val = 0; val < 6; val++)
		stackPush(&intStack, &val);

	while(!stackEmpty(&intStack)) 
	{
		stackPop(&intStack,&val);
		printf("Popped %d\n",val);
	}	
	stackFree(&intStack);
}
