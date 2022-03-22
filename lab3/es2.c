#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main (){
	pid_t pid1,pid2,pid3,pid4,pid5,pid6,pid;
	pid1=fork();
	int status;
	if (pid1==0){
		sleep(1);
		printf("child 1 ended\n");
		exit(0);
	} else {
		pid2=fork();
		if (pid2==0){
			sleep(3);
			printf("child 2 ended\n");
			exit(0);
		} else {
			pid3=fork();
			if (pid3==0){
				sleep(2);
				printf("child 3 ended\n");
				exit(0);
			} else {
				pid4=fork();
				if (pid4==0){
					sleep(6);
					printf("child 4 ended\n");
					exit(0);
				} else {
					pid5=fork();
					if (pid5==0){
						sleep(5);
						printf("child 5 ended\n");
						exit(0);
					} else {
						pid6=fork();
						if (pid6==0){
							sleep(4);
							printf("child 6 ended\n");
							exit(0);
						} else {
							while(1){
								pid=wait(NULL);
								switch(pid){
									case pid1:
										pid1=fork();
										break;
									case pid2:
										pid2=fork();
										break;
									case pid3:
										pid3=fork();
										break;
									case pid4:
										pid4=fork();
										break;
									case pid5:
										pid5=fork();
										break;
									case pid6:
										pid6=fork();
										break;
								}
							}
						}
					}
				}
			}
		}
	}
}