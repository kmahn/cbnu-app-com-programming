/*
6���� ����: �ζ� ������
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void user_check(int[]);           // ����ڰ� ������ ���ڸ� �迭�� ����
void generate_lotto(int[]);       // ��ǻ�Ͱ� �ζ� ��ȣ ����
int mapping_number(int[], int[]); // ��ġ�ϴ� �ζ� ��ȣ ����

int main() {
	// ���� ���� ���� �� �ʱ�ȭ
	int arr_lotto[6]; // ��ǻ�Ͱ� ���� 6���� ��ȣ ����
	int arr_user[6];  // ����ڰ� �Է��� 6���� ��ȣ ����
	int i, win, cnt = 0;

	// ���� ���� �õ尪 ����
	srand((unsigned)time(NULL));

	user_check(arr_user);
	generate_lotto(arr_lotto);

	printf("\n�Է¹�ȣ: ");
	for (i = 0; i < 6; i++) printf("%3d ", arr_user[i]);

	printf("\n��÷��ȣ: ");
	for (i = 0; i < 6; i++) printf("%3d ", arr_lotto[i]);

	win = mapping_number(arr_user, arr_lotto);
	printf("\n\n��÷ ��ȣ�� %d���Դϴ�.\n\n", win);

	return 0;
}

void user_check(int lotto[]) {
	// ���� ���� ����
	int i;

	printf("1 ~ 45 ������ ��ȣ�� 6�� �����ϼ���: ");
	for (i = 0; i < 6; i++) {
		scanf("%d", lotto + i);
	}
}

void generate_lotto(int lotto[]) {
	// ���� ���� ���� �� �ʱ�ȭ
	int i, dup = 0, cnt = 0;

	do {
		lotto[cnt] = rand() % 45 + 1; // 1 ~ 45 ������ ���� ����

		// �� ��° ������ʹ� �ߺ����� ������ ��ȣ�� üũ�ؾ� ��
		if (cnt > 0) {
			for (i = 0; i < cnt; i++) {
				if (lotto[i] == lotto[cnt]) {
					dup++;
				}
			}
		}

		if (dup == 0) {
			cnt++; // �ߺ��� ���� ��� ���� ��ȣ�� ����
		}
		else {
			dup = 0; // �ߺ��� ������ �ٽ� ����(cnt ���� ����)
		}
	} while (cnt < 6);
}

int mapping_number(int lotto1[], int lotto2[]) {
	// ���� ���� ����
	int i, j, cnt = 0;

	// ��ġ�ϴ� ��ȣ�� �� ����
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (lotto1[i] == lotto2[j]) {
				cnt++;
				break;
			}
		}
	}

	return cnt;
}