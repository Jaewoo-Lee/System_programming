#include <stdio.h>

int main(){

	struct player{
		char name[16];
		unsigned int height;
		unsigned int weight;
	};

	struct player Kim = {"Kim-Jinsub",180,70};
	struct player playerRead;

	FILE *fin, *fout;

	fout = fopen("playerInfo.data","w");
	fwrite(&Kim, sizeof(struct player),1,fout);
	printf("fout : %d\n",fout);
	fclose(fout);

	fin = fopen("playerInfo.data","r");
	fread(&playerRead, sizeof(struct player), 1, fin);
	fclose(fin);

	printf("Name = %s, Height : %u, Weight : %u\n", playerRead.name, playerRead.height, playerRead.weight);

	return 0;
}
