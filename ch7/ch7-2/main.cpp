#include "read.h"
#include "student_info.h"
#include "grade.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>
#include <map>
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
using std::map;

void classify(const Student_info& stu, map<string, vector<string> >& ret){
    try
    {
        double final_grade = grade(stu);
        if(final_grade >= 90) ret["A"].push_back(stu.name);
        else if(final_grade >= 80) ret["B"].push_back(stu.name);
        else if(final_grade >= 70) ret["C"].push_back(stu.name);
        else if(final_grade >= 60) ret["D"].push_back(stu.name);
        else ret["F"].push_back(stu.name);
    }
    catch(const std::exception& e)
    {
        ret["other"].push_back(stu.name);
    }
    
}

int main(){
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    while (read(cin, record))
    {
        students.push_back(record);
        maxlen = max(maxlen, record.name.size());
    }
    sort(students.begin(), students.end(), compare);
    map<string, vector<string> > types;
    for(vector<Student_info>::size_type i = 0; i != students.size(); ++i){
        cout << students[i].name << string(maxlen - students[i].name.size() + 1, ' ');
        try{
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        }catch(domain_error e){
            cout << e.what();
        }
        cout << endl;

        classify(students[i], types);
    }
    for(map<string, vector<string> >::const_iterator it = types.begin();
        it != types.end(); ++it){
        cout << it->second.size() << " student(s) get(s) " << it->first << endl;
    }

    
    
    return 0;
}
