#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;


int Evkl(int a, int b, int j)
{
	int U[3]={a,1,0}, V[3]={b,0,1}, T[3],q;

	while(V[0]!=0)
	{
		q=U[0]/V[0];
		T[0]=U[0]%V[0];
		T[1]=U[1]-q*V[1];
		T[2]=U[2]-q*V[2];

		for (int i=0; i<3; i++)
		{
			U[i]=V[i];
			V[i]=T[i];
		}
	}
	return U[j];
}
