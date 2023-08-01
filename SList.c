#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*定义节点类型*/
typedef struct NODE {
	int data;
	struct NODE *next;
}NODE;

/*定义SList类型*/
typedef struct SList {
	int size;                               //SList 大小
	char name[50];                          //Description等信息
	NODE *last;                             //尾指针，用来做尾插法
	NODE *setinal;                          //头结点，为了使插入操作和删除操作统一（插入链表第一个结点和删除链表最后一个结点)
}SList;

/*初始化SList:
  1.注意SList要传入地址，否则对其的修改无效
  2.size初始化为0， name初始化为用户给的字符串
  3.设置头结点setinal
  4.初始时，尾结点==头结点
*/
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

/*求链表长度：直接返回记录的值即可，也可以用count便利，但较为麻烦 */
int Length (SList L) {
	return L.size;
}

/*按值查找元素
  1.遍历List,返回相同的值的位置
  2.这里并没有返回查找失败的情况，即值不存在的情况
  3.一个链表可能有多个相同的值，所以遍历完按照输出即可判断是否在List中
*/
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
        return 0;
}

/* 判断函数位置是否合法的函数 */
bool IsPosition (int size, int pos){
	if (pos < 1 || pos > size) {
		printf("error: wrong position!!!");
		return false;
	}
	return true;
}

NODE* Position (SList L, int pos) {
	NODE *p = L.setinal;
	while (pos > 0) {
		p = p->next;
		pos--;
	}
	return p;
}

/*按位查找List, 设置计数器记录查找了多少个元素即可
  1.用IsPosition函数判断位置是否合法
  2.返回查找到的值
*/
int GetElem(SList L, int pos) {

	if(!IsPosition(L.size, pos)){
		return -1;
	}
	NODE *p = Position(L, pos);

	printf("the %dth is %d\n", pos, p->data);
	return p->data;
}

/*头插法：实现链表的原地逆置*/
void AddFirst(SList* L, int e){
       NODE *s = malloc(sizeof(NODE));
       if (s == NULL) {
	       printf("error: allocate memory defeat");
       }
     //GetElem(*L, 3);
       s -> data = e;
       s -> next = L->setinal -> next;
       L->setinal -> next = s;
       L->size = L->size + 1;
}     

/*尾插法：按序创建链表
  1.设置尾指针
  2.要保证尾指针不丢失
*/
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

/*在某一个位置插入元素：
  1.用IsPosition函数判断位置是否合法
  2.查找至该元素的前一个位置
  3.判断是在尾部插入还是其它地方插入（尾部插入要更改last，这里可以用双循环链表优化）
  4.size要加一
*/
int Insert(SList *L, int pos, int e) {
	if(!IsPosition(L->size+1, pos)) {
		return -2;
	}
	if(pos == L->size + 1){
		AddLast(L, e);
	}

	NODE *p = Position(*L, pos - 1);
        NODE *s = malloc(sizeof(NODE));
	s->data = e;
	s->next = p->next;
	p->next = s;
	L->size = L->size + 1;
}

/*删除最后一个结点：
  1.要保证last指针不丢失,需要从头到尾遍历找到新的last，（可以用双链表优化）
*/
int DeleteLast(SList* L) {
	if (L->last == L->setinal) {
		printf("The list is empty!\n");
		return 1;
	}

	NODE* p = Position(*L, L->size - 1);
	L->last = p;
	p->next = NULL;
	L->size = L->size - 1;
	return 0;
}

/*删除表中任意一个结点
  1.用IsPosition函数判断位置是否合法
  2.找到要删除的前一个结点
  3.判断是否删除的是最后一个结点
  4.删除
*/
int Delete(SList* L, int pos) {
	if (!IsPosition(L->size, pos)){
		return -1;
	}
	if (pos == L->size) {
		DeleteLast(L);
	}

	NODE *p = Position(*L, pos - 1);
	NODE *s = p->next;
	p->next = p->next->next;
	L->size = L->size - 1;
	free(s);

	return 0;
}

/*输出list信息*/
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
	GetElem(l1, 3);


	PrintList(l1);
	DeleteLast(&l1);
	Delete(&l1, 1);
	
	PrintList(l1);
	return 0;
}
