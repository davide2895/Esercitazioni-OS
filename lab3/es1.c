#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main (){
	pid_t pid;
	pid=fork();
	int status;
	if (pid==0){
		sleep(5);
		printf("child 1 ended\n");
		exit(0);
	} else {
		pid=fork();
		if (pid==0){
			sleep(5);
			printf("child 2 ended\n");
			exit(0);
		} else {
			waitpid(pid,&status,0);
			printf("child terminated \n");
			exit(0);
		}
	}
}