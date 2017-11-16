#include "head.h"

short list_menu_1(List** begin, List** end)
{
	system ("CLS");
	cout << "///////////////////////////////////////////" << endl
		<< "Choose the action:                       //" << endl 
		<< "1. Show and edit text array              //" << endl 
		<< "2. Apply the function                    //" << endl
		<< "                                         //" << endl
		<< "9. Back to main menu                     //" << endl
		<< "0. Exit the program                      //" << endl
		<< "///////////////////////////////////////////" << endl
		<< endl <<"Your choice: ";
	bool	check5 = 0;
	bool	check6 = 0;
	int		j = 0;
	while (j != 100)
	{
		List*	begin_temp = nullptr;
		List*	end_temp = nullptr;
		copy_list (*begin, &begin_temp, &end_temp);
		string ch;
		cin>>ch;
		if (ch == "9") // Back to main menu
		{
			if (begin_temp)
			{
				list_delete (&begin_temp);
			}
			return 9;
		}
		else if (ch == "0") // Exit
		{
			list_delete(begin);
			list_delete(&begin_temp);
			return 0;
		}
		else if (ch == "1") // Show and edit
		{
			system("CLS");
			if (!check5)
			{
				cout << "///////////////////////////////////////////" << endl
					<< "                                         //" << endl
					<< "                                         //" << endl
					<< "      Push \"0\" to exit the program       //" << endl
					<< "      Push \"9\" to get to the menu        //" << endl
					<< "                                         //" << endl
					<< "                                         //" << endl
					<< "///////////////////////////////////////////" << endl;
				Sleep(1500);
				system("CLS");
				check5 = 1;
			}
			show (begin_temp);
			unsigned char	a;
			bool	check1 = 0;
			bool*	check_1 = &check1;
			bool	check2 = 0;
			bool	check3 = 0;
			bool*	check_3 = &check3;
			bool	check4 = 0;
			bool*	check_4 = &check4;
			int		i = 0;
			while (i!=100)
			{
				a = getch();
				if (!kbhit())
				{
					if (a>=97 && a<=122 || a==32 || a==46) // Small latin letters
					{
						add_back(&begin_temp, &end_temp, a);
					}
					else if (a == 13) // Enter
					{
						list_delete (begin);
						*end = nullptr;
						copy_list (begin_temp, begin, end);
						list_delete (&begin_temp);
						i = enter (*begin, check_3, check_4);
						if (i==100)
						{
							system ("CLS");
							cout << "///////////////////////////////////////////" << endl
								<< "Choose the action:                       //" << endl 
								<< "1. Show and edit text array              //" << endl 
								<< "2. Apply the function                    //" << endl
								<< "                                         //" << endl
								<< "9. Back to main menu                     //" << endl
								<< "0. Exit the program                      //" << endl
								<< "///////////////////////////////////////////" << endl
								<< endl <<"Your choice: ";
						}
					}
					else if (a == 48) // Exit
					{
						list_delete(begin);
						list_delete(&begin_temp);
						return 0;
					}
					else if (a == 57) // Back to menu
					{
						list_delete(&begin_temp);
						i=100;
						system ("CLS");
						cout << "///////////////////////////////////////////" << endl
							<< "Choose the action:                       //" << endl 
							<< "1. Show and edit text array              //" << endl 
							<< "2. Apply the function                    //" << endl
							<< "                                         //" << endl
							<< "9. Back to main menu                     //" << endl
							<< "0. Exit the program                      //" << endl
							<< "///////////////////////////////////////////" << endl
							<< endl <<"Your choice: ";
					}
					else if (a == 8) // Delete
					{
						remove_back (&begin_temp, &end_temp, check_1);
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
							show(*begin);
						}
					}
				}
				else if (kbhit() && ( a == 0x00 ||a == 0xE0 ))
				{
					a=getch();
					if (a == 'K') // Left
					{
						arrow_left(&begin_temp, &end_temp);
					}
					else if (a == 'M') // Right
					{
						arrow_right(&begin_temp, &end_temp);
					}
				}
			}
			hide_arrow (begin);
		}
		else if (ch == "2")
		{
			system("CLS");
			if (check6 == 0)
			{
				cout << "///////////////////////////////////////////" << endl
					<< "                                         //" << endl  
					<< "        Press Enter to get back,         //" << endl
					<< "         9 to get to main menu           //" << endl
					<< "               0 to exit                 //" << endl
					<< "                                         //" << endl
					<< "                                         //" << endl
					<< "///////////////////////////////////////////" << endl;
				Sleep(1500);
				system ("CLS");
				check6 = 1;
			}
			// Удаление первой и последней буквы в словах с непарным количеством букв
			first_last_char_del (begin, end);
			// Отображение слов с непарным количеством букв
			disp_wrds_odd_char (*begin);
			/////////////////////////////////////////////////////////////////////////
			unsigned char ans;
			for (int r=0; r<5; )
			{
				ans = getch();
				if (ans == 13)
				{
					r=5;
					system ("CLS");
					cout << "///////////////////////////////////////////" << endl
						<< "Choose the action:                       //" << endl 
						<< "1. Show and edit text array              //" << endl 
						<< "2. Apply the function                    //" << endl
						<< "                                         //" << endl
						<< "9. Back to main menu                     //" << endl
						<< "0. Exit the program                      //" << endl
						<< "///////////////////////////////////////////" << endl
						<< endl <<"Your choice: ";
				}
				else if (ans == 57)
				{
					return 9;
				}
				else if (ans == 48)
				{
					return 0;
				}
			}
		}
		else
		{
			system("CLS");
			j++;
			if (j==1)
			{
				cout << "///////////////////////////////////////////" << endl
					<< "                                         //" << endl
					<< "                                         //" << endl 
					<< "      You can enter 1, 2, 9 or 0         //" << endl
					<< "                                         //" << endl 
					<< "                                         //" << endl 
					<< "                                         //" << endl
					<< "///////////////////////////////////////////" << endl;
				Sleep(2500);
				system("CLS");
			}
			if (j!=5)
			{
				cout << "///////////////////////////////////////////" << endl
					<< "Choose the action:                       //" << endl 
					<< "1. Show and edit text array              //" << endl 
					<< "2. Apply the function                    //" << endl
					<< "                                         //" << endl
					<< "9. Back to main menu                     //" << endl
					<< "0. Exit the program                      //" << endl
					<< "///////////////////////////////////////////" << endl
					<< endl <<"Your choice ("<<5-j<<" tries left): ";
			}
			else
			{
				list_delete(&begin_temp);
				list_delete(begin);
				return 0;
			}
		}
	}
}