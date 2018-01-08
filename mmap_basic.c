#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(){

	struct stat sb;
	off_t len;
	char *p;
	int fd;

	fd = open("buccaneer.txt",O_RDONLY);
	// chap8장 예제 : 파일에 대한 정보 반환
	fstat(fd, &sb);

	p = mmap(0, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
	close(fd);

	for(len = 0; len<sb.st_size; len++)
		putchar(p[len]);

	munmap(p, sb.st_size);

	return 0;
}
