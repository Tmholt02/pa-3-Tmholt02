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
        default:
            mode = "Other";
    }

    string permission = (data.st_mode & S_IRUSR) != 0 ? "Read ":"";
    if ((data.st_mode & S_IWUSR) != 0) permission += "Write ";
    if ((data.st_mode & S_IXUSR) != 0) permission += "Execute ";
    
    cout << "Inode #: " << data.st_ino << endl;
    cout << "Mode: " << mode << endl;
    cout << "Permission: " << permission << endl;

    return 0;
}
