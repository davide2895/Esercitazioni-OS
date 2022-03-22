#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	pid_t pid_ch1;
	pid_ch1=fork();
	for(int i=0; i<2; i++){
		switch (pid_ch1){
			case -1:
				printf ("fork failed");
				exit(-1);

			case 0:
				printf("i am child, PID %d parent is %d\n",getpid(),getppid());
				pid_ch1=fork();

			default:
				sleep(2);
				printf("i am parent, PID %d\n",getpid());
		}
	}
}
