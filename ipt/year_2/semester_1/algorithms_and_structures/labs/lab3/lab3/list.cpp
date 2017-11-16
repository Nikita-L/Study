#include "head.h"

short ls()
{
	system("CLS");
	cout << "///////////////////////////////////////////" << endl
		<< "                                         //" << endl
		<< "      Enter 100 small latin letters,     //" << endl 
		<< "         end text with a point!          //" << endl 
		<< "     (Push \"0\" to exit the program)      //" << endl
		<< "     (Push \"9\" to get to the menu)       //" << endl
		<< "                                         //" << endl
		<< "///////////////////////////////////////////" << endl;
	Sleep(1500);
	system("CLS");
	unsigned char	a;
	bool	check1 = 0;
	bool*	check_1 = &check1;
	bool	check2 = 0;
	bool	check3 = 0;
	bool*	check_3 = &check3;
	bool	check4 = 0;
	bool*	check_4 = &check4;
	List*	begin = nullptr;
	List*	end = nullptr;
	int		i = 0;
	while (i!=100)
	{
		a = getch();
		if (!kbhit())
		{
			if (a>=97 && a<=122 || a==32 || a==46) // Small latin letters
			{
				add_back(&begin, &end, a);
			}
			else if (a == 13) // Enter
			{
				i = enter (begin, check_3, check_4);
			}
			else if (a == 48) // Exit
			{
				list_delete(&begin);
				return 5;
			}
			else if (a == 57) // Back to menu
			{
				list_delete(&begin);
				return 0;
			}
			else if (a == 8) // Delete
			{
				remove_back (&begin, &end, check_1);
			}
			else
			{
				if (!check2)
				{
					check2 = 1;
					system("CLS");
					cout << "///////////////////////////////////////////" << endl
						<< "                                         //" << endl
						<< "         You can enter just small        //" << endl 
						<< "              latin letters!             //" << endl
						<< "     (Push \"0\" to exit the program)      //" << endl
						<< "     (Push \"9\" to get to the menu)       //" << endl
						<< "                                         //" << endl
						<< "///////////////////////////////////////////" << endl;
					Sleep(1500);
					system("CLS");
					show(begin);
				}
			}
		}
		else if (kbhit() && ( a == 0x00 ||a == 0xE0 ))
		{
			a=getch();
			if (a == 'K') // Left
			{
				arrow_left(&begin, &end);
			}
			else if (a == 'M') // Right
			{
				arrow_right(&begin, &end);
			}
		}
	}
	if (arrow(begin))
	{
		hide_arrow(&begin);
	}
	short w = list_menu_1(&begin, &end);
	if (w == 9)
	{
		return 0;
	}
	if (w == 0)
	{
		return 5;
	}
}