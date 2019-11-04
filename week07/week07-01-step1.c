/*
  7주차 예제: 선택정렬 - 프로그램 구조
*/
#include <stdio.h>
#define SIZE 10	// 배열 크기

// 난수를 생성하여 배열 초기화
void generate_random(int[]);

// 배열 출력
void print_array(const char *, const int[]);

// 선택 정렬
void selection_sort(int[]);


int main() {
	// 지역 변수 선언
	int data[SIZE], n;

	// 총 3회 수행
	for (n = 0; n < 3; n++) {
		// 난수로 배열 초기화 및 배열 출력
		generate_random(data);
		print_array("원본: ", data);

		// 선택 정렬 후 배열 출력
		selection_sort(data);
		print_array("정렬: ", data);

		printf("\n");
	}

	return 0;
}

void generate_random(int arr[]) {
	// 난수를 생성하여 배열 arr에 값 할당
}

void print_array(const char *str, const int arr[]) {
	// 배열 arr 출력
}

void selection_sort(int arr[]) {
	// 배열 arr을 선택정렬
}