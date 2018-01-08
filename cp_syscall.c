#include <fcntl.h>

int main(){

	char c;
	int fdin, fdout;

	fdin = open("input.txt",O_RDONLY);
	fdout = open("output.txt",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);

	while(read(fdin,&c,1) == 1)
		write(fdout,&c,1);
	
	close(fdin);
	close(fdout);

	return 0;
}
