//
//  ThreadLock.h
//  flyfight_branch
//
//  Created by snowcold on 29/6/14.
//
//

#ifndef __flyfight_branch__ThreadLock__
#define __flyfight_branch__ThreadLock__

#include <iostream>
class ThreadLockManager
{
private:
    
    pthread_mutex_t* mLock;
    
public:
    
    ThreadLockManager(pthread_mutex_t* mut) : mLock(mut)
    {
        pthread_mutex_init(mLock, NULL);
    }
    
    ~ThreadLockManager()
    {
        pthread_mutex_destroy(mLock);
        mLock = NULL;
    }
};

class ThreadLock
{
    pthread_mutex_t* mLock;
    
public:
    
    ThreadLock(pthread_mutex_t* mut) : mLock(mut)
    {
        pthread_mutex_lock(mLock);
    }
    
    ~ThreadLock()
    {
        pthread_mutex_unlock(mLock);
    }
    
};

#define ThreadLock(mutex) ThreadLock __locker__(mutex)

#endif /* defined(__flyfight_branch__ThreadLock__) */
