#include "vec.h"
#include <iostream>
#include <ctime>
using namespace std;
int main(){
    Vec<int> a;
    Vec<int> b;

    clock_t start1 = clock();
    for(int i = 0 ; i < 1000 ; ++i){
        a.push_back(1);
    }
    cout << clock() - start1 << endl;
    
    clock_t start2 = clock();
    for(int i = 0 ; i < 1000 ; ++i){
        b.push_back(1, false);
    }
    cout << clock() - start2 << endl;
    // for(Vec<int>::const_iterator it = a.begin(); it != a.end(); ++it){
    //     cout << *it << endl;
    // }
    cout << a.size() << endl;
    cout << b.size() << endl;
    return 0;
}