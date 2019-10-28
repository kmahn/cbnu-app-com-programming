/*
7주차 예제: 버블정렬 - 프로그램 구조
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

void generate_random(int[], int);
void print_array(const char *, int[], int);

int main() {
	// 지역 변수 선언
	int *data, size;

	// 난수 생성 시드값 초기화(한번만 호출)
	srand((unsigned)time(NULL));

	// 배열의 크기 입력
	printf("배열의 크기를 입력하세요: ");
	scanf("%d", &size);

	// 동적 배열
	data = (int *)malloc(sizeof(int) * size);

	generate_random(data, size);
	print_array("원본: ", data, size);

	// 버블 정렬: 구현을 미룸
	print_array("정렬: ", data, size);

	// 파일에 저장: 구현을 미룸(8장에서 구현)

	// 동적 메모리 해제
	free(data);

	return 0;
}


void generate_random(int arr[], int size) {
	int n;

	// size만큼의 난수를 생성하여 배열 arr에 저장
	for (n = 0; n < size; n++) arr[n] = rand() % MAX + 1;
}

void print_array(const char *str, int arr[], int size) {
	int n;

	printf("%s %d\n", str, size);

	for (n = 0; n < size; n++) {
		printf("%5d", arr[n]);

		// 한줄에 10 개씩 출력
		if ((n + 1) % 10 == 0) printf("\n");
	}
	printf("\n");
}
