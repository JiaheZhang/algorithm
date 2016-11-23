#include<iostream>
#include<stdlib.h>
using namespace std;
const int NUMBER = 20;
const int INF = 200;
int A[NUMBER];

int leftMaxKey = 0;
int rightMaxKey = 0;
int possLeftMaxKey = 0;
int possRightMaxKey = 0;
int possLeftMaxKey2 = 0;
int possRightMaxKey2 = 0;


int maxValue = 0;
int leftKey = 0;
int rightKey = 0;

int findMaxCross(int left,int right)
{
	int mid = (left + right) / 2;
	int leftSum,rightSum;
	int sum = 0;
	leftSum = -INF;
	
	for(int i = mid; i >= left; i--)
	{
		sum += A[i];
		if(sum > leftSum)
		{
			leftSum = sum;
			possLeftMaxKey = i;
		}
	}
	
	rightSum = -INF;
	sum = 0;
	for(int i = mid + 1;i <= right;i++)
	{
		sum +=A[i];
		if(sum > rightSum)
		{
			rightSum = sum;
			possRightMaxKey = i;
		}
	}
	return (leftSum + rightSum);
}
int findMaxAll(int left,int right)
{
	
	if(left == right)
	{
		possLeftMaxKey2 = left;
		possRightMaxKey2 = left;
		return A[left];
	}
	int mid = (left + right) / 2;
	int maybeMaxValueLeft = 0;
	int maybeMaxValueRight = 0;
	int maybeMaxCross = 0;
	maybeMaxValueLeft = findMaxAll(left,mid);
	maybeMaxValueRight = findMaxAll(mid + 1,right);
	maybeMaxCross = findMaxCross(left,right);
	
	if(maybeMaxCross > maybeMaxValueLeft && maybeMaxCross > maybeMaxValueRight)
	{
		leftKey = possLeftMaxKey;
		rightKey = possRightMaxKey;
		return maybeMaxCross;
	}
	else
	{
		if(maybeMaxValueLeft > maybeMaxCross && maybeMaxValueLeft > maybeMaxValueRight)
		{
			leftKey = possLeftMaxKey2;
			rightKey = possRightMaxKey2;
			return maybeMaxValueLeft;
		}
		else
		{
			leftKey = possLeftMaxKey2;
			rightKey = possRightMaxKey2;
			return maybeMaxValueRight;
		}
	}
	
}

int main()
{
	int max;
	for(int i = 0;i < NUMBER; i++)
	{
		A[i] = rand() % 100 - 50;
		cout<<A[i]<<endl;
	}
	
	max = findMaxAll(0,NUMBER);
	
	cout<<"between "<<leftKey + 1<<" and " <<rightKey + 1<<" is "<<max;
	
	return 0;
}
