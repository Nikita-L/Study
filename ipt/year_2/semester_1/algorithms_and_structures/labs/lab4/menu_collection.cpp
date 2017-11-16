#include "head.h"

void main_menu()
{
	cout
		<< "1. Первая часть" << endl
		<< "2. Вторая часть" << endl
		<< "3. Дополнительное задание" << endl
		<< "0. Выход" << endl << endl
		<< "Ваш выбор: ";
}
void part1_menu()
{
	system("CLS");
	cout
		<< "1. Стек" << endl
		<< "2. Очередь" << endl
		<< "3. Стек (размещение двух стеков в одном массиве)" << endl
		<< "0. Назад" << endl << endl
		<< "Ваш выбор: ";
}
void part1_use_menu()
{
	system("CLS");
	cout
		<< "1. Использовать массив" << endl
		<< "2. Использовать список" << endl
		<< "0. Назад" << endl <<endl
		<< "Ваш выбор: ";
}
void part1_stack_use_menu()
{
	system("CLS");
	cout
		<< "1. Добавить элемент" << endl
		<< "2. Удалить элемент" << endl
		<< "3. Просмотреть стэк" << endl
		<< "0. Назад" << endl << endl
		<< "Ваш выбор: ";
}
void part1_queue_use_menu()
{
	system("CLS");
	cout
		<< "1. Добавить элемент" << endl
		<< "2. Удалить элемент" << endl
		<< "3. Просмотреть очередь" << endl 
		<< "0. Назад" << endl << endl
		<< "Ваш выбор: ";
}
void part1_2stacks1mass_menu()
{
	system("CLS");
	cout
		<< "1. Добавить элемент в первый стэк" << endl
		<< "2. Удалить элемент из первого стэка" <<endl
		<< "3. Добавить элемент во второй стэк" <<endl
		<< "4. Удалить элемент из второго стэка" <<endl
		<< "5. Просмотреть первый стэк" <<endl
		<< "6. Просмотреть второй стэк" <<endl
		<< "7. Просмотреть массив" << endl
		<< "0. Назад" << endl << endl
		<< "Ваш выбор: ";
}
void part2_menu()
{
	system("CLS");
	cout
		<< "1. (А-B-С)/D-E*F" << endl
		<< "2. (A+B)*C-(D+E)/F" << endl
		<< "3. A/(B-C)+D*(E-F)" << endl
		<< "4. (A*B+C)/D-F/E" << endl
		<< "0. Назад" << endl << endl
		<< "Ваш выбор: ";
}
void additional_menu()
{
	system("CLS");
	cout
		<< "1. Стек" << endl
		<< "2. Очередь" << endl
		<< "0. Назад" << endl << endl
		<< "Ваш выбор: ";
}