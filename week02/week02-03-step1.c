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

// ��� �ִ� �Լ� ����
void get_data() {}

// ���ϰ��� �ִ� �Լ��� �ӽð� ����
float calc_average() {
	return 1.0;
}

float calc_stdev(float mean)
{
	return 1.0;
}