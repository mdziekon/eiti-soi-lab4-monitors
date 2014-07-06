#ifndef SYNC_HPP
#define SYNC_HPP

#include <semaphore.h>

class Semaphore
{
private:
    sem_t sem;

public:
    Semaphore(int value);
    ~Semaphore();

    void wait();
    void post();
};

class Condition
{
    friend class Monitor;

private:
    Semaphore sem = Semaphore(0);

    unsigned int waiting = 0;

public:
    void wait();
    bool signal();
};


class Monitor
{
private:
    Semaphore mutex = Semaphore(1);

public:
    void enter();
    void leave();

    void wait(Condition &condVar);
    void signal(Condition &condVar);
};

#endif
