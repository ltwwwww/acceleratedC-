#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    cout << "Please enter two numbers : ";
    int a, b;
    cin >> a >> b;
    if(a > b)
        cout << "the bigger is " << a << endl;
    else if(b > a)
        cout << "the bigger is " << b << endl;
    else
        cout << "these two numbers is equal" << endl;

    return 0;
}