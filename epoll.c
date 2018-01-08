#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/epoll.h>

#define MAX_BUFFER_LEN 256
#define MAX_EVENT_NUM	1

int main(){
	int retval, m_read, m_write;
	int i;
	int fd;
	int epfd;
	struct epoll_event ev;
	struct epoll_event evlist[MAX_EVENT_NUM];
	char buffer[MAX_BUFFER_LEN];
	
	if((fd = open("./test.txt", O_RDWR)) == -1){
		perror("open");
		exit(1);
	}

	// epoll create 
	epfd = epoll_create(1);
	if(epfd == -1){
		perror("epoll_create");
		exit(1);
	}	
	
	// epoll control 
	ev.events = EPOLLIN;
	ev.data.fd = STDIN_FILENO;
	
	if(epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &ev) == -1){
		perror("epoll_ctl");
		exit(1);
	}	
	
	while(1){
		// buffer 메모리 크기를 '0x00'으로 LEN만큼 초기화.
		memset(buffer, 0x00, MAX_BUFFER_LEN);

		retval = epoll_wait(epfd, evlist, MAX_EVENT_NUM, -1);
		if(retval == -1){			
			perror("epoll_wait");
			exit(1);				
		}
		
		printf("retval = %d \n", retval);

		for(i = 0; i < MAX_EVENT_NUM; i++){
		
			if(evlist[i].events & EPOLLIN){
				m_read = read(STDIN_FILENO, buffer, MAX_BUFFER_LEN);
				printf("[read] m_read = %d \n", m_read);
				
				m_write = write(fd, buffer, m_read);
				printf("[write] m_write = %d \n", m_write);
			}
		}
		usleep(1000);
	}

	close(fd);
	exit(0);
}
