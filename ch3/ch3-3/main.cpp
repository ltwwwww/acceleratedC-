#include <string>
#include <iostream>
#include <map>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::map;

int main(){
    cout << "please enter a series of strings: ";
    map<string, int> a;
    string s;
    while(cin >> s){
        ++a[s];
    }
    for(map<string, int>::iterator i = a.begin(); i != a.end(); ++i){
        cout << i->first << " ";
        cout << i->second;
        cout << endl;
    }
    return 0;
}