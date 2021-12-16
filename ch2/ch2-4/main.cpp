#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){
    cout << "Please enter your name: ";
    string name;
    cin >> name;

    const string greeting = "hello, " + name + "!";
    const int pad = 2;
    int rows = pad * 2 + 3;
    string::size_type cols = pad * 2 + greeting.size() + 2;
    const string spaces = string(pad * 2 + greeting.size(), ' ');
    
    for(int i = 0; i != rows; ++i){
        string::size_type j = 0;
        while(j != cols){
            if(i == pad + 1 && j == pad + 1){
                cout << greeting;
                j += greeting.size();
            }else{
                if(i == rows - 1 || i == 0 || j == 0 || j == cols - 1){
                    cout << '*';
                    ++j;
                }
                else if( i == pad + 1 ){
                    cout << ' ';
                    ++j;
                }else{
                    cout << spaces;
                    j += spaces.size();
                }
            }
        }
        cout << endl;
    }
    return 0;
}