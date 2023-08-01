#include <stdio.h>
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

int GetElm (AList L, int e) {
	for(int i = 0; i < L.size; i++) {
		if(L.list[i] == e) {
			printf("the %dth position is %d\n", i, e);
		}
	}

	return 0;
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
	PrintList(l);

	printf("%d\n", l.size);
	printf("%c %c\n", l.name[0], l.name[1]);



	return 0;
}
