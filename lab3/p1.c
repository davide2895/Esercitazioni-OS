#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main (){
	pid_t pid;
	pid=fork();
	if (pid==0){
		printf("call the execl \n");
		execl("/home/davide/Scrivania/lab3/prog","prog",NULL);
		printf("fail execl \n");
		exit(-1);
	} else {
		wait(NULL);
		printf("child terminated \n");
		exit(0);
	}
}