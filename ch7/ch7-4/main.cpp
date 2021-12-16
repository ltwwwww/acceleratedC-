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
        cout << it->first << " occurs in line(s): ";
        vector<int>::const_iterator index_it = it->second.begin();
        // cout << (*index_it) << ", ";
        // ++index_it;
        int line_count = 0;
        while(index_it != it->second.end()){
            if(index_it != it->second.end() - 1)
                cout << (*index_it) << ", ";
            else cout << (*index_it);
            ++index_it;
            ++line_count;
            if(line_count % 10 == 0) cout << endl;
        }
        cout << endl;
    }
    return 0;
}