//Mutex: Mutual Exclusion

/*RACE CONDITION:
0. Race condition is a situation where two or more threads/process happens to change a common data at the same time.
1. If there is a race condition then we have to protect it and the protected section is  called critical section/region.

MUTEX:
0. Mutex is used to avoid race condition.
1. We use lock() , unlock() on mutex to avoid race condition.*/


#include <iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include<mutex>

using namespace std;
using namespace std :: chrono;

int amount = 0;
mutex m;

void incAmount(){
    
    m.lock();
    ++amount;
    m.unlock();
}


int main()
{
    thread t1(incAmount);
    thread t2(incAmount);
    
    t1.join();
    t2.join();
    
    cout<<"Amount = "<<amount<<endl;
    return 0;
}
