#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]){
    cout << "Please enter a series of words: " << endl;
    string s;
    vector<string> vecStr;
    while(cin >> s){
        vecStr.push_back(s);
    }
    sort(vecStr.begin(), vecStr.end());
    int count = 1;
    string current = vecStr[0];
    for(vector<string>::size_type i = 1; i != vecStr.size(); ++i){
        if(current == vecStr[i]){
            ++count;
        }else{
            cout << current  << " appears " << count  << " times" << endl;
            count = 1;
            current = vecStr[i];
        }
        if(i == vecStr.size() - 1){
            cout << current  << " appears " << count  << " times" << endl;
        }
    }
    return 0;
}