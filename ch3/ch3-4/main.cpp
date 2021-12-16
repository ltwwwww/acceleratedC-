#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    cout << "Please enter a series of words: ";
    string s;
    cin >> s;
    string::size_type max = s.size();
    string::size_type min = s.size();
    while (cin >> s)
    {
        if(s.size() > max) max = s.size();
        if(s.size() < min) min = s.size();
    }
    cout << "the longest is " << max << endl;
    cout << "the shortest is " << min << endl;
    
    return 0;
}