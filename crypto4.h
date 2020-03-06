#ifndef crypto4
#define crypto4
struct Kart
{
	int val;
	int suit;	
};
int gcd(int x, int y);
void GenCD(int P, int *C, int *D, int N);
void GenN(int P, Kart *A, int N);
void GenU(int P,int C, int D, Kart *  A,Kart * B, int N);
void razGenU ( int P, int D, Kart * A, int N);
void GenV(int P,int C, int D, Kart * A,Kart * B, int N, int *n, int N1);
Kart genW1 (int P, int C, Kart * A, Kart * B, int *n1, int J);
void GenW (int P,int C, int D, int N, int *n, int *n1, int N1);
void gevZ(int P,int C, int D, Kart * A);
void MP();

#endif 

