#include <stdio.h>

int main(){

	int c;

	FILE *fin, *fout;

	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");

	while((c=fgetc(fin)) != EOF)
		fputc(c,fout);

	fclose(fin);
	fclose(fout);

	return 0;
}
