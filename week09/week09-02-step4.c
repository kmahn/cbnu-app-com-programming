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
	int n, m, minindex;
	char *tmp;

	for (n = 0; n < nword - 1; n++) {
		minindex = n;
		for (m = n; m < nword; m++) {
			if (strcmp(pstrarray[minindex], pstrarray[m]) > 0) minindex = m;
		}
		// �Ʒ��� ������ swap �Լ��� �и��ص� ��
		tmp = pstrarray[minindex];
		pstrarray[minindex] = pstrarray[n];
		pstrarray[n] = tmp;
	}
}

void print_words() {
	int n;
	printf("\n���� �� ���: �ܾ� �� = %d\n", nword);
	for (n = 0; n < nword; n++) {
		puts(pstrarray[n]);
	}
}

void deallocate() {
	int n;

	// �Էµ� ��� �ܾ ���ؼ� �ݺ��ϸ鼭
	for (n = 0; n < nword; n++) {
		if (pstrarray[n] != NULL) {
			// ��� ���� ����
			free(pstrarray[n]);
			pstrarray[n] = NULL;
		}
	}
}
