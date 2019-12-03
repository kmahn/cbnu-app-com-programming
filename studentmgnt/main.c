#include <stdio.h>
#include "studentmgnt.h"

int main() {
	char menu;

	read_list();

	while ((menu = print_menu()) != '7') {
		switch (menu) {
		case '1': add_student(); break; // 자료 추가
		case '2': search_menu(); break;
		case '3': delete_node(); break;
		case '4': sort_menu(); break;
		case '5': print_list();  break;
		case '6': break;
		default: break;
		}
	}

	write_list();
	delete_list();

	return 0;
}