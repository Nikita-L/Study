#include "head.h"

void main ()
{
	string	answer;
	usi		j, i = 1;
	setlocale( LC_ALL,"Russian" );
	main_menu();
	while (i)
	{
		cin >> answer;
		if (answer == "1") // Первая часть
		{
			 j = part1();
			 if (j == 1)
			 {
				 system("CLS");
				 main_menu();
			 }
			 else
				 return;
		}
		else if (answer == "2") // Вторая часть
		{
			j = part2();
			if (j == 1)
			{
				system("CLS");
				main_menu();
			}
			else
				return;
		}
		else if (answer == "3") // Дополнительное задание
		{
			j = additional();
			if (j == 1)
			{
				system("CLS");
				main_menu();
			}
			else
				return;
		}
		else if (answer == "0") // Выход
			return;
		else
		{
			system("CLS");
			main_menu();
		}
	}
}