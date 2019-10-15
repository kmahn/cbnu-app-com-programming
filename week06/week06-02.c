/*
6주차 예제: 로또 생성기
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void user_check(int[]);           // 사용자가 선택한 숫자를 배열에 저장
void generate_lotto(int[]);       // 컴퓨터가 로또 번호 생성
int mapping_number(int[], int[]); // 일치하는 로또 번호 매핑

int main() {
	// 지역 변수 선언 및 초기화
	int arr_lotto[6]; // 컴퓨터가 뽑은 6개의 번호 저장
	int arr_user[6];  // 사용자가 입력한 6개의 번호 저장
	int i, win, cnt = 0;

	// 난수 생성 시드값 설정
	srand((unsigned)time(NULL));

	user_check(arr_user);
	generate_lotto(arr_lotto);

	printf("\n입력번호: ");
	for (i = 0; i < 6; i++) printf("%3d ", arr_user[i]);

	printf("\n당첨번호: ");
	for (i = 0; i < 6; i++) printf("%3d ", arr_lotto[i]);

	win = mapping_number(arr_user, arr_lotto);
	printf("\n\n당첨 번호는 %d개입니다.\n\n", win);

	return 0;
}

void user_check(int lotto[]) {
	// 지역 변수 선언
	int i;

	printf("1 ~ 45 사이의 번호를 6개 선택하세요: ");
	for (i = 0; i < 6; i++) {
		scanf("%d", lotto + i);
	}
}

void generate_lotto(int lotto[]) {
	// 지역 변수 선언 및 초기화
	int i, dup = 0, cnt = 0;

	do {
		lotto[cnt] = rand() % 45 + 1; // 1 ~ 45 범위의 난수 생성

		// 두 번째 실행부터는 중복으로 생성된 번호를 체크해야 함
		if (cnt > 0) {
			for (i = 0; i < cnt; i++) {
				if (lotto[i] == lotto[cnt]) {
					dup++;
				}
			}
		}

		if (dup == 0) {
			cnt++; // 중복이 없을 경우 다음 번호를 뽑음
		}
		else {
			dup = 0; // 중복이 있으면 다시 뽑음(cnt 변경 없음)
		}
	} while (cnt < 6);
}

int mapping_number(int lotto1[], int lotto2[]) {
	// 지역 변수 선언
	int i, j, cnt = 0;

	// 일치하는 번호의 수 세기
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