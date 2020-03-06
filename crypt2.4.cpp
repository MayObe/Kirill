#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "crypt1.2.h"
#include "crypt1.3.h"
#include "crypto1.1.h"
#include "crypt2.2.h"
using namespace std;
int gcd(int x, int y)
{
    return y ? gcd(y,x%y) : x;
}
void RSA (long long int m )
{
	srand ( time(NULL) );
	long long int N[2],P[2],Q[2],f[2],d[2],e,c[2],M;
	for (int i=0; i<2; i++)
	{
		Q[i]=2+rand()%80;
	    P[i]=2+
		rand()%30;
		while (pop(Q[i])!=1)
		{
			Q[i]=2+rand()%80;
		}
		while (pop(P[i])!=1 or P[i]==Q[i])
		{
			P[i]=2+rand()%80;
		}	
		f[i]=(P[i]-1)*(Q[i]-1);
		N[i]=P[i]*Q[i];
	}
	if (N[1]<m) return ;
	for (int i=0; i<2; i++)
	{
		d[i]=1+rand()%(f[i]-1);
	    while (gcd(f[i],d[i])!=1)
	    {
		    d[i]=1+rand()%(f[i]-1);
	    }
	    c[i]=Evkl(d[i],f[i],1);
	    if (c[i]<0)
	    {
	    	c[i]+=f[i];
		}
	}
	if (d[1]>f[1]) return ;
	e=prov(m,d[1],N[1]);
	M=prov(e,c[1],N[1]);
	cout<<"M "<<M<<endl;
	cout<<"f "<<f[1]<<endl;
	cout<<"d "<<d[1]<<endl;
	cout<<"N "<<N[1]<<endl;
	cout<<"e "<<e<<endl;
	cout<<"c "<<c[1]<<endl;
	cout<<"P "<<P[1]<<endl;
	cout<<"Q "<<Q[1]<<endl;
	
}

	


