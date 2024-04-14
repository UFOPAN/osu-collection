#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node {
	int id;//ѧ�� 
	char name[50];//����
	char sex[10];//�Ա�
	//char native_place[20];//����
	int age;//����
	struct Node* next;//ָ����
}node;

node list;//����


int saveFile(node* L);  //�����ļ�
int readFile(node* L);  //��ȡ�ļ�
void welcome();     //���˵�����
void addstu();      //����ѧ����Ϣ
void delstu(node* L);      //ɾ��ѧ����Ϣ
void fixstu(node* L);      //�޸�ѧ����Ϣ
void searchstu(node* L);      //��ѯѧ����Ϣ
void outputstu(node* L);      //���ѧ����Ϣ
void exitsystem();     //�˳�ϵͳ
void insertstu(node* L, node e);//����ѧ����Ϣ
node* searchstuByid(int id, node* L);//��ѧ�Ų�ѯ
node* searchstuByname(char name[], node* L);//��������ѯ
void deletestu(node* pr);//ɾ����Ϣ

int main()
{
	int choice = 0;
	readFile(&list);//��ȡ�ļ�
	while (1) {
		welcome();//���˵�����
		scanf("%d", &choice);
		switch (choice) {
		case 1:      //����ѧ����Ϣ
			addstu();
			break;
		case 2:      //ɾ��ѧ����Ϣ
			delstu(&list);
			break;
		case 3:      //�޸�ѧ����Ϣ
			fixstu(&list);
			break;
		case 4:      //��ѯѧ����Ϣ
			searchstu(&list);
			break;
		case 5:      //���ѧ����Ϣ
			outputstu(&list);
			break;
		case 0:      //�˳�ϵͳ
			exitsystem();
			break;
		}
		printf("�Ƿ�������������ǣ�1��/��0������");
		scanf("%d", &choice);
		if (choice == 0) {
			break;
		}
	}
	exitsystem();
	return 0;
}
void welcome() {
	system("cls");   //����
	printf("**************************\n");
	printf("***   ѧ��Ϣ����ϵͳ   ***\n");
	printf("**************************\n");
	printf("**   ����ѧ����Ϣ ---1  **\n");
	printf("**   ɾ��ѧ����Ϣ ---2  **\n");
	printf("**   �޸�ѧ����Ϣ ---3  **\n");
	printf("**   ��ѯѧ����Ϣ ---4  **\n");
	printf("**   ���ѧ����Ϣ ---5  **\n");
	printf("**     �˳�ϵͳ ---0    **\n");
	printf("�������Ӧ�Ĺ��ܼ������֣���\n");
}
void addstu()//����ѧ����Ϣ
{
	node st;
	printf("����������ѧ�������Ϣ\n");
	printf("ѧ��:");
	scanf("%d", &st.id);
	printf("����:");
	scanf("%s", st.name);
	printf("�Ա�:");
	scanf("%s", st.sex);
	printf("����:");
	scanf("%d", &st.age);

	insertstu(&list, st);//����ѧ����Ϣ
}
void insertstu(node* L, node e) //����ѧ����Ϣ
{
	//ͷ�巨
	node* h = L;
	node* s = (node*)malloc(sizeof(node));
	*s = e;
	s->next = h->next;
	h->next = s;
	saveFile(L);
}

void delstu(node* L) //ɾ��ѧ����Ϣ
{
	system("cls");
	int id;
	node* p;
	printf("������Ҫ��ѯ��ѧ��ѧ��:");
	scanf("%d", &id);
	node* st = searchstuByid(id, L);
	p = st;

	if (st == NULL) {
		printf("���޴���");
		return;
	}
	st = st->next;
	printf("______________________________\n");
	printf("ѧ��\t|����\t|�Ա�\t|����|\n");
	printf("______________________________\n");
	printf("%d|\t%s|\t%s|\t%d|\n", st->id, st->name, st->sex, st->age);
	printf("______________________________\n");

	deletestu(p);
	saveFile(L);
}
void deletestu(node* pr)//ɾ����Ϣ
{
	node* s = pr->next;

	pr->next = s->next;
	s->next = NULL;
	free(s);
}

