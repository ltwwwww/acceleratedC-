#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "permuted-index.h"

using namespace std;

int main(int argc, char* argv[]){
    cout << "Please enter sentences: " << endl;
    vector<string> sentences = read_line(cin);
    vector<Rotation> rotated = rotate_lines(sentences);
    sort(rotated.begin(), rotated.end(), compare);
    permuted(rotated);
    return 0;
}
