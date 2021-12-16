#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    cout << "Please enter your first name: ";
    string name;
    cin >> name;

    const string greeting = "Hello, " + name + "!";
    cout << "Please enter the number of blank you want to add: " ;
    int n;
    cin >> n;
    const string::size_type width = greeting.size() + n * 2 + 2;
    const int height = n * 2 + 3;

    for( int i = 0; i != height; ++i ){
        for( string::size_type j = 0; j != width; ++j ){
            if( i == 0 || i == height - 1 ){
                cout << '*';
            }else if( i == height / 2 ){
                if( j == 0 || j == width - 1 )
                    cout << '*';
                else if( j == n + 1){
                    cout << greeting;
                    j += greeting.size() - 1;
                }
                else
                    cout << ' ';
            }else{
                if( j == 0 || j == width - 1 )
                    cout << '*';
                else
                    cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}