#include <stdio.h>

void print_array(const char *, const int[], int);

int main() {
	// 변수 선언 및 초기화
	int data[] = { 1, 2, 3, 4, 5, 6, 7 }; // 임시로 배열 설정 -> 차후 동적배열로 변경
	int size = 7; // 임시로 배열의 크기를 7로 정한다.
	int index, key = 1;

	// 파일에서 데이터 읽기
	print_array("원본: ", data, size);

	while (1) {
		printf("검색할 수를 입력하시오: "); // 사용자의 입력을 받는다.
		scanf("%d", &key);

		// 입력값이 1보다 작으면 프로그램 종료
		if (key < 1) break;

		// key를 탐색하고 결과를 출력한다. 구현을 미룸
		printf("%d를 탐색합니다.\n", key);
	}

	printf("프로그램을 종료합니다.\n\n");

	return 0;
}

void print_array(const char *str, const int arr[], int size) {
	int i;
	printf("%s %d\n", str, size);
	for (i = 0; i < size; i++) {
		printf("%5d", arr[i]);
		if ((i + 1) % 10 == 0) printf("\n");
	}
	printf("\n");
}
