#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>
#include <algorithm>
#include "handle.h"

using namespace std;

int main(){
    // vector<Student_info> students;
    // Student_info record;
    // typedef string::size_type string_sz;
    // string_sz maxlen = 0;
    // while(record.read(cin)){
    //     maxlen = max(maxlen, record.name().size());
    //     students.push_back(record);
    // }
    // sort(students.begin(), students.end(), Student_info::compare);

    // // cout << endl;
    // typedef vector<Student_info>::const_iterator iterator;
    // for(iterator it = students.begin(); it != students.end(); ++it){
    //     cout << (it)->name() << string(maxlen - (it)->name().size() + 1 , ' ');

    //     try{
    //         streamsize prec = cout.precision();
    //         cout << setprecision(5) << (it)->grade() << setprecision(prec) << endl;
    //     }catch(domain_error e){
    //         cout << e.what() << endl;
    //     }
    // }
    Student_info s1;
    s1.read(cin);
    Student_info s2 = s1;
    cout << s1.grade() << endl;
    cout << s2.grade() << endl;

    return 0;
}