//
// Created by zheyu on 5/28/20.
//

#ifndef THREAD_POOL_TASK_H
#define THREAD_POOL_TASK_H
class Task {
public:
    Task *prev;
    Task *next;
    void *arg;   //callback function arg
    void (*func)(void *arg);   //callback function
public:
    Task(void (*func)(void * arg), void *arg);
    Task() {
        prev = nullptr;
        next = nullptr;
    }
};


#endif //THREAD_POOL_TASK_H
