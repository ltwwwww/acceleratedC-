#include "pic.h"



using namespace std;

int main(){
    // vector<string> str = {"I", "be", "because", "I", "think"}; 
    // Picture pic(str);
    // cout << pic << endl;
    // cout << hcat(frame(pic),hcat(str, str)) << endl;
    // cout << hcat(frame(pic), vact(pic, vact(pic, pic))) << endl;
    // cout << hcat(str,str) << endl;
    Vec<Str> str;
    str.push_back("I");
    str.push_back("be");
    str.push_back("because");
    str.push_back("I");
    str.push_back("think");   
    Picture p = str;
    Picture q = frame(p);
    Picture r = hcat(p,q);
    Picture s = vact(q,r);
    cout << frame(hcat(s,vact(r,q))) << endl;
    return 0;
}