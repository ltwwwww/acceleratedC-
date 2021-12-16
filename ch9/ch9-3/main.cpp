#include "student_info.h"
#include <iostream>
#include <stdexcept>
using namespace std;
int main(){
    Student_info s;
    try
    {
        cout << s.grade() << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}