#include "student_info.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;
using std::sort;
using std::domain_error;
using std::streamsize;
using std::setprecision;

int main(){
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    while (record.read(cin))
    {
        students.push_back(record);
        maxlen = max(maxlen, record.name().size());
    }
    sort(students.begin(), students.end(), compare);

    for(vector<Student_info>::size_type i = 0; i != students.size(); ++i){
        cout << students[i].name() << string(maxlen - students[i].name().size() + 1, ' ');
        try{
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        }catch(domain_error e){
            cout << e.what();
        }
        cout << endl;
    }
    
    
    return 0;
}
