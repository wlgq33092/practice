#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <Log.h>

class ProcessMgr {
private:
    pid_t pid;
    int num_of_cproc;
    std::vector<int> cproc_pids;

    void start_cproc(int cproc_num);
    void signal_handle();

public:
    ProcessMgr();
    ProcessMgr(int cproc_num);

    ~ProcessMgr();

    void run();
    void runCmd(std::string cmd);
    void monitor(pid_t pid);
    int addOneCProc(std::string bin);
    void addCProcs(int cproc_num);

    bool isUnderControl(pid_t pid);
    int getCProcNum();
    void printCProcsPid();
    int killOneCProc(pid_t pid);
    int killAllCProc();
};

/*
class ProcessGroup {

};
*/
