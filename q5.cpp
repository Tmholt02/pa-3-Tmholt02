#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main() {
    int fd;
    int count = 0;

    // Loop until the open call fails with EMFILE error
    while (1) {
        fd = open("/dev/null", O_RDONLY); // Open a file that always exists
        if (fd == -1) {
            // Check if the error is EMFILE
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