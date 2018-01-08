#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char** argv){

	if(argc != 3){
		printf("seekfile : invalid parameters\n");
		printf("seekfile filename index\n");
		return -1;
	}

	char sFileName[256];
	int nIndex;
	int nFds;
	int nRet;
	char cFound;

	strcpy(sFileName, argv[1]);
	nIndex = atoi(argv[2]);	

	nFds = open(sFileName, O_RDONLY);

	if(nFds == -1){
		perror("file open error");
		return -1;
	}

	nRet = lseek(nFds, nIndex, SEEK_SET);

	if(nRet == -1){
		perror("lseek error");
		return -1;
	}

	printf("nRet : %d\n",nRet);

	read(nFds, &cFound, 1);
	printf("file : %s\n index : %d\n charater : %c\n",sFileName, nIndex, cFound);

	close(nFds);

	return 0;
}