void fixstu(node* L) //�޸�ѧ����Ϣ
{
	system("cls");
	int id,choice=-1;
	printf("������Ҫ��ѯ��ѧ��ѧ��:");
	scanf("%d", &id);
	node* st = searchstuByid(id, L);
	if (st == NULL) {
		printf("���޴���");
		return;
	}
	st = st->next;
	
	while (1) {
		system("cls");
		printf("______________________________\n");
		printf("ѧ��\t|����\t|�Ա�\t|����|\n");
		printf("______________________________\n");
		printf("%d|\t%s|\t%s|\t%d|\n", st->id, st->name, st->sex, st->age);
		printf("______________________________\n");
		printf("�޸�����---------1\n");
		printf("�޸��Ա�---------2\n");
		printf("�޸�����---------3\n");
		printf("������Ҫ�޸ĵ���Ϣ:");
		scanf("%d", &choice);
		
		switch (choice) {
		case 1:
			printf("����������:");
			scanf("%s", st->name);
			break;
		case 2:
			printf("�������Ա�:");
			scanf("%s", st->sex);
			break;
		case 3:printf("����������:");
			scanf("%d", &st->age);
			break;
		}
		printf("�Ƿ�����޸�?��yes(1)/no(0)��:");
		scanf("%d", &choice);
		if (choice == 0) {
			break;
		}
	}
	printf("______________________________\n");
	printf("ѧ��\t|����\t|�Ա�\t|����|\n");
	printf("______________________________\n");
	printf("%d|\t%s|\t%s|\t%d|\n", st->id, st->name, st->sex, st->age);
	printf("______________________________\n");
	saveFile(L);
}
void searchstu(node* L)//��ѯѧ����Ϣ
{
	system("cls");
	int choice = 0, id;
	node* st;
	char name[50];
	printf("��ѧ�Ų�ѯ----1\n");
	printf("��������ѯ----2\n");
	printf("��ѡ���ѯ��ʽ:");
	scanf("%d", &choice);
	if (choice == 1)
	{
		printf("������Ҫ��ѯ��ѧ��:");
		scanf("%d", &id);
		st = searchstuByid(id, L);
		if (st == NULL)
		{
			printf("���޴���\n");
		}
		else {
			st = st->next;
			printf("______________________________\n");
			printf("ѧ��\t|����\t|�Ա�\t|����|\n");
			printf("______________________________\n");
			printf("%d|\t%s|\t%s|\t%d|\n", st->id, st->name, st->sex, st->age);
			printf("______________________________\n");
		}
	}
	else if (choice == 2)
	{
		printf("������Ҫ��ѯ������:");
		scanf("%s", name);
		st = searchstuByname(name, L);
		if (st == NULL)
		{
			printf("���޴���\n");
		}
		else {
			st = st->next;
			printf("______________________________\n");
			printf("ѧ��\t|����\t|�Ա�\t|����|\n");
			printf("______________________________\n");
			printf("%d|\t%s|\t%s|\t%d|\n", st->id, st->name, st->sex, st->age);
			printf("______________________________\n");
		}
	}

}
node* searchstuByid(int id, node* L)//��ѧ�Ų�ѯ
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
node* searchstuByname(char name[], node* L)//��������ѯ
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
void outputstu(node* L)//���ѧ����Ϣ
{
	node* p = L->next;
	printf("______________________________\n");
	printf("ѧ��\t|����\t|�Ա�\t|����|\n");
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

void exitsystem()//�˳�ϵͳ
{
	system("cls");
	printf("��ӭ�´�ʹ��~~\n");
	exit(0);
}
int readFile(node* L) //��ȡ�ļ�
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
int saveFile(node* L)//�����ļ�
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
