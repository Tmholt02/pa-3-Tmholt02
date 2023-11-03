#include <iostream>
#include <unistd.h>

// Declare the openr function
extern "C" int openr(const char *pathname);

int main(int argc, char *argv[]) {
    if ( argc != 2 ) {
        std::cerr << "Usage: " << argv[0] << " <pathname>\n";
        return 1;
    }

    // Open the user provided file
    int user_fd = openr(argv[1]);
    if ( user_fd < 0 ) {
        perror("openr failed");
        return 1;
    }

    const int buffer_size = 4096;
    char buffer[buffer_size];
    ssize_t bytes_read;

    while ( ( bytes_read = read(user_fd, buffer, buffer_size) ) > 0 ) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    if ( bytes_read < 0 ) {
        perror("read failed");
        close(user_fd);
        return 1;
    }

    close(user_fd);
    return 0;
}
