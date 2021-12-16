#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main(int argc, char* argv[]){
    vector<char> chs = {'e', 'z', 'S', 'b'};
    for(vector<char>::const_iterator it = chs.begin(); it != chs.end(); ++it){
        if(isupper(*it)) cout << (char)tolower(*it) << " ";
        else cout << (char)(*it) << " ";
    }
    cout << endl;
    for(vector<char>::const_iterator it = chs.begin(); it != chs.end(); ++it){
        if(islower(*it)) cout << (char)toupper(*it) << " ";
        else cout << (char)(*it) << " ";
    }    
    cout << endl;


    return 0;
}