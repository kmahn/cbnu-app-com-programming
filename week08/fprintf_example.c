#include <stdio.h>

int main() {
	// ���� ������ ����
	FILE *fp;
	
	// ���� ����
	fp = fopen("myfile.txt", "w");

	if (fp) {
		// ���Ͼ��� �ݱ�
		fprintf(fp, "My first file\n");
		fclose(fp);
	}

	return 0;
}