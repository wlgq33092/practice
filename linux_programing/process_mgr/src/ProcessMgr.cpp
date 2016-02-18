#include "ProcessMgr.h"

#include "ProcessMgrError.h"

using namespace std;

ProcessMgr::ProcessMgr() 
    : num_of_cproc(0) {
    this->pid = getpid();    
}

ProcessMgr::ProcessMgr(int cproc_num)
    : num_of_cproc(cproc_num) {
    this->pid = getpid();
}

ProcessMgr::~ProcessMgr() {
}

void ProcessMgr::runCmd(string cmd) {
    if (0 == cmd.compare("add one proc")) {
        this->addOneCProc();
    }
}

void ProcessMgr::run() {
    while (1) {
        cout << "your cmd:" << endl;
        string cmd;
        cin >> cmd;

        this->runCmd(cmd);
    }
}

void ProcessMgr::start_cproc(int cproc_num) {
    if (cproc_num <= 0)
        cproc_num = this->num_of_cproc;

    for (int i = 0; i < cproc_num; ++i) {
        pid_t pid = fork();
        if (pid < 0) {
            Error("%s: fork child process error!\n", __func__);
        } else if (0 == pid) {
            // do invoke exec func to start child process
        } else {
            this->monitor(pid);
        }
    }

    this->run();
}

void ProcessMgr::monitor(pid_t pid) {
    if (pid = waitpid(-1, NULL, 0) < 0) {
        Error("parent process: wait child pid error! child pid = %d\n", pid);
        return ;
    } else {
        Info("child proc %d is returned!\n", pid);
    }
}

int ProcessMgr::addOneCProc() {
    pid_t pid = fork();
    if (pid < 0) {
        Error("%s: fork child process error!\n", __func__);
        return ADDCHILDPROCERROR;
    } else if (0 == pid) {
        // do invoke exec func to start child process
    } else {
        this->cproc_pids.push_back(pid);
        this->monitor(pid);
    }
}

void ProcessMgr::addCProcs(int cproc_num) {
    for (int i = 0; i < cproc_num; ++i) {
        this->addOneCProc();
    }
}

bool ProcessMgr::isUnderControl(pid_t pid) {
    /*
    if (find(cproc_pids.begin, cproc_pids.end(), pid) != cproc_pids.end()) {
        return true;
    } else {
        return false;
    }
    */
}
