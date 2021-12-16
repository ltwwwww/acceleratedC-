#include <vector>
#include <algorithm>
#include "student_info.h"
using std::vector;
using std::stable_partition;

vector<Student_info> classify(vector<Student_info>& vs,
                        bool certion(const Student_info&)){
    
    vector<Student_info>::iterator it = stable_partition(vs.begin(), vs.end(), certion);
    vector<Student_info> fails(it, vs.end());
    vs.erase(it, vs.end());
    return fails;
    }