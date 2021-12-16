#include <cstdlib>
#include <stdexcept>
#include <ctime>
#include <iostream>
#include "nrand.h"
using namespace std;


int main(int argc, char* argv[]){
    sranddev();
    // srand((unsigned)time(NULL));
    for(int i = 0; i < 10; ++i)
        cout << nrand(100000000) << endl;
    return 0;
}
