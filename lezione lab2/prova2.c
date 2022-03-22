#include <stdio.h> //printf function
#include <unistd.h> // ?fork function?
#include <sys/types.h> //stores process identifier
#include <stdlib.h> //exit function
#include <sys/wait.h>

int main(){
	
	pid_t pid, pid1;
	int status;
	
	printf("Original PID %d\n",getpid());

	pid=fork();

	if(pid == 0){
		printf("child PID %d\n", getpid());
		sleep(3);
		printf("child woke up aftrer sleep PID %d\n", getpid());
		exit(0);
	} else {
		pid=fork();//doesn't overwrite the other pid, these are two different processes

		if(pid==0){
			printf("child2 PID %d\n", getpid());
			sleep(4);
			printf("child2 woke up aftrer sleep PID %d\n", getpid());
			exit(0);
		}else{
			/*PARENT PROCESS*/
			pid1=1;
			while(pid1>0){
				pid1=wait(&status); //wait for a state change for any children
				if(pid1>0){
					printf("child PID %d terminated with status %d\n",pid1,status);
				}
			}
		}
	}
}