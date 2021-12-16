#include "str.h"
#include "frame.h"
#include <vector>
#include <iostream>
#include "split.h"
#include <string>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    vector<Str> str = { "I", "be", "because", "I", "think"};
    for(vector<Str>::size_type i = 0; i < str.size(); ++i){
        cout << str[i] << endl;
    }
    Str ss(5, '*');
    cout << ss << endl;
    // ss + ss;
    double num = 9;
    num + num;

    string a("ssss");
    a + a;
    // vector<Str> fstr = frame(str);
    // for(vector<Str>::size_type i = 0; i < fstr.size(); ++i){
    //     cout << fstr[i] << endl;
    // }

    // vector<Str> hstr = hcat(str, str);
    // for(vector<Str>::size_type i = 0; i < hstr.size(); ++i){
    //     cout << hstr[i] << endl;
    // }

    // vector<Str> vstr = vcat(str, str);
    // for(vector<Str>::size_type i = 0; i < vstr.size(); ++i){
    //     cout << vstr[i] << endl;
    // }

    // Str sentence = "asfg asfgsdfg sdfgsd";
    // vector<Str> words =  split(sentence);
    // for(vector<Str>::size_type i = 0; i < words.size(); ++i){
    //     cout << words[i] << endl;
    // }

    

    return 0;
}