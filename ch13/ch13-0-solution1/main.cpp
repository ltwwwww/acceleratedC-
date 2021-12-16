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
    vector<Core*> students;
    Core* record;
    typedef string::size_type string_sz;
    string_sz maxlen = 0;
    char c;
    while(cin >> c){
        if(c == 'U')
            record = new Core;
        else
            record = new Grad;
        record->read(cin);
        maxlen = max(maxlen, record->name().size());
        students.push_back(record);
    }
    sort(students.begin(), students.end(), compare_ptrs);

    // cout << endl;
    typedef vector<Core*>::const_iterator iterator;
    for(iterator it = students.begin(); it != students.end(); ++it){
        cout << (*it)->name() << string(maxlen - (*it)->name().size() + 1 , ' ');

        try{
            streamsize prec = cout.precision();
            cout << setprecision(5) << (*it)->grade() << setprecision(prec) << endl;
        }catch(domain_error e){
            cout << e.what() << endl;
        }
        delete (*it);
    }
    return 0;
}