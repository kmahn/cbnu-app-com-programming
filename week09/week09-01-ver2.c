#include <stdio.h>
#include <ctype.h>

// �����ڴ� 26�ڷ� ����, �� ���ĺ��� ���� Ƚ���� ī�����ϱ� ���� ����
int alphabet[26] = { 0 };

int main() {
	char buffer[256], *pch;
	int n;
	FILE *fp = fopen("malloc.txt", "r");

	// �� ���ξ� �о�鼭
	while (fgets(buffer, 255, fp) != NULL) {
		pch = buffer;
		while (*pch != NULL) {
			// ������ �� ���ڰ� ���ĺ� ��/�ҹ����̸� �ش� ������ ī��Ʈ�� �ϳ��� ����

			if (isupper(*pch)) alphabet[*pch - 'A']++;
			else if (islower(*pch)) alphabet[*pch - 'a']++;
			pch++;
		}
	}

	fclose(fp);

	printf("������ ������ ��\n\n");

	for (n = 0; n < 26; n++) {
		printf("%c: %2d", n + 'A', alphabet[n]);
		if ((n + 1) % 5 == 0) printf("\n");
		else printf(", ");
	}

	return 0;
}

