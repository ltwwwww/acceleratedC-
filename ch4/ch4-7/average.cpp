#include <vector>
#include <iostream>
// #include <>
using namespace std;

double average(const vector<double>& vec){
    double sum = 0.0;
    for(vector<double>::size_type i = 0; i != vec.size(); ++i){
        sum += vec[i];
    }
    return sum / vec.size();
}


int main(int argc, char* argv[]){
    vector<double> num = {2.1, 2.0, 2.0, 2.0};
    cout << "average : " << average(num) << endl;
    return 0;
}