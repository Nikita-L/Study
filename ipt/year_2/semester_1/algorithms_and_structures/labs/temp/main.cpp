#include "head.h"

void main ()
{
	string	str;
	char	key;
	for (usi i = 0; i != 1;)
	{
		key = getch();
		if (key >= 97 && key <= 122)
		{
			if (str.size() != 0)
			{
				if (str[str.size() - 1] < 97 || str[str.size() - 1] > 122)
				{
					putchar(key);
					str.push_back(key);
				}
			}
			else
			{
				putchar(key);
				str.push_back(key);
			}
		}
		else if (key == 42 || key == 43 || key == 45 || key == 47)
		{
			if (str.size() && str[str.size() - 1] != 42 && str[str.size() - 1] != 43 && str[str.size() - 1] != 45 && str[str.size() - 1] != 47 && str[str.size() - 1] != 40)
			{
				putchar(key);
				str.push_back(key);
			}
		}
		else if (key == 40)
		{
			if (!str.size())
			{
				putchar(key);
				str.push_back(key);
			}
			else
			{
				if ((str[str.size() - 1] == 42 || str[str.size() - 1] == 43 || str[str.size() - 1] == 45 || str[str.size() - 1] == 47 || str[str.size() - 1] == 40))
				{
					putchar(key);
					str.push_back(key);
				}
			}
		}
		else if (key == 41)
		{
			if (str.size())
			{
				bool bracket1_check = 0;
				for (short j = str.size() - 1; j > - 1; j--)
				{
					if (str[j] == 40)
					{
						bracket1_check = 1;
						break;
					}
				}
				if (bracket1_check && str[str.size() - 1] != 42 && str[str.size() - 1] != 43 && str[str.size() - 1] != 45 && str[str.size() - 1] != 47 && str[str.size() - 1] != 40)
				{
					putchar(key);
					str.push_back(key);
				}
			}
		}
		else if (key == 13)
		{
			if (str.size())
			{
				usi bracket1 = 0;
				usi bracket2 = 0;
				for (usi j = 0; j < str.size(); j++)
				{
					if (str[j] == 40)
						bracket1++;
				}
				for (usi j = 0; j < str.size(); j++)
				{
					if (str[j] == 41)
						bracket2++;
				}
				if (bracket1 == bracket2 && str[str.size() - 1] != 42 && str[str.size() - 1] != 43 && str[str.size() - 1] != 45 && str[str.size() - 1] != 47)
				{
					str = formulaToPostfix(str, 1, 1);
					for (usi i = 0; i < str.size(); i++)
					{
						if (str[i] == 40 || str[i] == 41)
						{
							for (usi j = i; j < str.size() - 1; j++)
								str[j] = str [j+1];
							str.pop_back();
							i--;
						}
					}
					cout << endl << str;
					getch();
					system("CLS");
					str.clear();
				}
			}
			else
				return;
		}
		else if (key == 8)
		{
			if (str.size())
			{
				system("CLS");
				str.pop_back();
				cout << str;
			}
		}
	}
}