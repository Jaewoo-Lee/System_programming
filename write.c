#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#define MAX 512

int main (){

	int fd;	
	int readn = 0;	
	int writen = 0;	
	char buf[MAX];
	char *buf2 = "This site\n";
	int i;

	fd = open("test_write.txt",O_RDWR);
	if(fd == -1){
		printf("Fail\n");
		return -1;
	}

	writen = write(fd,buf2,strlen(buf2));

	close(fd);
}
