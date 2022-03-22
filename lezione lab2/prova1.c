#include <stdio.h> //printf function
#include <unistd.h> // ?fork function?
#include <sys/types.h> //stores process identifier
#include <stdlib.h> //exit function

int main(){
	
	pid_t fork_result;
	printf("Beginning of execution \n");
	
	fork_result = fork(); //create a child process
	
	if(fork_result<0){
		printf("creation fail \n");
		exit(1); //something went wrong, the numeric value doesn't matter, there are some number associated to specific error
	} else {
		if(fork_result==0){
			printf("child process \n");
			printf("my PID is %d\n", getpid());
			printf("parent PID is %d\n", getppid());
			exit(0); //equivalent to return 0, means evreything went ok
		} else{
			printf("parent process \n");
			printf("my PID is %d\n", getpid());
			printf("parent PID is %d\n", getppid());
			sleep(2); //affect state machine, it stays in the waiting statefor a certain ammount of seconds
			exit(0);
		}
	}	

}