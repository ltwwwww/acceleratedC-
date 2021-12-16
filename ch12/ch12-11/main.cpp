#include "str.h"
#include "frame.h"
#include <vector>
#include <iostream>
#include "split.h"
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main(){
    vector<Str> str = { "I", "be", "because", "I", "think"};
    for(vector<Str>::size_type i = 0; i < str.size(); ++i){
        cout << str[i] << endl;
    }

    vector<Str> fstr = frame(str);
    for(vector<Str>::size_type i = 0; i < fstr.size(); ++i){
        cout << fstr[i] << endl;
    }

    vector<Str> hstr = hcat(str, str);
    for(vector<Str>::size_type i = 0; i < hstr.size(); ++i){
        cout << hstr[i] << endl;
    }

    vector<Str> vstr = vcat(str, str);
    for(vector<Str>::size_type i = 0; i < vstr.size(); ++i){
        cout << vstr[i] << endl;
    }

    Str sentence;
    getline(cin, sentence);
    vector<Str> words =  split(sentence);
    for(vector<Str>::size_type i = 0; i < words.size(); ++i){
        cout << words[i] << endl;
    }
    cout << words[0].c_str() << endl; 

    return 0;
}