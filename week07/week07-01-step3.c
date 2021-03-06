/*
7주차 예제: 선택정렬 - 난수 생성 및 출력 구현
*/
#include <stdio.h>
#include <stdlib.h> // srand(), rand() 함수
#include <time.h>	// time() 함수
#define SIZE 10		// 배열 크기
#define MAX 1000	// 난수 생성 범위

// 난수를 생성하여 배열 초기화
void generate_random(int[]);

// 배열 출력
void print_array(const char *, const int[]);

// 선택 정렬을 위한 도구 함수
int find_min(const int[], int);
void swap(int *, int *);
// 선택 정렬
void selection_sort(int[]);


int main() {
	// 지역 변수 선언
	int data[SIZE], n;

	// 난수 생성 시드값 초기화는 한 번만
	srand((unsigned)time(NULL));

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
	int n;

	// 배열의 크기만큼 난수를 생성하여 배열에 할당
	for (n = 0; n < SIZE; n++) {
		arr[n] = rand() % MAX + 1;
	}
}

void print_array(const char *str, const int arr[]) {
	// 배열 arr 출력
	int n;
	printf(str); // 배열의 제목 출력

				 // 배열의 원소 출력
	for (n = 0; n < SIZE; n++) printf("%5d", arr[n]);

	// 다음 출력 구분을 위해 줄바꿈
	printf("\n");
}

int find_min(const int arr[], int start) {
	// 배열의 start 인덱스에서부터 시작하여 가장 최소값이 있는 곳의 인덱스를 리턴
	int n, minindex = start;
	for (n = start + 1; n < SIZE; n++) {
		if (arr[minindex] > arr[n]) minindex = n;
	}
	return minindex;
}

void swap(int *px, int *py) {
	// px와 py가 가리키는 메모리의 값을 교환
	int temp = *px;
	*px = *py;
	*py = temp;
}

void selection_sort(int arr[]) {
	// 배열 arr을 선택정렬
	int n, minindex;
	for (n = 0; n < SIZE - 1; n++) {
		minindex = find_min(arr, n);
		swap(arr + minindex, arr + n);
	}
}
