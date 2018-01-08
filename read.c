#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 512

void main(){

	char buffer[BUFSIZE];
	int fd;
	ssize_t nread;
	long total = 0;

	if((fd=open("testfile.txt",O_RDONLY))==-1){
		printf("Cannot read\n");
		exit(1);
	}
	while((nread=read(fd,buffer,BUFSIZE))>0)
		total += nread;

	close(fd);

	printf("Number of characters in testfile : %d\n",total);
	exit(0);
}
