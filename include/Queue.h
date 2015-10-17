//
//  Queue.h
//  practice
//
//  Created by wuge on 15/10/10.
//  Copyright (c) 2015年 wuge. All rights reserved.
//

#ifndef __practice__Queue__
#define __practice__Queue__

#include <iostream>
#include "pthread.h"

using namespace std;

template<typename T>
class Queue {
private:
    int len;
    int max_size;
    int head;
    int tail;
    int* flag;
    T* data;
    
public:
    Queue() : max_size(128), head(0), tail(0), len(0) {
        data = new T(128);
        flag = new int[128];
    }
    Queue(int max_size) : max_size(max_size), head(0), tail(0), len(0) {
        data = new T(max_size);
        flag = new int[max_size];
    }
    ~Queue() {
        delete[] data;
        delete[] flag;
    }
    
    int length() { return this->len; }
    
    int empty() {
        return (this->len == 0);
    }
    
    int full() {
        return (this->len == this->max_size);
    }
    
    void push(T ele) {
        if (!this->full()) {
            data[(tail++) % this->max_size] = ele;
            this->len++;
        } else {
            cout << "que is full now!" << endl;
        }
    }
    
    void pop() {
        if (!this->empty()) {
            head = (head + 1) % this->max_size;
            this->len--;
        } else {
            cout << "this que is empty!" << endl;
        }
    }
    
    void mt_push(T ele) {
        if (!this->full()) {
            if (0 == __sync_val_compare_and_swap(&flag[tail], 0, 1)) {
                data[tail % this->max_size] = ele;
                __sync_add_and_fetch(&tail, 1);
                __sync_add_and_fetch(&len, 1);
                tail = tail % this->max_size;
            } else {
                
            }
        } else {
            cout << "this que is full! can't push ele!" << endl;
        }
        
    }
    
    void mt_pop() {
        if (!this->empty()) {
            if (1 == __sync_val_compare_and_swap(&flag[head], 1, 0)) {
                __sync_add_and_fetch(&head, 1);
                __sync_sub_and_fetch(&len, 1);
                head = head % this->max_size;
            }
        } else {
            cout << "this que is empty! can't pop ele!" << endl;
        }
    }
    
    void mt_front() {
        if (1 == __sync_val_compare_and_swap(&flag[head], 1, 0)) {
            
        }
    }
    
    T& front() { return data[head]; }
};

class TestQueue {
public:
    TestQueue();
    ~TestQueue();
};

#endif /* defined(__practice__Queue__) */
