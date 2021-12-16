#include "vec.h"
#include <iostream>
using namespace std;
int main(){
    Vec<int> a(9, 1);
    a.push_back(23);
    a.erease(a.begin());
    a.erease(a.begin());
    a.clear();
    
    for(Vec<int>::const_iterator it = a.begin(); it != a.end(); ++it){
        cout << *it << endl;
    }
    cout << a.size() << endl;
    return 0;
}