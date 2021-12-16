#include "equal.h"
#include <iostream>
#include <vector>

int main(){
    std::vector<int> a = {1,2,3,4};
    std::vector<int> b = {1,3,3};
    std::cout << equal(a.begin(), a.end(), b.begin()) << std::endl;
    return 0;
}