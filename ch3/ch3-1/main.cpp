#include <iostream>
#include <ios>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::endl;
// using std::precision;
using std::setprecision;
using std::string;
using std::streamsize;

int main(){
    cout << "Pleast enter your first name : ";
    string name;
    cin >> name;
    cout << "Hello, " + name + "!" << endl;

    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    cout << "Enter all your homework grades"
            "followed by end-of-file: ";

    int count = 0;
    double sum = 0;
    double hw;
    while(cin >> hw){
        sum += hw;
        ++count;
    }

    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
        << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
        << setprecision(prec) << endl;

    return 0;
}
