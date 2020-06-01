#include <iostream>
#include "Task.h"
#include "ThreadPool.h"
/**
 * main function, print from 1 to 999 using thread pool
 */
#define TOTAL_TASK 1000
void func(void *arg) {
    int count = *(int *)arg;
    std::cout << count << std::endl;
    //sleep(1);
}
int main() {
    int count = 0;
    ThreadPool *pool = new ThreadPool(4, 4, 1);
    for(int i = 0; i < TOTAL_TASK; ++i) {
        int *arg = new int(count);
        Task *task = new Task(func, arg);
        pool->add_task(task);
        count++;
    }
    while(true) {
        pause();
    }
    return 0;
}
