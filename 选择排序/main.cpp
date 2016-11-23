#include<iostream>
#include<stdlib.h>

const int NUMBER_ = 30;
using namespace std;
 int main()
 {
 	int A[NUMBER_];
 	int i,j;
 	int k = 0;
 	int temp;
 	for(i = 0;i < NUMBER_;i++)
 	{
 		A[i] = rand() % 100;
 	}
 	
 	for(i = 0;i < NUMBER_; i++)
 	{
 		k = i;
 		for(j = i;j < NUMBER_;j++)
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
 	
 	for(i = 0;i < NUMBER_ ;i++)
	 {
	 	cout<<A[i]<<endl;
	 }
 	
 	return 0;
 }
