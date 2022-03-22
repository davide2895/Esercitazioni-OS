#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	pid_t pid, pid_ch, pid_pa;
	int status_value;
	pid=fork();
	switch (pid){
		case -1:
			printf ("fork failed");
			exit(-1);
			
		case 0:
			printf("i am child, PID %d\n",getpid());
			sleep(5);
			exit(2);
			
		default:
			pid_ch=wait (&status_value);
			printf("child end: pid %d\n", pid_ch);
			printf("wifexited(status_value) %d\n",WIFEXITED(status_value));
			
			if (WIFEXITED(status_value)){
				printf("Status Value using Macro: %d\n",WEXITSTATUS(status_value));
				printf("Status Value from the parent: %d\n",status_value>>8);
			} else {
				printf ("Abnormal");
			}
	}
}
