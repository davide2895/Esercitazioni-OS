#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main(){
	
	int shmid;
	key_t key;
	char *str;
	pid_t pid;
	
	key=ftok("/tmp",'A');
	shmid = shmget(key, 1024, 0666|IPC_CREAT);
	if (shmid<0){
		printf("failed creating shared memory\n");
		exit(-1);
	}
	
	str = (char*) shmat(shmid,NULL,0);
	//shmid returns a void pointer, if we have disomogeneous data in the shared memory it's useful
	strcpy(str,"This is a message from the server \n");
	printf("Data written in the memory by the server \n");
	
	if(shmdt(str)!=0){
		printf("error detaching \n");
	}
	return(0);
	
}