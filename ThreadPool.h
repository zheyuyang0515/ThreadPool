//
// Created by zheyu on 5/28/20.
//

#ifndef THREAD_POOL_THREADPOOL_H
#define THREAD_POOL_THREADPOOL_H
#include <iostream>
#include <pthread.h>
#include "Task.h"
#include <unistd.h>
#define DEFAULT_SLEEP_TIME 10       //adjust the number of worker every this seconds
#define ADD_THREAD_RATE 0.8         //add new threads into the pool when (the number of busy threads in the pool) / (the number of threads in the pool) >= this rate
#define DEL_THREAD_RATE 0.3         //remove threads from the pool when(the number of busy threads in the pool) / (the number of threads in the pool) <= this rate
class ThreadPool;
class Worker {
private:
    pthread_t pid;
    //Task *task_head;

private:
    static void *init_worker(void * arg);

public:
    Worker *prev;   //prev pointer
    Worker *next;   //next pointer
public:
    Worker(ThreadPool *pool);
    Worker() {
        prev = nullptr;
        next = nullptr;
    };
    ~Worker(){};
};

class Manager {
private:
    pthread_t pid;
private:
    static void *init_manager(void * arg);
public:
    Manager(ThreadPool *pool);
    ~Manager(){};
};

class ThreadPool {
private:
    Manager *manager;

public:
    pthread_mutex_t lock;
    pthread_cond_t empty_queue_cond;
    Task *tasks_head;     //task_head dummy queue
    Task *tasks_tail;        //task_tail dummy queue
    Worker *workers_head;     //worker_head dummy queue(threads)
    Worker *workers_tail;     //worker_tail dummy queue(threads)
    int tasks_num, workers_num;        //queue size of tasks and workers
    int min_thread_num, max_thread_num, add_step;
    int delete_thread_num;      //number of threads need to be deleted at present
    int busy_thread_num;        //number of busy thread

public:
    //add a node to the tail of the queue
    template <class T>
    static void add_node(T *node, T *nodes);

    //remove and return node from the head of the queue
    template<class T>
    static T* remove_node(T *head, T *tail);

    //add a task into the queue
    void add_task(Task *task);

public:
    ThreadPool(int min_thread_num, int max_thread_num, int add_step);
    ~ThreadPool();
};



#endif //THREAD_POOL_THREADPOOL_H
