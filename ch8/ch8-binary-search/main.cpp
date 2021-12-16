#include "binary.h"
#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> sqe = {1,2,3,4,5,6,7,8};
    cout << binary_search(sqe.begin(), sqe.end(), 2) << endl;
    return 0;
}