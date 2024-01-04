#include <iostream>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std;
using namespace std :: chrono;

typedef unsigned long long ull;

void oddSum(ull start, ull end){
    
    ull sum = 0;
    
    for(ull i = start; i<end; i++){
        if(i % 2){
            sum += i;
        }
    }
    
    cout<<"odd sum = "<<sum<<endl;
}

void evenSum(ull start, ull end){
    
    ull sum = 0;
    
    for(ull i = start; i<end; i++){
        if(i % 2 == 0){
            sum += i;
        }
    }
    
    cout<<"even sum = "<<sum<<endl;
}

int main()
{
    ull end = 1900000000;
    ull start = 0;
    
    auto startTime = high_resolution_clock()::now();
    
    thread t1(oddSum, start, end); // starts thread1 after reading this line and comes beak to main
    thread t2(evenSum, start, end); //// starts thread2 after reading this line and comes beak to main
    
    // join the created therads with main thread
    t1.join(); // makes main thread wait till t1 finishes
    t2.join(); // makes main thread wait till t2 finishes
    
    auto stopTime = high_resolution_clock()::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    
    cout<<"time = "<<duration.count()/1000000<<endl;

    return 0;
}
