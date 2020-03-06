#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "crypt1.2.h"
#include "crypto1.1.h"
#include "crypt2.2.h"
using namespace std;
struct Kart
{
	int val;
	int suit;
};
int gcd(int x, int y)
{
    return y ? gcd(y,x%y) : x;
}
void GenCD(int P, int *C, int *D, int N)
{
	for ( int i=0; i<N; i++)
	{
		C[i]=2+rand()%(P-1);
		while (gcd(C[i],P-1)!=1)
		{
			C[i]=2+rand()%(P-1);
		}
		while (i>0 and C[i]==C[0])
		{
			C[i]=2+rand()%(P-1);
			while (gcd(C[i],P)!=1)
			{
				C[i]=2+rand()%(P-1);
			}
		}
		D[i]=Evkl(C[i],P-1,1);
		if( D[i]<0)
		{
			D[i]+=(P-1);
		}
	}

}
void GenN(int P, Kart *A, int N)
{
	int k(0),F;
	bool flag=false;
	for (int i=1; i<5; i ++)
	{
		for (int j= 0; j<13; j++)
		{
			A[k].suit=i;
			k++;
		}
	}
	for (int i=0; i<N; i++)
	{
		A[i].val=2+rand()%(P-1);
	}
	while (true)
	{
		flag =true;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(A[i].val==A[j].val && i!=j)
				{
					A[j].val=2+rand()%(P-1);
					flag = false;
				}
			}
		}
		if (flag)
		{
			break;
		}
	}
}
void GenU(int P,int C, int D, Kart *  A,Kart * B, int N)
{
	for (int i =0; i<N; i++)
	{
		B[i].val=prov(A[i].val,C,P);
		B[i].suit=A[i].suit;


	}
}
void razGenU ( int P, int D, Kart * A, int N)
{
	for (int i=0; i<N; i++)
	{
		A[i].val=prov(A[i].val,D,P);
	}
}
void GenV(int P,int C, int D, Kart * A,Kart * B, int N, int *n, int N1) // карты А
{
	for (int i=0; i<N1; i++)
	{
		n[i]=0+rand()%(N-1);
		while(i>0 and n[0]==n[i])
		{
			n[i]=0+rand()%(N-1);
		}
		B[i].val=A[n[i]].val;
		B[i].suit=A[n[i]].suit;
	}
	cout<<"Ошибки нет))"<<endl;
	cout<<"N "<<n[0]<<" "<<n[1]<<endl;
	for ( int i = 0; i<N; i++)
	{
		A[i].val=prov(A[i].val,50,15);
		cout<<"Тут чет нито "<<endl;
	}
	cout<<"ddrov "<<endl;
}
Kart genW1 (int P, int C, Kart * A, Kart * B, int *n1, int J)
{
	B[J].val=prov(A[n1[J]].val,C,P);
	B[J].suit=A[n1[J]].suit;
	return B[J];
}
void GenW (int P,int C, int D, int N, int *n, int *n1, int N1)
{
	cout<<"Потом тут"<<endl;
	for (int i=0; i<N1; i++)
	{
		n1[i]=0+rand()%(N-1);
		while(i>0 and (n1[0]==n1[i] or n1[i]==n[0] or n1[i]==n[i] ))
		{
			n[i]=0+rand()%(N-1);
		}
		while (i==0 and (n1[i]==n[i] or n1[i]==n[1]))
		{
			n[i]=0+rand()%(N-1);
		}
	}
	cout<<"И тут "<<endl;
}
void gevZ(int P,int C, int D, Kart * A) // карты Б
{
	A[0].val=prov(A[0].val,D,P);
	A[1].val=prov(A[1].val,D,P);
}
void MP()
{
	int p=100+rand()%500, C[2],D[2], mas1[2],mas2[2];
	Kart A[2], B[2], Stol[5],All[52],All1[52];
	while (pop(p)==0)
	{
		p=100+rand()%500;
	}
	GenCD(p,C,D,2);
	GenN(p, All, 52);
	GenU(p,C[0],D[0], All,All1,52);
	GenV(p,C[1],D[1],All1,A,52,mas1, 2);
	GenW(p,C[0], D[0],52, mas1, mas2,2);
	genW1 (p, D[0],All1,B, mas2,0);
	genW1 (p, D[0],All1,B, mas2,1);
	cout<<endl;
	gevZ(p,C[1],D[1],B);
/*
	cout<<"Исходная колода: "<<endl;
	for ( int i = 0; i<52; i++)
	{
		cout<<"Значение: "<<All[i].val<<" ";
		cout<<"Масть: "<<All[i].suit<<endl;
	}
	cout<<"Координаты а и б "<<endl;
	cout<<mas1[0]<<"  "<<mas1[1]<<endl;
	cout<<mas2[0]<<"  "<<mas2[1]<<endl;*/
	razGenU (p, D[0], A,2);
	/*cout<<"Карты а и б"<<endl;
	for ( int i = 0; i<2; i++)
	{
		cout<<"Значение: "<<A[i].val<<" ";
		cout<<"Масть: "<<A[i].suit<<endl;
	}
	for ( int i = 0; i<2; i++)
	{
		cout<<"Значение: "<<B[i].val<<" ";
		cout<<"Масть: "<<B[i].suit<<endl;
	}*/
	cout<<"P "<<p<<endl;
	for ( int i = 0; i<2; i++)
	{
		cout<<"C "<<C[i]<<endl;
		cout<<"D "<<D[i]<<endl;
	}
	cout<<endl;




}

