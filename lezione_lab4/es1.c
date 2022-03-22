#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
	
	int shmid, i, status;
	int *a;
	pid_t pid;
	
	shmid = shmget(IPC_PRIVATE, 2*sizeof(int), 0666|IPC_CREAT); 
	//0666 sono i privilegi di user, group e others, 4 è read, 2 è write, 1 è execute, 4+2=6
	// potremmo anche scrivere 0600 tanto è IPC_PRIVATE
	if (shmid<0){
		printf("error creating shared memory\n");
		exit(-1);
	}
	
	a = (int*) shmat(shmid,NULL,0);
	//shmid returns a void pointer, if we have disomogeneous data in the shared memory it's useful
	
	pid=fork();
	if(pid<0){
		printf("fail fork\n");
	}else if(pid==0){
		//child
		sleep(4);
		printf("child reads a0: %d, a1: %d\n",a[0],a[1]);
	}else{
		//parent
		a[0]=0;
		a[1]=1;
		for(i=0; i<10; i++){
			a[0]=a[1]+a[0];
			a[1]=a[1]+a[0];
			printf("parent writes a0: %d, a1: %d\n",a[0],a[1]);
		}
		wait(&status);
	}
	
	//detach the shared memory for both parent and children
	shmdt(a);
	shmctl(shmid, IPC_RMID, 0);
	
}