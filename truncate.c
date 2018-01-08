#include <unistd.h>

int main(){

	int ret;
	ret = truncate("./p_test.txt",45);
	
	if(ret ==1){
		perror("truncate");
		return -1;
	}

	return 0;
}

