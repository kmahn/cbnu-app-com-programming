#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	// ���� ���� ����
	char buffer[100], *tmp; // ����ڰ� �Է��� ���ڿ� ����, ��� ���� �Ҵ��(���� �Ҵ�)
	int size; // ���� ���ڿ��� ����

	nword = 0;
	printf("�ܾ �Է��ϼ���. �ִ� �ܾ���� 100���Դϴ�.\n");
	printf("�Է��� �����Ϸ��� ���͸� �Է��ϼ���\n\n");
	
	while (nword < MAXWORD) {
		printf("%d. �ܾ� �Է�: ", nword + 1);
		gets(buffer);

		// �Էµ� �ܾ ���ڿ��̸� �Է��� ��ħ
		if (strcmp(buffer, "") == 0) break;

		size = strlen(buffer) + 1; // �ܾ��� ũ�⸦ ���ϰ�
		pstrarray[nword] = (char *)malloc(sizeof(char) * size); // �ܾ ������ �������� �Ҵ�
		strcpy(pstrarray[nword++], buffer); // �ܾ ����
	}
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
