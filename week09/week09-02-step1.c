#include <stdio.h>
#define MAXWORD 100 // �ܾ� �ִ� ��

// �Լ� ���� �����
void get_words();
void sort_string();
void print_words();
void deallocate();

// ���� ���� ����
char *pstrarray[MAXWORD]; // �ܾ ������ ���� ������ �迭
int nword;

int main() {
	get_words();    // ����ڷκ��� �ܾ �Է� �޾� ����
	sort_string();  // �ܾ ������������ ����
	print_words();  // ���ĵ� �ܾ ���
	deallocate();   // �Ҵ� ���� ������ ����
}

void get_words() {
	// ������ �̷�
}

void sort_string() {
	// ������ �̷�
}

void print_words() {
	// ������ �̷�
}

void deallocate() {
	// ������ �̷�
}
