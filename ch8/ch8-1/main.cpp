#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <ctime>
#include "grade.h"
#include "Student_info.h"
#include "analysis.h"

using std::cin;             using std::sort;
using std::cout;            using std::streamsize;
using std::domain_error;    using std::string;
using std::endl;            using std::vector;
using std::max;             using std::setw;
using std::setprecision;

int main(){
    vector<Student_info> did, didnt;
    Student_info record;
    string::size_type maxlen = 0;

    while(read(cin, record)){
        maxlen = max(maxlen, record.name.size());
        if( did_all_hw(record)) did.push_back(record);
        else didnt.push_back(record);
    }
    if(did.empty()){
        cout << "No student did all the homework" << endl;
        return 1;
    }
    if(didnt.empty()){
        cout << "Every student did all the homework" << endl;
        return 1;
    }

    // write_analysis(cout, "median", median_analysis, did, didnt);
    // write_analysis(cout, "average", average_analysis, did, didnt);
    // write_analysis(cout, "median of homework turn in", optimistic_median_analysis, did, didnt);

    write_analysis(cout, "median", aux_grade, did, didnt);
    write_analysis(cout, "average", average_grade, did, didnt);
    write_analysis(cout, "median of homework turn in", optimistic_median, did, didnt);
    // sort(students.begin(), students.end(), compare);
    // clock_t start = clock();
    // vector<Student_info> fails = extrace_fails(students);
    // clock_t elapsed = clock() - start;
    // cout << "elapsed: " << elapsed << endl; 
    // for (vector<Student_info>::size_type i = 0;
    //     i != students.size(); ++i){
    //         cout << students[i].name
    //          << string(maxlen + 1 - students[i].name.size(), ' ');
    //         // cout << std::left << setw(maxlen + 1) << students[i].name;
        
    //     try {
    //         double final_grade = grade(students[i]);
    //         streamsize prec = cout.precision();
    //         cout << setprecision(3) << final_grade << setprecision(prec);
    //     } catch(domain_error e){
    //         cout << e.what();
    //     }
    //     cout << endl;
    //     }
    
    // vector<Student_info> fail = extrace_fails(students);
    // cout << "pass : " << endl;
    // for (vector<Student_info>::const_iterator i = students.begin();
    //      i < students.end(); i++)
    // {
    //     cout << (*i).name << string(maxlen + 1 - (*i).name.size(), ' ');
    //     try{
    //         double final_grade = grade(*i);
    //         streamsize prec = cout.precision();
    //         cout << setprecision(3) << final_grade << setprecision(prec);
    //     }catch(domain_error e){
    //         cout << e.what();
    //     }
    //     cout << endl;
    // }

    // cout << "fail : " << endl;
    // for (vector<Student_info>::const_iterator i = fail.begin();
    //      i < fail.end(); i++)
    // {
    //     cout << (*i).name << string(maxlen + 1 - (*i).name.size(), ' ');
    //     try{
    //         double final_grade = grade(*i);
    //         streamsize prec = cout.precision();
    //         cout << setprecision(3) << final_grade << setprecision(prec);
    //     }catch(domain_error e){
    //         cout << e.what();
    //     }
    //     cout << endl;
    // }
    
    return 0;
}


