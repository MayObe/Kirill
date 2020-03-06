#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "crypto4.h"
using namespace std;

int main(int argc, char** argv) {
	srand ( time(NULL) );
	setlocale(0,"rus");
	MP();
	cout<<"Привет"<<endl;
	return 0;
}
