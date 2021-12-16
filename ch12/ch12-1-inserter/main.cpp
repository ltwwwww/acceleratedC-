#include "str.h"
#include <iostream>
#include <string>

using namespace std;
int main(){
    Str line = "AAAAAAAA";
    Str line2 = "BBB";
    cout << line << endl;
    line.insert(line.begin(), line2.begin(), line2.end());
    cout << line << endl;
    Str line3 = string(5, 's');
    cout << line3 << endl;
    return 0;
}