#include<iostream>
#include<malloc.h>
using namespace std;

typedef int elemType;

typedef struct L
{
	elemType date;
	struct L *next;
	
}LNode;

LNode* creat(int number)
{
	LNode *head,*p,*temp;
	head = (LNode*)malloc(sizeof(LNode));
	//head->date = number;//save the length if elemType is "int"
	head->next = NULL;
	
	p = head;
	
	for(int i = 0;i < number;i++)
	{
		temp = (LNode*)malloc(sizeof(LNode));
		scanf("%d",&(temp->date));//
		p->next = temp;
		p = temp;
	}
	p->next = NULL;
	
	return head;
	
}

int length(LNode* lengthL)
{
	int size = 0;
	LNode* p;
	p = lengthL;
	while(p->next != NULL)
	{
		size++;
		p = p->next;
	}
	return size;
}

void display(LNode* disL)
{
	LNode* p;
	p = disL;
	cout<<"The length of node is "<<length(p)<<endl<<"The date is ";
	while(p->next != NULL)
	{
		p = p->next;
		cout<<p->date<<" ";
	}
	cout<<endl;
}

int search(LNode* searchL,elemType searchDate)
{
	LNode* p;
	p = searchL;
	int k = 0;
	while(p->next != NULL && p->date != searchDate)
	{
		k++;
		p = p->next;
	}
	if(p->next == NULL)
		return 0;
	else
		return k;
}

bool delete(LNode* deleteL,elemType deleteDate)
{
	
}

int insert(LNode* insertL,elemType insertDate)
{
	
}

void sort(LNode* sortL)
{
	
}



int main()
{
	LNode* head;
	head = creat(10);
	display(head);
	cout<<search(head,5);
	return 0;
}
