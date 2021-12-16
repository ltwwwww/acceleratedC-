#include "handle.h"
#include "pic.h"
#include <iostream>
#include "vec.h"
#include "graph.h"
using namespace std;

int main(int argc, char* argv[]){
    Vec<Student_info> students;
    Student_info record;
    while(record.read(cin)){
        students.push_back(record);
    }
    sort(students.begin(), students.end(), Student_info::compare);
    cout << frame(graph(students)) << endl;
    return 0;
}