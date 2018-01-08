#include <stdio.h>

int main(){

	char str[512];
	int n;

	FILE *fp;

	fp = fopen("test.txt","r");
	
	printf("%s\n", fgets(str, 512, fp));

	fseek(fp, 10, SEEK_SET);
	printf("3. %s\n", fgets(str, 512, fp));

	fseek(fp, 5, SEEK_SET);
	printf("2.1 %s\n",fgets(str,10,fp));
	fseek(fp, 5, SEEK_CUR);
	printf("2. %s\n", fgets(str, 512, fp));

	fseek(fp, -6, SEEK_END);
	printf("3. %s\n", fgets(str, 512, fp));

	fseek(fp, -10, SEEK_CUR);
	printf("4. %s\n", fgets(str, 512, fp));

	fclose(fp);

	return 0;
}
