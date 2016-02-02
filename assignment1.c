#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	pid_t pid = getpid();
	pid_t ppid = getppid();

	char* hostName = calloc(sizeof(char),100);
	gethostname(hostName, 100);

	char* userID = calloc(sizeof(char),100);
	cuserid(userID);

	printf("P0: PID: %d \n", (int)pid);
	printf("P0: PPID: %d \n", (int)ppid);

	printf("P0: HostName: %s \n", hostName);

	printf("P0: UserID: %s \n", userID);

       // puts(getpid());
       // puts(getppid());
       // puts(gethostname());
       // puts(cuserid());
       // puts(ctime());
       // puts(getcwd());
        puts("P0: this is the parent process");

        return 0;
}




