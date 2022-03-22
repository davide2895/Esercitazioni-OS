#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){
	char command[50];
	int sys_value;
	
	strcpy (command,"ls -l");
	
	sys_value=system(command);
	printf("Return from the system %d\n",sys_value);
	exit(0);
}