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
		if (answer == "1") // Заполнить/Создать дерево (только буквы)
		{
			treeGetElement(&tree);
			mainMenu();
		}
		else if (answer == "2") // Удалить элемент
		{
			treeGetDeleteElement (&tree);
			mainMenu();
		}
		else if (answer == "3") // Отобразить дерево
		{
			system ("CLS");
			if (tree)
				treeShow (tree, 0);
			getch();
			mainMenu();
		}
		else if (answer == "4") // Удалить повторяющиеся буквы
		{
			treeGetDeleteRepeatElement (&tree);
			mainMenu();
		}
		else if (answer == "5") // Отобразить дерево постфиксным обходом
		{
			system ("CLS");
			if (tree)
				treePostfixShow (tree, 0);
			getch();
			mainMenu();
		}
		else if (answer == "6") // Очистить дерево
		{
			treeDelete(&tree);
			mainMenu();
		}
		else if (answer == "0") // Выход
		{
			treeDelete(&tree);
			return;
		}
		else
			mainMenu();
	}
}