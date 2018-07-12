#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "stack.h"

void stackNew(stack *s, int elementSize, int stackCapacity)
{
	assert(elementSize > 0);
	s->elementSize = elementSize;
	s->stackSize = 0;
	s->stackCapacity = stackCapacity;
	s->elements = malloc(stackCapacity*elementSize);
	assert(s->elements != NULL);
}

void stackFree(stack *s)
{
	free(s->elements);
}	

bool stackEmpty(const stack *s)
{
	return s->stackSize == 0;
}

bool stackFull(const stack*s)
{
	return s->stackSize == s->stackCapacity;
}

void stackPush(stack *s, const void *elementAddr)
{
	void *stackAddr;
	
	if(stackFull(s))
	{
		printf("Stack Full\n");
		return;
	}

	stackAddr = (char*)s->elements + (s->stackSize * s->elementSize);
	memcpy(stackAddr, elementAddr, s->elementSize);
	s->stackSize++;
}

void stackPop(stack *s, void *elementAddr)
{
	const void *stackAddr;

	assert(!stackEmpty(s));
	s->stackSize--;
	stackAddr = (const char*) s->elements + (s->stackSize * s->elementSize);
	memcpy(elementAddr,stackAddr,s->elementSize);
}


