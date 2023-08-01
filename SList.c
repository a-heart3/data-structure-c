#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE {
	int data;
	struct NODE *next;
}NODE;

typedef struct SList {
	int size;
	char name[50];
	NODE *setinal;
}SList;

void InitList (SList *L, char name[]) {
	L->size = 0;
	strcpy(L->name, name);
	L->setinal = malloc(sizeof(NODE));
	if(L->setinal == NULL){
		printf("woqiao");
	}
	else{
		printf("6666");
	}
	L->setinal->data = 100;
}

int main(void){
	char name[50] = "ax";
	SList l1;
	InitList(&l1, name);
	if (l1.setinal == NULL) {
		printf("wtf");
		return 123;
	}
	printf("%c %c %d %d\n",l1.name[0], l1.name[1], l1.size, l1.setinal->data);

	return 0;
}
