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
    for(map<string, vector<int> >::const_iterator it = result.begin(); it != result.end(); ++it)
    {
        cout << it->first << " occurs in : ";
        vector<int>::const_iterator index_it = it->second.begin();
        cout << (*index_it);
        ++index_it;
        while(index_it != it->second.end()){
            cout << ", " << (*index_it);
            ++index_it;
        }
        cout << endl;
    }
    return 0;
}