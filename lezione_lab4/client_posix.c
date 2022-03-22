#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>

#define NAME "/shmem"
#define SIZE (2 * sizeof(int))

//POSIX EXAMPLE
// to compile use gcc client_posix.c -o client_posix -lrt

int main(){
	
	int fd, i;
	int *data;
	
	fd=shm_open(NAME, O_CREAT | O_RDWR, 0666); //no size
	
	if(fd<0){
		perror("shm_open()"); //proper funcion to report errors
		exit(-1);
	}
	
	//define the size of the shm
	ftruncate(fd, SIZE);
	
	//attach the shm
	data = (int *) mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0);
	if(data<0){
		perror("mmap() error");
	}
	
	for(i=0; i<2; i++){
		printf("reading in the shared memory: data[%d]: %d\n", i, data[i]);
	}
	
	munmap(data, SIZE);
	close(fd);
	shm_unlink(NAME); //destroy the shared memory
	
}