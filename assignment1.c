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
	time_t tempTime;
	time = ctime(&tempTime);

	char* directory = calloc(sizeof(char),100);
	getcwd(directory, 100);

	printf("P0: PID: %d \n", (int)pid);
	printf("P0: PPID: %d \n", (int)ppid);

	printf("P0: HostName: %s \n", hostName);

	printf("P0: UserID: %s \n", userID);

	printf("P0: Time: %s \n", time);

	printf("P0: Current Directory: %s \n", directory);

        puts("P0: this is the parent process");


	char* whaleString = calloc(sizeof(char),100);
	putenv("WHALE=7");
	whaleString = getenv("WHALE");

	printf("P0: WHALE is equal to  %s \n", whaleString);

	int shrimp = 5;

	pid_t child2pid;
	pid_t child1pid = fork();

	pid_t cpid = getpid();
	pid_t cppid = getppid();
	if((int)cpid == 0)
	{
		printf("C1: PID: %d \n", (int)cpid);
		printf("C1: PPID: %d \n", (int)cppid);
		shrimp = 7;
		sleep(1);
	}

	if(getpid() == pid)
	{
		child2pid = fork();
	}

	if(getpid() == 0)
	{
		printf("C2: PID: %d \n",(int)getpid());
		printf("C2: PPID: %d \n",(int)getppid());
		shrimp = 6;
		sleep(1);
	}

	int i;
	for(i = atoi(whaleString); i > 0; i--)
	{
		whaleString = getenv("WHALE");
		if(child1pid == 0)
		{
			printf("C1:SHRIMP = %d, WHALE is equal to  %s \n",shrimp, whaleString);
			sprintf(whaleString, "%d", atoi(getenv("WHALE"))-1);
			setenv("WHALE",whaleString,1);
			shrimp = shrimp - 3;
			i--;
			sleep(1);
		}
		if(child2pid == 0)
		{
			printf("C2:SHRIMP = %d, WHALE is equal to  %s \n", shrimp, whaleString);
			sprintf(whaleString, "%d", atoi(getenv("WHALE"))-1);
			setenv("WHALE",whaleString,1);
			shrimp = shrimp - 3;
			i--;
			sleep(2);
		}
		else
		{
			printf("P0:SHRIMP = %d, WHALE is equal to  %s \n", shrimp, whaleString);
			sprintf(whaleString, "%d", atoi(getenv("WHALE"))-1);
			setenv("WHALE", whaleString,1);
			shrimp = shrimp - 3;
			i--;
		}
		printf("end of for loop %d \n",i);
	}
	printf("end of for loop for realsies \n");

	if(hostName) free(hostName);
	if(userID) free(userID);
	//if(time) free(time);
	if(directory) free(directory);
	//if(whaleString) free(whaleString);

        return 0;
}




