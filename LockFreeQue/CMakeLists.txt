#project name
project(LockFreeQue)

include_directories(./include)
aux_source_directory(./src DIR_SRCS)
#set(LockFreeQue ${DIR_SRCS})

add_executable(LockFreeQue ${DIR_SRCS})
