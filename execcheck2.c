#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int status;

    pid = fork();

    if(pid == 0)
    {
        printf("Child executing Linux command\n");

        execl("/bin/ls", "ls", "-l", NULL);

        printf("Exec failed\n");
        exit(1);
    }
    else if(pid > 0)
    {
        wait(&status);

        printf("\nParent resumed\n");

        if(WIFEXITED(status))
        {
            printf("Exit Status: %d\n",
                   WEXITSTATUS(status));
        }
    }
    else
    {
        printf("Fork Failed\n");
    }

    return 0;
}

