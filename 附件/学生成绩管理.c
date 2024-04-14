#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node {
	int id;//学号 
	char name[50];//姓名
	char sex[10];//性别
	//char native_place[20];//籍贯
	int age;//年龄
	struct Node* next;//指针域
}node;

node list;//链表


int saveFile(node* L);  //保存文件
int readFile(node* L);  //读取文件
void welcome();     //主菜单界面
void addstu();      //增加学生信息
void delstu(node* L);      //删除学生信息
void fixstu(node* L);      //修改学生信息
void searchstu(node* L);      //查询学生信息
void outputstu(node* L);      //输出学生信息
void exitsystem();     //退出系统
void insertstu(node* L, node e);//插入学生信息
node* searchstuByid(int id, node* L);//按学号查询
node* searchstuByname(char name[], node* L);//按姓名查询
void deletestu(node* pr);//删除信息

int main()
{
	int choice = 0;
	readFile(&list);//读取文件
	while (1) {
		welcome();//主菜单界面
		scanf("%d", &choice);
		switch (choice) {
		case 1:      //增加学生信息
			addstu();
			break;
		case 2:      //删除学生信息
			delstu(&list);
			break;
		case 3:      //修改学生信息
			fixstu(&list);
			break;
		case 4:      //查询学生信息
			searchstu(&list);
			break;
		case 5:      //输出学生信息
			outputstu(&list);
			break;
		case 0:      //退出系统
			exitsystem();
			break;
		}
		printf("是否继续操作？（是（1）/否（0））：");
		scanf("%d", &choice);
		if (choice == 0) {
			break;
		}
	}
	exitsystem();
	return 0;
}
void welcome() {
	system("cls");   //清屏
	printf("**************************\n");
	printf("***   学生息管理系统   ***\n");
	printf("**************************\n");
	printf("**   增加学生信息 ---1  **\n");
	printf("**   删除学生信息 ---2  **\n");
	printf("**   修改学生信息 ---3  **\n");
	printf("**   查询学生信息 ---4  **\n");
	printf("**   输出学生信息 ---5  **\n");
	printf("**     退出系统 ---0    **\n");
	printf("请输入对应的功能键（数字）：\n");
}
void addstu()//增加学生信息
{
	node st;
	printf("请输入新增学生相关信息\n");
	printf("学号:");
	scanf("%d", &st.id);
	printf("姓名:");
	scanf("%s", st.name);
	printf("性别:");
	scanf("%s", st.sex);
	printf("年龄:");
	scanf("%d", &st.age);

	insertstu(&list, st);//插入学生信息
}
void insertstu(node* L, node e) //插入学生信息
{
	//头插法
	node* h = L;
	node* s = (node*)malloc(sizeof(node));
	*s = e;
	s->next = h->next;
	h->next = s;
	saveFile(L);
}

void delstu(node* L) //删除学生信息
{
	system("cls");
	int id;
	node* p;
	printf("请输入要查询的学生学号:");
	scanf("%d", &id);
	node* st = searchstuByid(id, L);
	p = st;

	if (st == NULL) {
		printf("查无此人");
		return;
	}
	st = st->next;
	printf("______________________________\n");
	printf("学号\t|姓名\t|性别\t|年龄|\n");
	printf("______________________________\n");
	printf("%d|\t%s|\t%s|\t%d|\n", st->id, st->name, st->sex, st->age);
	printf("______________________________\n");

	deletestu(p);
	saveFile(L);
}
void deletestu(node* pr)//删除信息
{
	node* s = pr->next;

	pr->next = s->next;
	s->next = NULL;
	free(s);
}

