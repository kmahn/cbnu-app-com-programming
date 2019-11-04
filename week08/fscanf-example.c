#include <stdio.h>

int main() {
	char str[80];
	float f;
	FILE *pfile;

	pfile = fopen("myfile.txt", "r");
	fscanf(pfile, "%f", &f);
	fscanf(pfile, "%s", str);
	fclose(pfile);
	printf("I have read: %f and %s\n", f, str);

	return 0;
}