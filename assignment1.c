int main(int argc, char *argv[]){

        puts(getpid());
        puts(getppid());
        puts(gethostname());
        puts(cuserid());
        puts(ctime());
        puts(getcwd());
        puts("this is the parent process");

        return 0;
}




