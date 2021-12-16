#include "student_info.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(){
    Core* p1 = new Core(cin);
    Core* p2 = new Grad(cin);
    Core s1;
    Grad s2(cin);
    

    p1->grade(); //Core::grade
    p1->name(); //Core::name
    cout << endl;
    p2->grade(); //Grad::grade Core::grade
    p2->name(); //Core::name
    cout << endl;
    s2.name(); //Core::name
    s2.grade(); //Grad::grade Core::grade

    cout << p1->grade() << endl;
    cout << p2->grade() << endl;
    cout << s2.grade() << endl;
    cout << p1->valid() << endl;
    cout << p2->valid() << endl;
    cout << s1.valid() << endl;
    cout << s2.valid() << endl;
    return 0;
}