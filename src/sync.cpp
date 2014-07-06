#include "sync.hpp"

Semaphore::Semaphore(int value)
{
    if (sem_init(&sem, 0, value) != 0)
    {
        throw "Semaphore initialization failed!";
    }
}

Semaphore::~Semaphore()
{
    sem_destroy(&sem);
}

void Semaphore::wait()
{
    if (sem_wait(&sem) != 0)
    {
        throw "Semaphore wait() failed!";
    }
}

void Semaphore::post()
{
    if (sem_post(&sem) != 0)
    {
        throw "Semaphore post() failed!";
    }
}

void Condition::wait()
{
    sem.wait();
}

bool Condition::signal()
{
    if (waiting)
    {
        --waiting;
        sem.post();
        return true;
    }
    else
    {
        return false;
    }
}

void Monitor::enter()
{
    mutex.wait();
}

void Monitor::leave()
{
    mutex.post();
}

void Monitor::wait(Condition &condVar)
{
    ++condVar.waiting;
    leave();
    condVar.wait();
}

void Monitor::signal(Condition &condVar)
{
    if(condVar.signal())
    {
        enter();
    }
}
