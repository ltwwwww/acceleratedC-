#include "student_info.h"
#include <iostream>
#include <stdexcept>
using namespace std;
int main(){
    Student_info s;
    if(s.valid())
        cout << s.grade() << endl;
    return 0;
}