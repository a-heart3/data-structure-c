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
	NODE *last;
	NODE *setinal;
}SList;

void InitList (SList *L, char name[]) {
	L->size = 0;
	strcpy(L->name, name);
	L->setinal = malloc(sizeof(NODE));
	if(L->setinal == NULL){
		printf("error: poit null, segement overflow!!!");
	}
	L->setinal->data = -1;
	L->setinal->next = NULL;
	L->last = L->setinal;
}

int Length (SList L) {
	return L.size;
}

int LocateElem(SList L, int e){
	NODE *p = L.setinal->next;
	int count = 1;
	while (p) {
		if (p->data == e) {
			printf("LocateElem success, e is in position %d", count);
		}
		p = p->next;
		count ++;
	}
}

int GetElem(SList L, int pos) {
	int position = pos;
	NODE *p = L.setinal->next;
	while (p && pos > 0) {
		p = p->next;
		pos--;
	}
	if(p == NULL || pos > 0) {
		printf("error: wrong position");
		return -1;
	}
	printf("the %dth element in list is %d\n",position, p->data);

}

/* use AddFirst to reverse the List*/
void AddFirst(SList* L, int e){
       NODE *s = malloc(sizeof(NODE));
       if (s == NULL) {
	       printf("error: allocate memory defeat");
       }
       s -> data = e;
       s -> next = L->setinal -> next;
       L->setinal -> next = s;
       L->size = L->size + 1;
}     

/*execute insert at last, use rear, remember:setinal just like a node*/
void AddLast(SList* L, int e) {
	NODE *s = malloc(sizeof(NODE));
	if(s == NULL) {
		printf("error: allocate memory defeat");
	}
	s -> data = e;
	s -> next = NULL;
	L -> last -> next = s;
	L -> last = s;
	L -> size = L -> size + 1;
}

int Insert(SList *L, int pos, int e) {
	pos = pos - 1;
	NODE *p = L->setinal;
	while (p && pos > 0) {
		p = p->next;
		pos--;
	}
	if (pos > 0 || p == NULL) {
		printf("error: the insert position illegal\n");
		return -1;
	}

	if (p->next == NULL) {
		AddLast(L, e);
	}
	else{
		NODE *s = malloc(sizeof(NODE));
		s->data = e;
	        s->next = p->next;
	        p->next = s;
	        L->size = L->size + 1;

	}
}

int DeleteLast(SList* L) {
	if (L->last == L->setinal) {
		printf("The list is empty!\n");
		return 1;
	}

	NODE* p = L->setinal;
	while (p->next != L->last) {
		p = p->next;
	}
	L->last = p;
	p->next = NULL;
	L->size = L->size - 1;
	return 0;
}

int Delete(SList* L, int pos) {
	pos--;
	NODE *p = L->setinal->next;
	while (p && pos > 0) {
		p = p->next;
		pos--;
	}
	if(!p || !p->next || pos > 0) {
		printf("error: delete postion is illegle\n");
		return -1;
	}
	if (L->last == p->next) {
		DeleteLast(L);
	}
	else {
		NODE *s = p->next;
		p->next = p->next->next;
		L->size = L->size - 1;
		free(s);
	}

	return 0;
}

void PrintList(SList L) {
	printf("your list name is:");
	for (int i = 0; L.name[i] != '\0'; i++) {
		printf("%c", L.name[i]);
	}
	printf("\n");

	printf("your list length is: %d\n", L.size);

	NODE *p = L.setinal->next;
	while(p->next) {
		printf("%d --> ", p->data);
	        p = p->next;	
	}
	printf("%d\n", p->data);
}

int main(void){
	char name[50] = "ax";
	SList l1;
	InitList(&l1, name);
	AddLast(&l1, 200);
	AddLast(&l1, 300);
	Insert(&l1, 2, 500);
	Insert(&l1, 2,1000);
	DeleteLast(&l1);
	Delete(&l1, 6);
	Delete(&l1, 1);


	PrintList(l1);
	
	return 0;
}
