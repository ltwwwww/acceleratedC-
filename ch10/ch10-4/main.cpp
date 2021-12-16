#include "string_list.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    String_list a;
    a.push_back("aaa");
    a.push_back("bbb");
    a.push_back("vvv");

    for(String_list::iterator i = a.begin(); i != a.end(); ++i){
        cout << *i << endl;
    }
    for(String_list::iterator i = a.end()-1; i >= a.begin(); --i){
        cout << *i << endl;
    }


    return 0;
}