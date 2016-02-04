//
//  main.cpp
//  practice
//
//  Created by wuge on 15/10/10.
//  Copyright (c) 2015年 wuge. All rights reserved.
//

#include <iostream>
#include "Queue.h"

void TestQue() {
    Queue<int> que;
    for (int i = 0; i < 20; i++) {
        que.push(i);
    }
    
    for (int i = 0; i < 20; i++) {
        cout << "ele: " << que.front() << endl;
        que.pop();
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TestQue();
    
    return 0;
}
