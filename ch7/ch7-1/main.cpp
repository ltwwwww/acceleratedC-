#include "split.h"
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "xref.h"
using namespace std;

int main(){
    string s;
    vector<string> lines;
    while (getline(cin, s))
    {
        lines.push_back(s);
    }
    map<string, vector<int> > result = xref(lines);
    map<int, vector<string> > times;
    for(map<string, vector<int> >::const_iterator it = result.begin(); it != result.end(); ++it){
        times[(it->second).size()].push_back(it->first);
    }
    for(map<int, vector<string> >::const_iterator it = times.begin();
        it != times.end(); ++it){
        cout << "words occur " << it->first << " times : ";
        vector<string>::const_iterator id = it->second.begin();
        if(id != it->second.end()) cout << *id;
        ++id;
        while (id != it->second.end())
        {
            cout << " " << *id;
            ++id;
        }
        cout << endl;
    }
    // for(map<string, vector<int> >::const_iterator it = result.begin(); it != result.end(); ++it)
    // {
    //     cout << it->first << " occurs in : ";
    //     vector<int>::const_iterator index_it = it->second.begin();
    //     cout << (*index_it);
    //     ++index_it;
    //     while(index_it != it->second.end()){
    //         cout << ", " << (*index_it);
    //         ++index_it;
    //     }
    //     cout << endl;
    // }
    return 0;
}