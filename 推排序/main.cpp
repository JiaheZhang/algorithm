#include<iostream>
#include<stdlib.h>
#define left(a) (a << 1)
#define right(a) ((a << 1) + 1)
#define parent(a) (a >> 1)

using namespace std;

const int NUMBER = 20;
int heapSize = NUMBER;

void maxHeap(int *p,int i)
{
	int l = left(i);
	int r = right(i); 
	int max;
	int temp;
	if(l <= heapSize && p[l - 1] > p[i - 1])
	{
		max = l;
	}
	else
	{
		max = i;
	}
	
	if(r <= heapSize && p[r - 1] > p[max -1])
	{
		max = r;
	}
	if(max != i)
	{
		temp = p[i - 1];
		p[i - 1] = p[max - 1];
		p[max - 1] = temp;
		maxHeap(p,max);
	}
}

void buildHeap(int *p)
{
	for(int i = heapSize / 2;i > 0;i--)
	{
		maxHeap(p,i);
	}
}
void sortHeap(int *p)
{
	int temp = 0;
	for(int i = NUMBER;i > 0;i--)
	{
		temp = p[i - 1];
		p[i - 1] = p[0];
		p[0] = temp;
		heapSize--;
		maxHeap(p,1); 
	}
}

int main()
{
	int A[NUMBER];
	for(int i = 0;i < NUMBER; i++)
	{
		A[i] = rand() % 100;
		cout<<A[i]<<endl;
	}
	cout<<endl;
	
	
	buildHeap(A);
	for(int i = 0;i < NUMBER; i++)
	{
		cout<<A[i]<<endl;
	}
	cout<<endl;
	
	sortHeap(A);
	for(int i = 0;i < NUMBER; i++)
	{
		cout<<A[i]<<endl;
	}
	

	return 0;
} 
