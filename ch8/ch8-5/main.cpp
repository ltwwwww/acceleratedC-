#include <iostream>
#include "gen.h"
#include <ctime>
#include <iterator>

using namespace std;

int main(int argc, char* argv[]){
    srand((unsigned)time(NULL));
    GRAMMER g = read_grammer(cin);
    vector<string> sentence;
    aux_gen(g, back_inserter(sentence));
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