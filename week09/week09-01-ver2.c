#include <stdio.h>
#include <ctype.h>

// 영문자는 26자로 구성, 각 알파벳이 나온 횟수를 카운팅하기 위한 변수
int alphabet[26] = { 0 };

int main() {
	char buffer[256], *pch;
	int n;
	FILE *fp = fopen("malloc.txt", "r");

	// 한 라인씩 읽어가면서
	while (fgets(buffer, 255, fp) != NULL) {
		pch = buffer;
		while (*pch != NULL) {
			// 라인의 각 문자가 알파벳 대/소문자이면 해당 문자의 카운트를 하나씩 증가

			if (isupper(*pch)) alphabet[*pch - 'A']++;
			else if (islower(*pch)) alphabet[*pch - 'a']++;
			pch++;
		}
	}

	fclose(fp);

	printf("파일의 영문자 수\n\n");

	for (n = 0; n < 26; n++) {
		printf("%c: %2d", n + 'A', alphabet[n]);
		if ((n + 1) % 5 == 0) printf("\n");
		else printf(", ");
	}

	return 0;
}

