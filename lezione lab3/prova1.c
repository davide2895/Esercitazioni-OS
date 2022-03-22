#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	pid = fork();
	if (pid==0){
		//child
		execl("/usr/bin/ls","ls","-a","/home/davide",NULL);
		printf("exec fail \n");
		exit(1);
	} else {
		//parent
		wait(NULL);
		printf("child ended \n");
	}
	exit(0);
}