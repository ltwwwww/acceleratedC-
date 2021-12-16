#include <algorithm>
#include <iostream>
#include <string>
#include "read.h"
#include "student_info.h"
using namespace std;
int main(int argc, char* argv[]){
    cout << "Please input" << endl;
    Student_info s;
    cin >> s.name >> s.midterm >> s.final;
    string::size_type maxlen = 0;
    maxlen = max(maxlen, s.name.size());
    return 0;
}