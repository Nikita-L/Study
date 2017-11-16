#include "head.h"

usi part1()
{
	string	answer;
	usi		j, i = 1;
	part1_menu();
	while (i)
	{
		cin >> answer;
		if (answer == "1") // Стек
		{
			j = part1_stack();
			if (j == 1)
				part1_menu();
			else
				return 0;
		}
		else if (answer == "2") // Очередь
		{
			j = part1_queue();
			if (j == 1)
				part1_menu();
			else
				return 0;
		}
		else if (answer == "3") // Стек (размещение двух стеков в одном массиве)
		{
			j = part1_2stacks1mass();
			if (j == 1)
				part1_menu();
			else
				return 0;
		}
		else if (answer == "0") // Назад
			return 1;
		else
			part1_menu();
	}
}
usi part2()
{
	li A, B, C, D, E, F;
	string	answer;
	usi i = 1;
	part2_data_get(&A, &B, &C, &D, &E, &F);
	part2_menu();
	while (i)
	{
		cin >> answer;
		if (answer == "1") // (А-B-С)/D-E*F  ->  AB-C-D/EF*-
		{
			part2_formula1(A, B, C, D, E, F);
			part2_menu();
		}
		else if (answer == "2") // (A+B)*C-(D+E)/F  ->  AB+C*DE+F/-
		{
			part2_formula2(A, B, C, D, E, F);
			part2_menu();
		}
		else if (answer == "3") // A/(B-C)+D*(E-F)  ->  ABC-/DEF-*+
		{
			part2_formula3(A, B, C, D, E, F);
			part2_menu();
		}
		else if (answer == "4") // (A*B+C)/D-F/E  ->  AB*C+D/FE/-
		{
			part2_formula4(A, B, C, D, E, F);
			part2_menu();
		}
		else if (answer == "0") // Назад
			return 1;
		else
			part2_menu();
	}
}
usi additional()
{
	string	answer;
	usi j, i = 1;
	additional_menu();
	while (i)
	{
		cin >> answer;
		if (answer == "1") // Стек
		{
			j = additional_stack();
			if (j == 1)
				additional_menu();
			else
				return 0;
		}
		else if (answer == "2") // Очередь
		{
			j = additional_queue();
			if (j == 1)
				additional_menu();
			else
				return 0;
		}
		else if (answer == "0") // Назад
			return 1;
		else
			additional_menu();
	}
}