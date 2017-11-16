#include "head.h"

void main ()
{
	Worker V;
	V.show();

	Worker A("Andrew", 19, "manager", 3);
	A.show();

	Worker S=A;
	S.show();

	S.get();
	S.show();

	Worker N("Nikta", 18, "IT", 1);
	N.show();
	N.postchange();
	N.show();

	N.expcompare(N, A);

	PrimeWorker F;
	F.show();

	PrimeWorker P("Petya", 27, "Security", 6, 3);
	P.show();

	PrimeWorker Q(P);
	Q.show();

	PrimeWorker W("Lisa", 24, "Security", 5, 2);
	W.get();
	W.getbonus();
	W.show();

	W.postchange();

	W.expcompare(W, P);

	system ("pause");
}