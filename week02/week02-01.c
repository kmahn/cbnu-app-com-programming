#include <stdio.h>

int main() {
	// 1. ���� ���� ����
	char dept[20], name[20];
	int grade, year;

	// 2. �ȳ��� ��� �� �Է�
	printf("������ �Է��ϼ���.\n\n");
	printf("�а�: ");
	scanf("%s", dept);
	printf("�г�: ");
	scanf("%d", &grade);
	printf("���г⵵: ");
	scanf("%d", &year);
	printf("�̸�: ");
	scanf("%s", name);

	// 3. �ڱ� �Ұ� ���
	printf("\n���� %s %d�г� %d�й� %s�Դϴ�.\n", dept, grade, year, name);
	return 0;
}