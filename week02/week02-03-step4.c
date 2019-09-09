#include <stdio.h>
#define NUMMAX 10	// �������� �ִ� ���� ����

// �Լ� �����
void get_data();
float calc_average();
float calc_stdev(float mean);

// ���� ���� ����
float num[NUMMAX];
int n;

int main()
{
	// ���� ���� ����
	float avg, stdev;

	// ������ �Է�
	get_data();

	// ��� ���ϱ�
	avg = calc_average();

	// ǥ������ ���ϱ�
	stdev = calc_stdev(avg);

	printf("\n��� = %6.2f\n", avg);
	printf("ǥ������ = %6.2f\n\n", stdev);

	return 0;
}

// ������ �Է� �Լ�
void get_data() {
	// �ȳ��� ���
	printf("�ִ� 10���� �Ǽ��� �Է��ϼ���\n");
	printf("�Է��� �����Ϸ���, 0 ������ ���� �Է��ϼ���.\n\n");

	// ���ݱ��� �Էµ� �������� ���� 0���� �ʱ�ȭ
	n = 0;

	// ������ �Էµ��� �ʰų� �����Ͱ� 10�� ���ϰ� �Էµ� ����
	// ����ڷκ��� �����͸� �Է¹���
	while (n < 10) {
		printf("���� %d: ", n + 1);
		scanf("%f", &num[n]);
		if (num[n] > 0.0) n += 1;
		else break;
	}
}

// ��� ���ϴ� �Լ�
float calc_average() {
	// �ʿ��� ���� ���� ����
	float sum, avg;
	int k;

	// sum�� ������ �׵������ �ʱ�ȭ
	sum = 0.0;

	// k = 0 ~ n ���� num[k]������ �� ���ϱ�
	for (k = 0; k < n; k++)
		sum += num[k];

	// ��� ���ϱ�
	avg = sum / n;

	return avg;
}

// ǥ������ ���ϴ� �Լ�
float calc_stdev(float mean)
{
	// �ʿ��� ���� ���� ����
	float sum, diff, variance, stdev;
	int k;

	// �л� �� ǥ������ ���ϱ�
	sum = 0.0;
	for (k = 0; k < n; k++) {
		diff = num[k] - mean;
		sum += diff * diff;
	}
	variance = sum / n;
	stdev = (float)sqrt(variance);

	return stdev;
}