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
		if (answer == "1") // ������ �����
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
		else if (answer == "2") // ������ �����
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
		else if (answer == "3") // �������������� �������
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
		else if (answer == "0") // �����
			return;
		else
		{
			system("CLS");
			main_menu();
		}
	}
}