#include "frame.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;
int main(int argc, char* argv[]){
    vector<string> str = {"I", "bee", "because", "I", "think"};
    vector<string> frameStr = frame(str);
    vector<string> hcatStr = hcat(str, str);
    vector<string> vcatStr = vcat(str, str);

    
    for(vector<string>::size_type i = 0; i != frameStr.size(); ++i){
        cout << frameStr[i] << endl;
    }
    for(vector<string>::size_type i = 0; i != hcatStr.size(); ++i){
        cout << hcatStr[i] << endl;
    }
    for(vector<string>::size_type i = 0; i != vcatStr.size(); ++i){
        cout << vcatStr[i] << endl;
    }
    try{
        vector<string> cenStr = center(str);
        for(vector<string>::size_type i = 0; i != cenStr.size(); ++i){
            cout << cenStr[i] << endl;
        }
    }catch(domain_error e){
        cout << e.what() << endl;
    }

    return 0;
}