#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    string path;
    cout << "Please enter the pathname: ";
    getline(cin, path);

    struct stat data;

    lstat(path.c_str(), &data);

    string mode;
    switch (data.st_mode & S_IFMT) {
        case S_IFREG:
            mode = "File";
            break;
        case S_IFDIR:
            mode = "Directory";
            break;
        case S_IFIFO:
            mode = "Pipe";
            break;
    }

    
    cout << "Inode #: " << data.st_ino << endl;
    cout << "Mode: " << mode << endl;
    cout << "Owner: " << data.st_uid << endl;

    return 0;
}
