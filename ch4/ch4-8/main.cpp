#include <vector>
#include <iostream>

using namespace std;

vector<double> f(){
    vector<double> a = {1,2,3,4,5};
    return a;
}

int main(int argc, char* argv[]){
    double d = f()[2];
    cout << d << endl;
    return 0;
}