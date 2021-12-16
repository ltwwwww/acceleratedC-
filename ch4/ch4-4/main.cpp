#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int get_width(double n){
    return log10(n) + 1;
}

int main(int argc, char* argv[]){
    double max = 999.0;
    for(double i = 1.0; i <= max; ++i){
        cout << setw(get_width(max)) << i << " " << setw(get_width(max * max)) << i * i << endl;
    }

    return 0;
}