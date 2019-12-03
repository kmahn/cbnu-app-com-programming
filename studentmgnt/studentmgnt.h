#ifndef __STUDENTMGNT_H__
#define __STUDENTMGNT_H__

typedef struct STUDENT_INFO SINFO;

struct STUDENT_INFO {
	char major[32];
	char id[16];
	char name[16];
	int score;
	SINFO *next;
};

char print_menu();
void add_student();
void delete_list();
void print_list();
void write_list();
void read_list();
void search_menu();
void print_node(const char *key, char cond);
void sort_menu();
void sort_list(char cond);
void sort_add(SINFO *node, char cond);
void delete_node();

#endif
