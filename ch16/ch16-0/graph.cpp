#include "graph.h"
#include <vector>
#include <string>
using namespace std;
Picture graph(const Vec<Student_info>& students){
    Picture names;
    Picture grades;

    for(Vec<Student_info>::const_iterator it = students.begin(); it != students.end(); ++it){
        names = vact(names, vector<string>(1, it->name()));
        grades = vact(grades, vector<string>(1, string( it->grade() / 5, '=')));
    }
    return hcat(names, grades);
}
