#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

	if(argc != 4){
		printf("mkfile : invalid parameters\n");
		printf("mkfile filename character repeat\n");
		return -1;
	}

	char sFileName[256];
	char cCharacter;
	int nRepeat;

	strcpy(sFileName,argv[1]);	
	cCharacter = argv[2][0];
	nRepeat = atoi(argv[3]);

	int nFds;

	nFds = creat(sFileName, 0644);

	if(nFds == -1){
		perror("file create error");
		return -1;
	}

	int i;
	for(i=0;i<nRepeat;i++){
		write(nFds, &cCharacter,1);
	}

	close(nFds);

	return 0;
}
