#include "head.h"

void main ()
{
	Worker<int> V;
	V.show();

	Worker<int long> A("Andrew", 19, "Manager", 3);
	A.show();

	Worker<int long> S(A);
	S.show();

	S.get();
	S.show();

	Worker<float> N("Nikta", 18, "IT", 1.123456789);
	N.show();
	N.postchange();
	N.show();

	Worker <float> H("Valeriy", 23, "Producer", 1.23456789987654321);

	N.expcompare(N, H);
	cin.get();
	cin.get();
	system("CLS");

	PrimeWorker<int> F;
	F.show();

	PrimeWorker<double> P("Petya", 27.3, "Security", 6.12131323, 3);
	P.getbonus();
	P.show();

	PrimeWorker<double> Q(P);
	Q.show();

	Q.get();
	Q.getbonus();
	Q.show();
	P.show();
	


	PrimeWorker<double> W("Lisa", 24, "Security", 5, 2);
	W.get();
	W.getbonus();
	W.show();

	W.postchange();
	W.show();

	W.expcompare(W, P);
	
	system ("pause");
}