#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 100              //capacity of stack 100

typedef struct Stack {
	char name[50];       //description of stack
	int size;            
	int top;             //the top pointer of stack
	int base;            //the base pointer of stack
	int a[Max];          //stack
}Stack;

/*use to init the stack
 * top = -1
 * base = 0
*/
int Init_Stack (Stack* st, char name[]) {
	int i = 0;
	while (name[i] != '\0') {
		st->name[i] = name[i];
		i++;
	}
	st->name[i] = '\0';
	st->size = 0;
	st->top = -1;
	st->base = 0;

	return 0;
}	

/*use to judge if a stack is empty or full*/
int is_Empty (Stack st) {
	if (st.size == 0) {
		printf("error: the stack is null!!!\n");
		return 1;
	}
	
	return 0;            
}

int is_Full (Stack st) {
        if (st.size == 100) {
		printf("error: the stack has already full!!!\n");
		return 2;
	}

	return 0;
}

int Push (Stack* st, int e) {
	if (is_Full(*st)) {
		return 2;
	}

	st->a[++st->top] = e;
	st->size += 1;
	
	return 0;
}	

int Pop (Stack* st) {
	int e = 0;
	if (is_Empty(*st)) {
		return 1;
	}

	st->size -= 1;
	return st->a[st->top--];
}

int GetElem (Stack st) {
	if (is_Empty(st)) {
		return 1;
	}

	printf("the top of the stack is %d\n", st.a[st.top]);
	return st.a[st.top];
}

/*use to print the information of Stack*/
int print_Stack (Stack st) {
	int i = 0;
	printf("the name of stack is: ");
	while (st.name[i] != '\0') {
		printf("%c", st.name[i]);
		i++;
	}
	printf("\nthe length of stack is: %d\n", st.size);
	printf("the top is: %d\n", st.top);
	printf("the base is: %d\n", st.base);
	printf("the stack is: ");
	if (is_Empty(st)) {
		printf("null\n");
		return 1;              //code 1 represent stack is empty
	}
	for (i=0; i<=st.size-2; i++) {
		printf("%d-->", st.a[i]);
	}
	printf("%d\n", st.a[i]);

	return 0;
}

int main (void) {
	Stack s;
	Init_Stack (&s, "ax");
	Push (&s, 12220);
	Push (&s, 22500);
	GetElem(s);
	print_Stack(s);

	Pop (&s);
	print_Stack(s);



	return 0;
}

