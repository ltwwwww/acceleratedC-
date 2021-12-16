#include <cstring>
#include <iterator>
#include <iostream>

using namespace std;

char* duplicate(const char* vec){
    
    const size_t length = strlen(vec) + 1;
    char* ret = new char[length];
    copy(vec, vec + length, ret);
    return ret;
}

int main(){
    char a[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char* b = duplicate(a);
    cout << b << endl;
    char* argv[] = {"sss", "bbb"};
    cout << argv[1] << endl;
    return 0;
}

