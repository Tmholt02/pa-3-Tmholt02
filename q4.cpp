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

    cout << "Inode #: " << data.st_ino << endl;
    cout << "Mode: " << data.st_mode << endl;
    cout << "Owner: " << data.st_uid << endl;

    return 0;
}
