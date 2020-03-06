#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

bool poop(int a)
{
	int account(0);
	for(int i=1; i<30; i++)
	{
		if(a%i==0)
		{
			account++;
		}
    }
    if  (account>2)
    {
    	return false;
	}
	else
	{
		return true;
	}
}
