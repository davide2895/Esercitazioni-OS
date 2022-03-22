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
		execl("./programma","programma","lino","pino","gino",NULL); //RELATIVE PATH, ATTENTION!!!
		printf("exec fail \n");
		exit(1);
	} else {
		//parent
		wait(NULL);
		printf("child ended \n");
	}
	exit(0);
}