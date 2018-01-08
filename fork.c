#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(){

	pid_t pid;
	int nRepeat;
	char *sMessage;

	printf("--------------------------\n");
	printf("before fork pid : %d\n",pid);
	printf("--------------------------\n");

	pid = fork();
	printf("After fork pid : %d\n",pid);


	switch(pid){
		case -1 :
			perror("fork");
			return 1;
		case 0 :
			nRepeat = 5;
			sMessage = "This is the parent!";
			break;
		default :
			nRepeat = 3;
			sMessage = "This is the child!";
			break;
	}

	for( ; nRepeat>0 ; nRepeat--){
		printf("pid : %d, Remain : %d\n", pid, nRepeat-1);
		puts(sMessage);
		sleep(1);
	}

	return 0;
}
