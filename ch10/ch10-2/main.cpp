#include "median.h"
#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> a = {1,4,5,3,2,3,4,5,6,7,8,9};
    int b[] = {1,4,5,3,2,3,4,5,6,7,8,9};
    cout << median<int>(a.begin(), a.end()) << endl;
    
    cout << median<int>(b, b + 12) << endl;
    cout << endl;
    for (int i = 0; i < 12; ++i)
    cout << a[i] << endl;
    for (int i = 0; i < 10; ++i)
    cout << b[i] << endl;
    return 0;
}