#include <stdio.h>
#include <stdlib.h>

void print_array(const char *, const int[], int);
int *read_data1(int *);

int main() {
	// 변수 선언 및 초기화
	int *data = NULL;
	int size = 0;
	int index, key = 1, i;

	// 파일에서 데이터 읽기
	data = read_data1(&size);
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

	if (data) {
		// 동적 할당이 된 data가 가리키는 메모리 해제
		free(data);
	}

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

int *read_data1(int *psize) {
	int *arr = NULL, size = 0, i;
	char temp[20];	// 임시 버퍼
	const char *FILE_PATH = "sorted.txt";	// 입력 파일 경로
	FILE *fp = fopen(FILE_PATH, "r");		// 읽기 모드로 파일 열기

	if (fp) {
		fscanf(fp, "%s %d", temp, &size); // "정렬: 데이터수" 입력 - temp로 정렬을 읽어들이고 무시(프로그램에는 불필요한 값)
		if (size > 0) {
			// 읽을 데이터가 있다면, 배열을 읽을 데이터만큼 동적 할당
			arr = (int *)malloc(sizeof(int) * size);
			for (i = 0; i < size; i++) {
				fscanf(fp, "%d", arr + i);
			}
		}
		fclose(fp);
	}
	else {
		printf("파일이 존재하지 않습니다.\n");
	}
	*psize = size;
	return arr;
}
