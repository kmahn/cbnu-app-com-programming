#include <stdio.h>

// 4. �Լ� ���� �߰�
float find_max(float, float, float);
float find_min(float, float, float);

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
	// max = 100.1;
	// min = -20.4;

	// 5. �Լ� ȣ��
	max = find_max(num1, num2, num3);
	min = find_min(num1, num2, num3);

	difference = max - min;
	printf("\n���� ū ���� ���� ���� ���� = %f\n\n", difference);

	return 0;
}

// 6. �Լ� ����
float find_max(float a, float b, float c)
{
	float max;
	if (a > b)
		if (a > c) max = a;
		else max = c;
	else
		max = (b > c) ? b : c;
	return max;
}

float find_min(float a, float b, float c)
{
	float min = a;

	if (min > b) min = b;
	if (min > c) min = c;

	return min;
}
