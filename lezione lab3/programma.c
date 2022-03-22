#include <stdio.h>

int main(int argc, char* argv[]){
	printf("Hello this is a program printing command line parameters\n");
	for(int i=0; i<argc; i++){
		printf("command n.%d value %s\n",i,argv[i]);
	}
	return 0;
}