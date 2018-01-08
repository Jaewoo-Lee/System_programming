d#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/uio.h>

int main(){

	char sLine1[48], sLine2[51], sLine3[49];
	struct iovec iov[3];
	ssize_t nr;
	int fd, i;
	
	fd = open("buccaneer.txt", O_RDONLY);
	if(fd == -1){
		perror("open");
		return 1;
	}

	iov[0].iov_base = sLine1;
	iov[0].iov_len = sizeof(sLine1);
	iov[1].iov_base = sLine2;
	iov[1].iov_len = sizeof(sLine2);
	iov[2].iov_base = sLine3;
	iov[2].iov_len = sizeof(sLine3);

	nr = readv(fd, iov, 3);
	if(nr == -1){
		perror("readv");
		return 1;
	}
	sLine1[47] = '\0';
	sLine2[50] = '\0';
	sLine3[48] = '\0';

	for(i=0;i<3;i++){
		printf("%d.1. %s",i+1,(char*)iov[i].iov_base);
	}

	printf("\n\n");
	printf("1.2. %s\n",sLine1);
	printf("2.2. %s\n",sLine2);
	printf("3.2. %s\n",sLine3);

	close(fd);

	return 0;
}






