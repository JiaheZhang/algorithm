#include<iostream>
#include<malloc.h>
using namespace std;

template<typename elemType>
struct LNode
{
	elemType date;
	LNode *next;
	
};

template<typename elemType>
class NodeLink
{
	public:
		NodeLink();
		NodeLink(NodeLink<elemType> &);
		//void creat(int number);
		int getLength(void) const;
		void display(void) const;
		int search(elemType searchDate) const;
		bool deleteDate(elemType deleteDate);
		void insert(elemType insertDate);//稳定的插入 
		void sort(void) const;
	
	private:
		LNode<elemType> *head;
		int length;
};

template<typename elemType>
NodeLink<elemType>::NodeLink()
{
	head = new LNode<elemType>;
	head->next = NULL;
	this->length = 0;
}

template<typename elemType>
NodeLink<elemType>::NodeLink(NodeLink<elemType> &ref)
{
	
}

template<typename elemType>
int NodeLink<elemType>::getLength(void) const
{
	return this->length;
}


template<typename elemType>
void NodeLink<elemType>::display(void) const
{
	LNode<elemType> *p;
	p = head;
	cout<<"The length of node is "<<getLength()<<endl<<"The date is ";
	while(p->next != NULL)
	{
		p = p->next;
		cout<<p->date<<" ";
	}
	cout<<endl;
}

template<typename elemType>
int NodeLink<elemType>::search(elemType searchDate) const
{
	LNode<elemType> *p;
	p = head;
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

template<typename elemType>
bool NodeLink<elemType>::deleteDate(elemType deleteDate)
{
	LNode<elemType> *p,*freeP;
	p =  head;
	
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
			delete freeP;
			this->length--;
			return true;
		}
		else
		return false;
		
	}
}

template<typename elemType>
void NodeLink<elemType>::insert(elemType insertDate)//稳定的插入 
{
	LNode<elemType> *p,*temp;
	p = head;
	while(p->next != NULL)
	{
		if(p->next->date > insertDate)
			break;
		p = p->next;
	}
	temp = new LNode<elemType>;
	temp->date = insertDate;
	temp->next = p->next;
	p->next = temp;
	this->length++;
}

template<typename elemType>
void NodeLink<elemType>:: sort(void) const
{
	LNode<elemType> *p;
	p = head;
	elemType temp;
	int size = getLength();
	for(int i = 0;i < size;i++)
	{
		p = head;
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
	NodeLink<int> head;
	
	for(int i = 0;i < 20;i++)
	{
		head.insert(20 - i);
	}
	head.deleteDate(6);
	
	head.sort();
	head.display();
	
	cout<<head.search(10);
	return 0;
}
