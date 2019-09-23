#include <stdio.h>
#define NMAX 5
#define OUTPUT_MESSAGE "1 ~ 4번 중 한 후보의 번호를 입력하시오: "

int main() {
	// 지역 변수 선언 및 초기화
	int ip[NMAX] = { 0 };  // 득표수를 기록할 배열 원소의 값들을 0으로 초기화
	int n = 0, xdata = 0, i;

	printf(OUTPUT_MESSAGE);

	// scanf는 서식문자에 정확하게 값이 들어온 수를 리턴, 
	// 즉, 입력된 데이터가 숫자로 정확하게 입력되는 동안 반복문 수행(문자가 들어오면 반복 종료)
	while (scanf("%d", &xdata) == 1) {
		n++; // 투표횟수 증가

		// 무효투표인 경우
		if (xdata < 1 || xdata > NMAX) ++ip[0];
		// 정상적인 투표인 경우
		else ++ip[xdata];

		printf(OUTPUT_MESSAGE);
	}

	// 결과 출력
	printf("\n득표수\n");
	for (i = 1; i < NMAX; i++) printf("%d번: %d 표\n", i, ip[i]);
	printf("무효표: %d 표\n", ip[0]);
	printf("총 투표수: %d 표\n", n);

	return 0;
}