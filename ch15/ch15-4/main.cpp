#include "pic.h"
#include <vector>
#include <string>

using namespace std;

int main(){
    // vector<string> str = {"I", "be", "because", "I", "think"}; 
    // Picture pic(str);
    // cout << pic << endl;
    // cout << hcat(frame(pic),hcat(str, str)) << endl;
    // cout << hcat(frame(pic), vact(pic, vact(pic, pic))) << endl;
    // cout << hcat(str,str) << endl;

    // vector<string> str = {"I", "be", "because", "I", "think"};
    // Picture p = str;
    // Picture q = frame(p);
    // Picture r = hcat(p,q);
    // Picture s = vact(q,r);
    // Picture t = frame(hcat(s,vact(r,q)));
    // cout << t << endl;

    // t.reframe('*', '*', '*');
    // cout << t << endl;

    vector<string> str1 = {"I", "be", "because", "I", "think"};
    vector<string> str2 = {"hello"};
    Picture p1 = str1;
    Picture p2 = str2;
    cout << hcat(p1,p2) <<endl;
    cout << hcat(p2,p1) <<endl;


    return 0;
}