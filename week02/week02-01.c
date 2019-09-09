#include <stdio.h>

int main() {
	// 1. 지역 변수 선언
	char dept[20], name[20];
	int grade, year;

	// 2. 안내문 출력 및 입력
	printf("정보를 입력하세요.\n\n");
	printf("학과: ");
	scanf("%s", dept);
	printf("학년: ");
	scanf("%d", &grade);
	printf("입학년도: ");
	scanf("%d", &year);
	printf("이름: ");
	scanf("%s", name);

	// 3. 자기 소개 출력
	printf("\n나는 %s %d학년 %d학번 %s입니다.\n", dept, grade, year, name);
	return 0;
}