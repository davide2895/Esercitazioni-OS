#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>

struct my_msg_st {
	long int my_msg_type;
	char some_text[512];
};

int main(){
	
	struct my_msg_st some_data;
	int msgid;
	key_t key;
	char buffer[512];
	int running=1;
	int len;
	int msgsnd_return;
	
	key=ftok("/tmp",'B');
	if(key== -1){
		perror("ftok");
		exit(-1);
	}
	//create massage queue
	msgid = msgget (key, 0666|IPC_CREAT);
	if(msgid== -1){
		perror("Unable to create queue");
		exit(errno);
	}
	
	while (running){
		printf("Enter some text ");
		scanf("%s", buffer);
		printf("you have entered %s\n",buffer);
		strcpy(some_data.some_text,buffer);
		len= strlen(some_data.some_text)+1;
		msgsnd_return= msgsnd(msgid, &some_data, len, 0);
		if(msgsnd_return == -1){
			perror("Unable to send message");
			exit(errno);
		}
		if(strcmp(buffer,"end")==0){
			running=0;
		}
	}
	
}