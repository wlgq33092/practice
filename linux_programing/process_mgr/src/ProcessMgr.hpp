#include <iostream>

class ProcessMgr {
private:
    pid_t pid;

public:
    ProcessMgr() {
        pid = getPid();
    }

    ~ProcessMgr() {
    }
};
