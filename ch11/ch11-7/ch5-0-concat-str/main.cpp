#include "frame.h"
#include <iostream>
#include <vector>
#include <string>
#include "vec.h"
using namespace std;
int main(int argc, char* argv[]){
    Vec<string> str;
    str.push_back("I");
    str.push_back("be");
    str.push_back("because");
    str.push_back("I");
    str.push_back("think");
    Vec<string> frameStr = frame(str);
    Vec<string> hcatStr = hcat(str, str);
    Vec<string> vcatStr = vcat(str, str);
    // Vec<string> v;
    // Vec<string> frameV = frame(v);
    // for(Vec<string>::size_type i = 0; i != frameV.size(); ++i){
    //     cout << frameV[i] << endl;
    // }
    for(Vec<string>::size_type i = 0; i != hcatStr.size(); ++i){
        cout << hcatStr[i] << endl;
    }
    for(Vec<string>::size_type i = 0; i != vcatStr.size(); ++i){
        cout << vcatStr[i] << endl;
    }
    return 0;
}