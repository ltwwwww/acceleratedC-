#include <cstdlib>
#include <stdexcept>
#include <iostream>
using namespace std;

#define MY_RAND_MAX  32767

int nrand(int n){
    
    if(n <= 0){
        throw logic_error("size of n if out of range !");
    } 
    int r;
    if(n <= MY_RAND_MAX){
        const int bucket_size = MY_RAND_MAX / n;
        do{
            int bucket = rand() / bucket_size;
            r = bucket;
        }while ( r >= n);
    }else{
        const int bucket_size = n / MY_RAND_MAX;

        do{
            int bucket = nrand(MY_RAND_MAX);
            int remainder = nrand(bucket_size);
            r = bucket_size * bucket + remainder;
        }while (r >= n);
    }
    return r;
}