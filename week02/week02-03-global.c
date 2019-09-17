#include <stdio.h>
#include <math.h>
#define NUMMAX 10	// �������� �ִ� ���� ����

// �Լ� �����
void get_data();
void calc_avgstd();

// ���� ���� ����
float num[NUMMAX];
int n;

double avg, stdev;

int main()
{
	// ���� ���� ����
	// float avg, stdev;

	// ������ �Է�
	get_data();

	// ��� ���ϱ�
	// avg = calc_average();

	// ǥ������ ���ϱ�
	// stdev = calc_stdev(avg);

	// ���������� �̿��Ͽ� ��հ� ǥ������ ���ϱ�
	calc_avgstd();

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


void calc_avgstd() {
	double sum = 0, ssum = 0, variance;
	int k;
	for (k = 0; k < n; k++) {
		sum += num[k];
		ssum += num[k] * num[k];
	}

	avg = sum / n;
	variance = ssum / n - avg * avg;
	stdev = sqrt(variance);
}