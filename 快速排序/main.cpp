#include<iostream>
#include<stdlib.h> 
using namespace std;
const int NUMBER = 500;

int randSelectKey(int p[],int l,int r)
{
	int temp = 0;
	int randKey = (rand() % (r - l + 1)) + l;
	
	temp = p[randKey];
	p[randKey] = p[r];
	p[r] = temp;
	
	int valueKey = p[r];
	int j = l - 1;
	
	for(int i = l;i < r;i++)
	{
		if(p[i] <= valueKey)
		{
			j++;
			temp = p[j];
			p[j] = p[i];
			p[i] = temp;
		}
	}
	temp = p[j + 1];
	p[j + 1] = valueKey;
	p[r] = temp;
	return (j + 1);
}

void quickSelect(int p[],int l,int r)
{
	if(l < r)
	{
		int q = 0;
		q = randSelectKey(p,l,r);
		quickSelect(p,l,q - 1);
		quickSelect(p,q + 1,r);
	}
}
int main()
{
	int A[NUMBER];
	for(int i = 0;i < NUMBER; i++)
	{
		A[i] = rand() % 1000;
		cout<<A[i]<<endl;
	}
	cout<<endl;
	
	quickSelect(A,0,NUMBER - 1);
	for(int i = 0;i < NUMBER; i++)
	{
		cout<<A[i]<<endl;
	}

	return 0;
} 