void fixstu(node* L) //修改学生信息
{
	system("cls");
	int id,choice=-1;
	printf("请输入要查询的学生学号:");
	scanf("%d", &id);
	node* st = searchstuByid(id, L);
	if (st == NULL) {
		printf("查无此人");
		return;
	}
	st = st->next;
	
	while (1) {
		system("cls");
		printf("______________________________\n");
		printf("学号\t|姓名\t|性别\t|年龄|\n");
		printf("______________________________\n");
		printf("%d|\t%s|\t%s|\t%d|\n", st->id, st->name, st->sex, st->age);
		printf("______________________________\n");
		printf("修改姓名---------1\n");
		printf("修改性别---------2\n");
		printf("修改年龄---------3\n");
		printf("请输入要修改的信息:");
		scanf("%d", &choice);
		
		switch (choice) {
		case 1:
			printf("请输入姓名:");
			scanf("%s", st->name);
			break;
		case 2:
			printf("请输入性别:");
			scanf("%s", st->sex);
			break;
		case 3:printf("请输入年龄:");
			scanf("%d", &st->age);
			break;
		}
		printf("是否继续修改?（yes(1)/no(0)）:");
		scanf("%d", &choice);
		if (choice == 0) {
			break;
		}
	}
	printf("______________________________\n");
	printf("学号\t|姓名\t|性别\t|年龄|\n");
	printf("______________________________\n");
	printf("%d|\t%s|\t%s|\t%d|\n", st->id, st->name, st->sex, st->age);
	printf("______________________________\n");
	saveFile(L);
}
void searchstu(node* L)//查询学生信息
{
	system("cls");
	int choice = 0, id;
	node* st;
	char name[50];
	printf("按学号查询----1\n");
	printf("按姓名查询----2\n");
	printf("请选择查询方式:");
	scanf("%d", &choice);
	if (choice == 1)
	{
		printf("请输入要查询的学号:");
		scanf("%d", &id);
		st = searchstuByid(id, L);
		if (st == NULL)
		{
			printf("查无此人\n");
		}
		else {
			st = st->next;
			printf("______________________________\n");
			printf("学号\t|姓名\t|性别\t|年龄|\n");
			printf("______________________________\n");
			printf("%d|\t%s|\t%s|\t%d|\n", st->id, st->name, st->sex, st->age);
			printf("______________________________\n");
		}
	}
	else if (choice == 2)
	{
		printf("请输入要查询的姓名:");
		scanf("%s", name);
		st = searchstuByname(name, L);
		if (st == NULL)
		{
			printf("查无此人\n");
		}
		else {
			st = st->next;
			printf("______________________________\n");
			printf("学号\t|姓名\t|性别\t|年龄|\n");
			printf("______________________________\n");
			printf("%d|\t%s|\t%s|\t%d|\n", st->id, st->name, st->sex, st->age);
			printf("______________________________\n");
		}
	}

}
node* searchstuByid(int id, node* L)//按学号查询
{
	node* p = L;
	while (p->next != NULL)
	{
		if (p->next->id == id) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}
node* searchstuByname(char name[], node* L)//按姓名查询
{
	node* p = L;
	while (p->next != NULL)
	{
		if (strcmp(name, p->next->name) == 0) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}
void outputstu(node* L)//输出学生信息
{
	node* p = L->next;
	printf("______________________________\n");
	printf("学号\t|姓名\t|性别\t|年龄|\n");
	printf("______________________________\n");
	if (p != NULL) {

		while (p != NULL)
		{
			printf("%d|\t%s|\t%s|\t%d|\n", p->id, p->name, p->sex, p->age);
			printf("______________________________\n");
			p = p->next;
		}
	}
}

void exitsystem()//退出系统
{
	system("cls");
	printf("欢迎下次使用~~\n");
	exit(0);
}
int readFile(node* L) //读取文件
{
	FILE* fpr = fopen("data.txt", "r");
	node st;
	node* s;
	node* t = L;
	if (fpr == NULL) {
		return 0;
	}
	else {
		while (fscanf(fpr, "%d %s %s %d", &st.id, st.name, st.sex, &st.age) != EOF) {
			s = (node*)malloc(sizeof(node));
			*s = st;
			t->next = s;
			t = s;
			t->next = NULL;
		}
	}
	return 1;
}
int saveFile(node* L)//保存文件
{
	FILE* fpw = fopen("data.txt", "w");
	if (fpw == NULL)
	{
		return 0;
	}
	node* p = L->next;
	while (p != NULL) {
		fprintf(fpw,"%d %s %s %d\n", p->id, p->name, p->sex, p->age);
		p = p->next;
	}
	return 1;
}
