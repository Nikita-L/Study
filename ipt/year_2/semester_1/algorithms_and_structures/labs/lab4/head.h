#include <iostream>
#include <string>
#include <conio.h>
#include <sstream>
#include <list>
#include <iterator>

#define usi unsigned short
#define li long

using namespace std;

void main_menu ();
usi part1();
usi part2();
void part1_menu();
void part1_use_menu();
usi part1_stack();
usi part1_stack_mass();
void part1_stack_use_menu();
void part1_stack_mass_add(char**, usi*);
void part1_stack_mass_del(char**, usi*);
void part1_stack_mass_show(char*, usi);
void mass_delete(char*);
usi part1_stack_list();
void part1_stack_list_menu();
usi part1_queue();
usi part1_queue_mass();
void part1_queue_use_menu();
void part1_queue_mass_add(char**, usi*, usi*, usi*);
void part1_queue_mass_del(char**, usi*, usi*, usi*);
void part1_queue_mass_show(char*, usi, usi, usi);
usi part1_queue_list();
usi part1_2stacks1mass();
void part1_2stacks1mass_menu();
void part1_2stacks1mass_stack1_add(char**, usi*, usi*);
void part1_2stacks1mass_stack1_del(char**, usi*, usi*);
void part1_2stacks1mass_stack1_show(char*, usi);
void part1_2stacks1mass_stack2_add(char**, usi*, usi*);
void part1_2stacks1mass_stack2_del(char**, usi*, usi*);
void part1_2stacks1mass_stack2_show(char*, usi, usi);
void part1_2stacks1mass_stacks_show(char*, usi, usi);
void part2_data_get(li*, li*, li*, li*, li*, li*);
void part2_menu();
void part2_formula1(li, li, li, li, li, li);
void part2_formula2(li, li, li, li, li, li);
void part2_formula3(li, li, li, li, li, li);
void part2_formula4(li, li, li, li, li, li);
string part2_inttostr(li);
usi additional();
void additional_menu();
usi additional_stack();
usi additional_queue();

struct data
{
	char key;
	data *prev, *next;
};
struct data_str
{
	string key;
	data_str *prev, *next;
};

class partsList
{
private:
	data info;
	data_str info_str;
	data *begin, *end;
	data_str *begin_str, *end_str;
public:
	partsList() : begin(nullptr), end(nullptr), begin_str(nullptr), end_str(nullptr) {}
	~partsList();
	void part1_stack_list_add();
	void part1_stack_list_del();
	void part1_stack_list_show();
	void part1_queue_list_del();
	void part2_stack_add(string);
	void part2_stack_show();
};