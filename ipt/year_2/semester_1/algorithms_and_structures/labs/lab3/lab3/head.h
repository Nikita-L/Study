#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

using namespace std;

struct List
{
	char key;
	List* prev, *next;
};

void menu();
short mass();
short ls ();
short mass_menu_1(char*, unsigned int);
unsigned int size (List*);
void show (List*);
void add_back (List**, List**, char);
void remove_back (List**, List**, bool*);
bool arrow (List*);
void arrow_left (List**, List**);
void arrow_position_left (List*);
void arrow_right (List**, List**);
void arrow_position_right (List**, List**);
void hide_arrow (List**);
int enter (List*, bool*, bool*);
short list_menu_1(List**, List**);
void copy_list (List*, List**, List**);
void list_delete (List**);
void first_last_char_del (List**, List**);
void disp_wrds_odd_char (List*);