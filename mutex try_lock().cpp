/*
Few points to remember about the try_lock is as follows:
0. try_lock() Tries to lock the mutex. Returns immediately. On successful lock acquisition returns true otherwise returns false.
1. If try_lock() is not able to lock mutex, then that thread doesn't get blocked that's why it is called non-blocking.
2. If try_lock is called two times by the same thread which owns the mutex, the behaviour is undefined.
   It is a dead lock situation with undefined behaviour. (if you want to be able to lock the same mutex by same thread more than one time the go for recursive_mutex)



1. In try_lock(), the order of execution is somewhat undefined. We may get different values.
2. This is because, when one thread is try_lock(), the other thread might have already locked it. Now. this trying thread will not wait to acquire lock and continue exection.

*/

/*
1. In below program, since we are using try_lock(), the final amount may not be 2000000, but if we use simple lock() on mutex, the output will be always 2000000.
*/



#include <iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include<mutex>

using namespace std;
using namespace std :: chrono;

int amount = 0;
mutex m;

void increaeThread(){
    
    for(int i=0; i<100000; i++){
        
        if(m.try_lock()){
            
            ++amount;
            m.unlock();
        }
    }
}


int main()
{
    thread t1(increaeThread);
    thread t2(increaeThread);
    
    t1.join();
    t2.join();
    
    cout<<"Amount = "<<amount<<endl;
    return 0;
}
