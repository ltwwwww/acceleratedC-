#include <iostream>
#include <string>
#include <vector>
#include "split.h"

using namespace std;

int main(){
    vector<string> vec;
    string s = "asdf asfga dfgsd afa";
    split(s.begin(), s.end(), back_inserter(vec));
    for(vector<string>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << endl;
    return 0;
}