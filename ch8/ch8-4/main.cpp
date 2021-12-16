#include "reverse.h"
#include <vector>
#include <iostream>

int main(){
    std::vector<int> a = {1,2,3,4};
    reverse(a.begin(), a.end());
    std::cout << a[0] << " " << a[1] << " "<< a[2]<< " " << a[3] << std::endl;
    return 0;
}