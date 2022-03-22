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
		char *binaryPath = "/usr/bin/bash";
		char *arg1 = "-c";
		char *arg2 = "echo \"visit $HOSTNAME:$PORT from your browser.\"";
		char *const env[] = {"HOSTNAME=www.linuxhint.com","PORT=8080",NULL};
		
		execle(binaryPath,binaryPath,arg1,arg2,NULL,env);
		printf("exec fail \n");
		exit(1);
	} else {
		//parent
		wait(NULL);
		printf("child ended \n");
	}
	exit(0);
}