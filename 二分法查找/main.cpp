#include<iostream>
#include<stdlib.h>

const int NUMBER = 30;
using namespace std;
void f(int left,int right);
int date;
int where;
int A[NUMBER];
int i,j;
int k = 0;
int temp;
 int main()
 {
 	
 	for(i = 0;i < NUMBER;i++)
 	{
 		A[i] = rand() % 100;
 	}
 	
 	for(i = 0;i < NUMBER; i++)
 	{
 		k = i;
 		for(j = i;j < NUMBER;j++)
 		{
 			if(A[k] >= A[j])
 			{
 				k = j;
 			}
 		}
 		temp = A[k];
 		A[k] = A[i];
 		A[i] = temp;
 	}
 	
 	for(i = 0;i < NUMBER ;i++)
	{
	 	cout<<A[i]<<endl;
	}
	cout<<"Input date";
	cin>>date;
 	f(0,NUMBER);
 	cout<<"The "<<date<<" is at "<<where<<endl;
 	return 0;
 }
 void f(int left,int right)
 {
 	if(left == right)
 	{
 		where = -1;
 		return;
 	}
 	
 	int key = (left + right) / 2;
 	if(A[key] == date)
 	where = key;
 	else
 	{
 		if(A[key] > date)
 		f(left,key);
 		else
 		f(key + 1,right);
 	}
 }
