#include <iostream>
#include "gen.h"
#include <ctime>

using namespace std;

int main(int argc, char* argv[]){
    srand((unsigned)time(NULL));
    GRAMMER g = read_grammer(cin);
    vector<string> sentence = gen_sen(g);
    vector<string>::const_iterator it = sentence.begin();
    if(!sentence.empty()){
        cout << *it;
        ++it;
    }

    while (it != sentence.end())
    {
        cout << " " << *it;
        ++it;
    }
    cout << "." << endl;
    return 0;
}