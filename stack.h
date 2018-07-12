
typedef struct s{
	void *elements;		//pointer to the stack
	int elementSize;	//size of each element in the stack
	int stackSize;		//current size of the stack
	int stackCapacity;	//capac ity of the stack
}stack;

void stackNew(stack *s, int elementSize, int stackCapacity);
void stackFree(stack*s);
bool stackEmpty(const stack *s);
bool stackFull(const stack *s);
void stackPush(stack *s, const void *elementAddr);
void stackPop(stack *s, void *elementAddr);
