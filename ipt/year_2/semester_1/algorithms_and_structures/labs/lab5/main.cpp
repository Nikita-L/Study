#include "header.h"

void main ()
{
	string	answer;
	usi		i = 1;
	TreeElement *tree = nullptr;
	setlocale( LC_ALL,"Russian" );
	mainMenu();
	while (i)
	{
		cin >> answer;
		if (answer == "1") // ���������/������� ������ (������ �����)
		{
			treeGetElement(&tree);
			mainMenu();
		}
		else if (answer == "2") // ������� �������
		{
			treeGetDeleteElement (&tree);
			mainMenu();
		}
		else if (answer == "3") // ���������� ������
		{
			system ("CLS");
			if (tree)
				treeShow (tree, 0);
			getch();
			mainMenu();
		}
		else if (answer == "4") // ������� ������������� �����
		{
			treeGetDeleteRepeatElement (&tree);
			mainMenu();
		}
		else if (answer == "5") // ���������� ������ ����������� �������
		{
			system ("CLS");
			if (tree)
				treePostfixShow (tree, 0);
			getch();
			mainMenu();
		}
		else if (answer == "6") // �������� ������
		{
			treeDelete(&tree);
			mainMenu();
		}
		else if (answer == "0") // �����
		{
			treeDelete(&tree);
			return;
		}
		else
			mainMenu();
	}
}