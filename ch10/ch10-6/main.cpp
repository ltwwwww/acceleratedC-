#include "string_list.h"
#include <string>
#include <iostream>
#include "split.h"

using namespace std;

int main(int argc, char* argv[]){
    string sentence = "sasd sfa agadg asgf";
    String_list a = split(sentence);
    for(String_list::iterator i = a.begin(); i != a.end(); ++i){
        cout << *i << endl;
    }
    return 0;
}