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
	LNode *p;
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

bool deleteDate(LNode* deleteL,elemType deleteDate)
{
	LNode *p,*freeP;
	p =  deleteL;
	
	while(p->next != NULL)
	{
		
		if(p->next->date >= deleteDate)
			break;
		p = p->next;
	}
	if(p->next == NULL)
	{
		return false;
	}
	else
	{
		if(p->next->date == deleteDate)
		{
			freeP = p->next;
			p->next = p->next->next;
			free(freeP);
			return true;
		}
		else
		return false;
		
	}
}

void insert(LNode* insertL,elemType insertDate)//ÎÈ¶¨µÄ²åÈë 
{
	LNode *p,*temp;
	p = insertL;
	while(p->next != NULL)
	{
		if(p->next->date > insertDate)
			break;
		p = p->next;
	}
	temp = (LNode*)malloc(sizeof(LNode));
	temp->date = insertDate;
	temp->next = p->next;
	p->next = temp;
}

void sort(LNode* sortL)
{
	LNode *p;
	p = sortL;
	elemType temp;
	int size = length(p);
	for(int i = 0;i < size;i++)
	{
		p = sortL;
		for(int j = i;j < size - 1;j++)
		{
			p = p->next;
			if(p->next->date < p->date)
			{
				temp = p->date;
				p->date = p->next->date;
				p->next->date = temp;
			}
		}
		
	}
}



int main()
{
	LNode* head;
	head = creat(10);
	insert(head,10);
	deleteDate(head,5);
	
	sort(head);
	display(head);
	
	cout<<search(head,10);
	return 0;
}
