#include <stdio.h>
#define NMAX 5
#define OUTPUT_MESSAGE "1 ~ 4�� �� �� �ĺ��� ��ȣ�� �Է��Ͻÿ�: "

int main() {
	// ���� ���� ���� �� �ʱ�ȭ
	int ip[NMAX] = { 0 };  // ��ǥ���� ����� �迭 ������ ������ 0���� �ʱ�ȭ
	int n = 0, xdata = 0, i;

	printf(OUTPUT_MESSAGE);

	// scanf�� ���Ĺ��ڿ� ��Ȯ�ϰ� ���� ���� ���� ����, 
	// ��, �Էµ� �����Ͱ� ���ڷ� ��Ȯ�ϰ� �ԷµǴ� ���� �ݺ��� ����(���ڰ� ������ �ݺ� ����)
	while (scanf("%d", &xdata) == 1) {
		n++; // ��ǥȽ�� ����

		// ��ȿ��ǥ�� ���
		if (xdata < 1 || xdata > NMAX) ++ip[0];
		// �������� ��ǥ�� ���
		else ++ip[xdata];

		printf(OUTPUT_MESSAGE);
	}

	// ��� ���
	printf("\n��ǥ��\n");
	for (i = 1; i < NMAX; i++) printf("%d��: %d ǥ\n", i, ip[i]);
	printf("��ȿǥ: %d ǥ\n", ip[0]);
	printf("�� ��ǥ��: %d ǥ\n", n);

	return 0;
}