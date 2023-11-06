#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int pipefd[2];
    char buf;
    pid_t cpid;
    char *filename = (char*)"quickFox.txt";
    int fd;

    // Create a pipe for communication
    if (pipe(pipefd) == -1) {
        perror("Whoops! Failed to make pipe :(");
        exit(EXIT_FAILURE);
    }

    // Open a file
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Whoops! Failed to open that file :(");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    cpid = fork();
    if (cpid == -1) {
        perror("Whoops! Failed to fork the child process :(");
        exit(EXIT_FAILURE);
    }

    // I am the parent
    if (cpid != 0) {
        
        // Close unused read end
        close(pipefd[0]);         

        // Unlink the file
        if (unlink(filename) == -1) {
            perror("Whoops! Parent process failed to delete the test file :(");
            exit(EXIT_FAILURE);
        }

        // Execute ls to show the file is gone
        printf("ls after deletion:\n");
        char *args2[] = {(char*)"ls", NULL};
        execvp("ls", args2);

        // Send synchronization message to child
        write(pipefd[1], "x", 1);
        close(pipefd[1]);

        // Wait for child
        wait(NULL);                
        exit(EXIT_SUCCESS);
    }

    // I am the child
    else {
        
        // Close unused write end
        close(pipefd[1]);          

        // Wait for synchronization message from parent
        read(pipefd[0], &buf, 1);

        // Try to read the file
        char filebuf[100];
        ssize_t count = read(fd, filebuf, sizeof(filebuf) - 1);
        if (count == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        filebuf[count] = '\0';
        printf("Child read from file: %s\n", filebuf);

        close(pipefd[0]);
        _exit(EXIT_SUCCESS);

    }
}