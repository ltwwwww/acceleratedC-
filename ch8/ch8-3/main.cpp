#include "median.h"
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

int main(){
    vector<int> a = {1,4,5,3,4,5,6,6,5,4,3,3,4,3,2};

    clock_t start = clock();
    for (int i = 0; i < 100; i++)
    {
        median<int, vector<int>::iterator>(a.begin(), a.end());
    }
    cout << "jiange: " << clock() - start << endl;
    
    clock_t start2 = clock();
    for (int i = 0; i < 100; i++)
    {
        median_copy<int>(a);
    }
    cout << "jiange: " << clock() - start2 << endl;


    return 0;
}