#include <fcntl.h> //open
#include <stdio.h> //printf
#include <stdlib.h> //printf
#include <unistd.h> //read
#include <string.h> //strtok


int main(int argc, char* argv[]){
    printf("> ");
    fflush(stdout); //Allow display on every shell
    
    //Define var
    int MAXLINE = 1024;
    int MAXARGS = 1024;
    char cmd[MAXLINE];
    
    //Reading keyboard
    if (fgets(cmd,MAXLINE,stdin) == NULL){
        printf("No command to execute\n");
    }
    
    //Exec
    int i;
    char* args[MAXARGS];
    args[0] = strtok(cmd, " \t\n");
    for (i = 1; i < MAXARGS; i++) {
        if ((args[i] = strtok(NULL, " \t\n")) == NULL) break;
    }
    
    if (fork()==0){
        execvp(args[0], args);
        exit(0);
    }
    printf(">Command ID is : %d<\n",wait(0));
    
    //Final print
    printf(">Terminated<\n");
}
