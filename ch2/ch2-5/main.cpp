#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    const int a = 5, b = 4;
    cout << "rectangle : "  << endl;
    for(int i = 0; i != b; ++i){
        cout << string(a, '*') << endl;
    }
    cout << endl;
    cout << "square : " << endl;
    for(int i = 0; i != a; ++i){
        cout << string(a, '*') << endl;
    }    
    cout << endl;
    cout << "triangle : " << endl;
    for(int i = 0; i != a; ++i){
        cout << string( i + 1, '*') << endl;
    }

    return 0;
}