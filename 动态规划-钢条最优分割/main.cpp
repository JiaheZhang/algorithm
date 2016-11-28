#include<iostream>

using namespace std;

const int prize[11] = {0,1,5,8,9,10,17,17,20,24,30};
int maxArry[11] = {0,0,0,0,0,0,0,0,0,0,0};
int maxArry2[11] = {0,0,0,0,0,0,0,0,0,0,0};

int max(int a,int b)
{
	return a>b?a:b;
}

/***********top to down****************/
int getMax(int length,const int p[])
{
	if(maxArry[length] > 0)
		return maxArry[length];
	if(length == 0)
		return 0;
	
	
	int value = -1;
	
	for(int i = 1; i <= length;i++)
	{
		value = max(value,prize[i] + getMax(length - i,p));
	}
	maxArry[length] = value;//save the best value
	return value;
}
/***************dowm to top******************/
int getMax2(int length,const int p[])
{
	int value = -1;
	for(int i = 1;i <= length;i++)
	{
		value = -1;
		for(int j = 1;j <= i;j++)
		{
			value = max(value,p[j] + maxArry2[i - j]);
		}
		maxArry2[i] = value;
	}
	return value;
}

int main()
{
	int v = 0;
	int v2 = 0;
	v = getMax(10,prize);
	v2 = getMax2(10,prize);
	cout<<v<<endl;
	cout<<v2;
	
	return 0;
}
