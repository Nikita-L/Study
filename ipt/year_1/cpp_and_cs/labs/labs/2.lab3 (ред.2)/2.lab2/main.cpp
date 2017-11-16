#include "head.h"

void main ()
{
	Worker A("Andrew", 19, "manager", 3);
	A.show();

	Worker S=A;
	S.show();

	S==A;

	cin.get();
	cin.get();
	system ("CLS");

	PrimeWorker B("Vova", 23, "IT", 4, 3);
	B.getbonus();
	B.show();

	PrimeWorker X;
	X=B;
	B.show();
	
	X==B;


	cout<<endl;
	system ("pause");
}