#include "head.h"

int main()
{
	for (int i=0; i<=5;)
	{
		cout<<"////////////////////////"<<endl<<"1. Use class          //"<<endl<<"2. Use extra class    //"<<endl<<"0. Exit               //"<<endl<<"////////////////////////"<<endl;
		int choice1;
		cin>>choice1;
		switch (choice1)
		{
		case 1: // ~~~~~~~~~~ Основной класс ~~~~~~~~~~
			{
				Point p1;	// Конструктор по умолчанию
				p1.showPoint();
				Point p2(1, 1); // Конструктор с парамтрами
				Point p3=p2; // Конструктор копирования
				p2.showPoint();
				p3.showPoint();
				Point p4(4, 5);
				p1.Distance(p1, p4); // Расстояние между 2 точками
				p1.Plus(p3,p4); // Сумма координат
				Point p5;
				p5.getPoint(); // Ввод
				p5.showPoint(); // Вывод
				p1.IdentityCheck(p5, p4); // Проверка сходимости 2 точек
			
				break;
			}
		case 2: // ~~~~~~~~~~ Производный класс ~~~~~~~~~~
			{
				ExtraPoint p6;	// Конструктор по умолчанию
				p6.showPoint();
				ExtraPoint p7(1, 1, "green"); // Конструктор с парамтрами
				ExtraPoint p8=p7; // Конструктор копирования
				p7.showPoint();
				p8.showPoint();
				ExtraPoint p9(4, 5, "white");
				p6.Distance(p6, p9); // Расстояние между 2 точками
				p6.Plus(p8,p9); // Сумма координат
				ExtraPoint p10;
				p10.getPoint(); // Ввод
				p10.showPoint(); // Вывод
				p6.IdentityCheck(p10, p9); // Проверка сходимости 2 точек
				
				break;
			}
		case 0:
			i=6;
			break;
		default:
			i++;
			break;
		}
	}

	



	
	

	cout<<endl;
	system("pause");
	return 0;
}