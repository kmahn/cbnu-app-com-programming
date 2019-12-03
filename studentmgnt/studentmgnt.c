#include <stdio.h>
#include <stdlib.h>
#include "studentmgnt.h"

SINFO *listhead = NULL;

static void flush();
static void insert_node(SINFO *new_node, SINFO *prev_node, SINFO *pos);

char print_menu() {
	char menu;
	printf(
		"처리할 기능의 번호를 선택하세요.\n\n"

		"1. 자료추가\n"
		"2. 목록검색\n"
		"3. 목록삭제\n"
		"4. 목록정렬\n"
		"5. 목록보기\n"
		"6. 메뉴보기\n"
		"7. 종료\n\n"

		"선택 > "
	);

	menu = getchar();
	flush();
	return menu;
}


void add_student() {
	SINFO *new_node = (SINFO *)malloc(sizeof(SINFO));
	printf("데이터를 입력하세요.\n");
	printf("학과: "); scanf("%s", new_node->major);
	printf("학번: "); scanf("%s", new_node->id);
	printf("이름: "); scanf("%s", new_node->name);
	printf("성적: "); scanf("%d", &new_node->score);

	insert_node(new_node, NULL, listhead);
	printf("%s의 데이터를 저장하였습니다.\n\n", new_node->name);
	flush();
}

void print_list() {
	SINFO *search = listhead;

	printf("\n%-16s%-16s%-16s%-6s\n", "학과", "학번", "이름", "성적");
	printf("======================================================\n");
	while (search) {
		printf("%-16s", search->major);
		printf("%-16s", search->id);
		printf("%-16s", search->name);
		printf("%6d\n", search->score);
		search = search->next;
	}
	printf("\n");
}

void delete_list() {
	SINFO *temp = listhead;
	while (listhead) {
		listhead = listhead->next;
		free(temp);
		temp = listhead;
	}
}

void write_list() {
	SINFO *temp;
	FILE *fp;

	if (fp = fopen("student.dat", "wb")) {
		temp = listhead;
		while (temp) {
			fwrite(temp, sizeof(SINFO), 1, fp);
			temp = temp->next;
		}
		fclose(fp);
	}
}


void read_list() {
	SINFO *temp;
	FILE *fp;
	int count;
	if (fp = fopen("student.dat", "rb")) {
		do {
			temp = (SINFO *)malloc(sizeof(SINFO));
			count = fread(temp, sizeof(SINFO), 1, fp);
			if (count) {
				insert_node(temp, NULL, listhead);
			}
		} while (count);
		fclose(fp);
	}
}

void search_menu() {
	char key[32], cond;
	printf(
		"\n무엇으로 검색하시겠습니까?\n"
		"1. 학번\n"
		"2. 이름\n\n"
		"검색조건 > "
	);
	cond = getchar();
	if (cond != '1' && cond != '2') {
		printf("\n검색 조건이 틀립니다.\n\n");
	}
	else {
		printf("\n%s은? ", cond == '1' ? "학번" : "이름");
		scanf("%s", key);
		print_node(key, cond);
	}
	flush();
}

void print_node(const char *key, char cond) {
	SINFO *search = listhead;
	int result;

	while (search) {
		result = cond == '1' ? strcmp(search->id, key) : strcmp(search->name, key);

		if (result == 0) break;
		search = search->next;
	}

	if (search) {
		printf("\n검색 결과: ");
		printf("%s ", search->major);
		printf("%s ", search->id);
		printf("%s ", search->name);
		printf("%3d\n\n", search->score);
	}
	else
		printf("\n\n검색 조건에 해당하는 학생이 없습니다.\n\n");
}

void sort_menu() {
	char cond;
	printf(
		"\n무엇으로 정렬하시겠습니까?\n"
		"1. 학과\n"
		"2. 학번\n\n"
		"정렬 조건 > "
	);
	cond = getchar();
	if (cond == '1' || cond == '2')
		sort_list(cond);
	else
		printf("\n검색 조건이 틀립니다.\n\n");
	flush();
}

void sort_list(char cond) {
	SINFO *oldlist, *temp;
	oldlist = listhead;
	listhead = NULL;

	while (oldlist != NULL) {
		temp = oldlist;
		oldlist = oldlist->next;
		sort_add(temp, cond);
	}
	if (cond == '1')
		printf("\n학과순으로 정렬하였습니다.\n\n");
	else
		printf("\n학번순으로 정렬하였습니다.\n\n");
}

void sort_add(SINFO *node, char cond) {
	int result;
	SINFO *search, *prev;
	search = listhead;
	prev = NULL;

	while (search) {
		result = cond == '1' ? strcmp(node->major, search->major) : strcmp(node->id, search->id);

		if (result > 0) {
			prev = search;
			search = search->next;
		}
		else
			break;
	}
	insert_node(node, prev, search);
}

void delete_node() {
	char name[16];
	SINFO *search, *prev;

	printf(
		"\n삭제할 학생의 이름을 입력하세요: \n"
		"이름: "
	);
	scanf("%s", name);
	flush();

	search = listhead;
	prev = NULL;
	while (search) {
		if (strcmp(name, search->name) == 0)
			break;
		prev = search;
		search = search->next;
	}

	if (search) {
		if (prev) {
			prev->next = search->next;
		}
		else {
			listhead = search->next;
		}
		free(search);
		printf("%s 학생의 데이터를 삭제하였습니다.\n\n", name);
	}
	else {
		printf("학생 데이터가 존재하지 않습니다.\n");
	}
}

// 내부 함수
void flush() {
	while (getchar() != '\n');
}

void insert_node(SINFO *new_node, SINFO *prev_node, SINFO *pos) {
	if (prev_node) {
		new_node->next = pos;
		prev_node->next = new_node;
	}
	else {
		new_node->next = pos;
		listhead = new_node;
	}
}

