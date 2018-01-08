#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(){

	struct stat sb;
	off_t len;
	char *p;
	int fd;

	pid_t pid;

	fd = open("test.txt",O_RDWR);
	fstat(fd,&sb);

	p = mmap(0,sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);

	pid = fork();

	switch(pid){
		case -1:
			perror("fork");
			return 1;
		case 0:
			printf("parent : read the shared_file.txt\n");
			for(len=0; len<sb.st_size; len++)
				putchar(p[len]);
			
			printf("parent : now, change the second letter to G.\n");
			p[1] = 'G';
	
			wait();
			munmap(p,sb.st_size);
			break;
		default:
			printf("child : I will sleep.\n");
			for(len = 0; len<sb.st_size; len++)
				putchar(p[len]);

			sleep(1);
			printf("child : read the shared memory.\n");
			for(len = 0; len<sb.st_size; len++)
				putchar(p[len]);
			break;
	}

	return 0;
}
