#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;




void dec2bin(int num, int A[])
{
	int i=0;
	while (num!=0 )
	{

		if  (num%2==0)
		{
			A[i]=0;
		}
		else
		{
			A[i]=1;
		}

		num=num/2;
		i++;
	}
}
void reverse (int A[], int N)
{
	int temp;
	for ( int i=0; i<N/2; i++)
	{
		temp=A[i];
		A[i]=A[N-i-1];
		A[N-i-1]=temp;
	}
}

int prov(int a, int x,int p)
{
	int *A= new int[0];
	int N=log2(x)+1;
	dec2bin(x,A);
	for ( int i=0; i<30; i++)
	{
		if ((pow(2,i)==x))
		{
			N+=1;
		}
	}
	int y=1;
	int s=a;
	for(int i=0; i<N; i++)
	{
		if(A[i]==1)
		{
			y=(y*s)%p;
		}
		s=(s*s)%p;
	}
	return y;
}


