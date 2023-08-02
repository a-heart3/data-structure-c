#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef struct AList {
	int list[MAX];
	int size;
	char name[50];
}AList;

int Init (AList *L, char name[]) {
	L->size = 0;
	for(int i = 0; name[i] != '\0'; i++) {
		L->name[i] = name[i];
	}

	return 0;
}

int Length (AList L) {
	return L.size;
}

int AddLast (AList* L, int e) {
	L->list[L->size] = e;
	L->size = L->size + 1;
}

int LocateElem (AList L, int e) {
	for(int i = 0; i < L.size; i++) {
		if(L.list[i] == e) {
			printf("the %dth position is %d\n", i, e);
		}
	}

	return 0;
}

bool IsPosition(int size, int pos) {
	if (pos > size || pos < 1) {
		printf("error: the position is error");
		return false;
	}
	return true;
}

int GetElem (AList L, int pos) {

	if (!IsPosition(L.size, pos)) {
		return -1;
	}

	return L.list[pos - 1];
}

int Insert (AList* L, int pos, int e) {
	if(!IsPosition(L->size + 1, pos)) {
		return -1;
	}

	if(L->size == MAX){
		printf("list is full\n");
		return -1;
	}

	for(int i = L->size; i >= pos; i--) {
		L->list[i] = L->list[i - 1];
	}

	L->list[pos - 1] = e;
	L->size = L->size + 1;

	return 1;
}

int Delete (AList *L, int pos) {
	if(L->size == 0) {
		printf("list is empty\n");
		return -1;
	}

	if(!IsPosition(L->size, pos)) {
		return -1;
	}

	int element = L->list[pos - 1];
	for(int i = pos - 1; i < L->size -1; i++) {
		L->list[i] = L->list[i + 1];
	}
	L->size = L->size - 1;

	return element;
}

int PrintList (AList L){
	printf("your list name is: ");
	for(int i = 0; L.name[i] != '\0'; i++) {
		printf("%c", L.name[i]);
	}
        printf("\nyour list length is: %d\n", L.size);

	if(L.size == 0) {
		printf("the list is empty!");
		return -1;
	}

	int j = 0;
	for (j; j < L.size - 1; j++) {
		printf("%d ", L.list[j]);
	}
	printf("%d\n", L.list[j]);
        
}

int main(void) {
	AList l;
	char name[50] = "ax";
	Init(&l, name);
	AddLast(&l, 100);
	AddLast(&l, 200);
	AddLast(&l, 300);
	Insert(&l, 4, 1000);
	Insert(&l, 2, 500);
	PrintList(l);
	Delete(&l, 2);
        printf("%d\n", GetElem(l, 2));
	PrintList(l);

	return 0;
}
