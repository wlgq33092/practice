#project name
project(ProcessMgr)

include_directories(./include)
aux_source_directory(./src DIR_SRCS)
#set(LockFreeQue ${DIR_SRCS})

aux_source_directory(./examples/test1 TEST1_SRCS)

add_executable(ProcessMgr ${DIR_SRCS})
add_executable(test1 ${TEST1_SRCS})

