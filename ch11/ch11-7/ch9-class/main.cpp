#include "student_info.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>
#include <algorithm>
#include "vec.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::domain_error;
using std::streamsize;
using std::setprecision;
using std::sort;


int main(){
    Vec<Student_info> students;
    Student_info record;
    typedef string::size_type string_sz;
    string_sz maxlen = 0;

    while(record.read(cin)){
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }
    sort(students.begin(), students.end(), compare);

    cout << endl;
    typedef Vec<Student_info>::const_iterator iterator;
    for(iterator it = students.begin(); it != students.end(); ++it){
        cout << it->name() << string(maxlen - it->name().size() + 1 , ' ');

        try{
            streamsize prec = cout.precision();
            cout << setprecision(5) << it->grade() << setprecision(prec) << endl;
        }catch(domain_error e){
            cout << e.what() << endl;
        }
    }

    return 0;
}