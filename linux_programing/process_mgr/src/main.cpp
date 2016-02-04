#include <iostream>
#include <string>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main() {
    pid_t pid;

    pid = fork();

    int pipe = open("./info", O_RDWR);
    if (pipe < 0) {
        system("touch ./info");
        pipe = open("./info", O_RDWR);
    }

    if (pid < 0) {
        cout << "fork error!" << endl;
        return 0;
    } else if (pid == 0) {
        cout << "child process!" << endl;
        sleep(1);
        char buf[32] = {0};
        read(pipe, buf, 11);
        cout << "message from parent: " << buf << endl;
        close(pipe);
    } else {
        write(pipe, "hello, son!", 11);
        if (waitpid(pid, NULL, 0) < 0) {
            cout << "wait for child error!" << endl;
        } else {
            cout << "parent process wait child finish done!" << endl;
        }
        close(pipe);
    }

    return 0;
}
