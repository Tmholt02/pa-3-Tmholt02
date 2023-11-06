#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main() {
    int fd;
    int count = 0;

    while (true) {

        // This file always exists I think.
        fd = open("/dev/null", O_RDONLY);
        if (fd == -1) {

            // This error is for reaching the limit.
            if (errno == EMFILE) {
                printf("Maximum number of open files reached: %d\n", count);
                exit(EXIT_SUCCESS);
            } else {
                perror("open");
                exit(EXIT_FAILURE);
            }
        }
        count++;
    }

    return 0;
}