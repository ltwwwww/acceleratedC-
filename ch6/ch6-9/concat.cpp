#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

string target = "";

void cat(const string& s){
    target += s;
}

int main(int argc, char* argv[]){
    vector<string> strs = {"aaa", "bbb", "ccc"};
    for_each(strs.begin(), strs.end(), cat);
    cout << target << endl;
    return 0;
}