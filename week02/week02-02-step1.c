#include <stdio.h>

void main()
{
	// 1. ���� ���� ����
	float num1, num2, num3;
	float max, min;
	float difference;

	// 2. �ȳ��� ��� �� ������ �Է�
	printf("�� ���� ���� �Է��ϼ���.\n\n");
	printf("ù ��° ��: ");
	scanf("%f", &num1);
	printf("�� ��° ��: ");
	scanf("%f", &num2);
	printf("�� ��° ��: ");
	scanf("%f", &num3);

	// 3. �ӽ� �����ͷ� ó��
	max = 100.1;
	min = -20.4;

	difference = max - min;
	printf("\n���� ū ���� ���� ���� ���� = %f\n\n", difference);

	return 0;
}
