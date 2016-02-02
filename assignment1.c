#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){

	pid_t pid = getpid();
	pid_t ppid = getppid();

	char* hostName = calloc(sizeof(char),100);
	gethostname(hostName, 100);

	char* userID = calloc(sizeof(char),100);
	cuserid(userID);

	char* time = calloc(sizeof(char),100);
	time_t* tempTime;
	time = ctime(tempTime);

	char* directory = calloc(sizeof(char),100);
	getcwd(directory, 100);

	printf("P0: PID: %d \n", (int)pid);
	printf("P0: PPID: %d \n", (int)ppid);

	printf("P0: HostName: %s \n", hostName);

	printf("P0: UserID: %s \n", userID);

	printf("P0: Time: %s \n", time);

	printf("P0: Current Directory: %s \n", directory);

       // puts(getpid());
       // puts(getppid());
       // puts(gethostname());
       // puts(cuserid());
       // puts(ctime());
       // puts(getcwd());
        puts("P0: this is the parent process");

	if(hostName) free(hostName);
	if(userID) free(userID);
	if(time) free(time);
	if(directory) free(directory);

        return 0;
}




