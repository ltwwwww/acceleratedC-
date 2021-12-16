#include "permuted-index.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include "split.h"

using namespace std;

vector<string> read_line(istream& is){
    vector<string> lines;
    string line;
    while(getline(is, line)){
        lines.push_back(line);
    }
    return lines;
}

vector<Rotation> rotate_line(string s){
    vector<Rotation> ret;
    vector<string> words = split(s);

    for(vector<string>::size_type i = 0; i < words.size(); ++i){
        Rotation rot = {words.size() - i, words};
        ret.push_back(rot);
        rotate(words.begin(), words.begin() + 1, words.end());
    }
    return ret;
}

vector<Rotation> rotate_lines(vector<string> lines){
    vector<Rotation> ret;
    for(vector<string>::size_type i = 0; i != lines.size(); ++i){
        vector<Rotation> temp = rotate_line(lines[i]);
        ret.insert(ret.end(), temp.begin(), temp.end());
    }
    return ret;
}

void permuted(const vector<Rotation>& vec){
    vector<string> first_parts;
    vector<string> second_parts;
    string::size_type max_len_of_first = 0;

    for(vector<Rotation>::size_type k = 0; k != vec.size(); ++k){
        string first;
        for(vector<string>::size_type j = vec[k].first; j != vec[k].words.size(); ++j){
            
            first += (vec[k].words[j] + " ");
            
        }
        first_parts.push_back(first);
        if(first.size() > max_len_of_first) max_len_of_first = first.size();
        string second;
        for(vector<string>::size_type i = 0; i != vec[k].first; ++i){
            second += (vec[k].words[i] + " ");
            
        }
        second_parts.push_back(second);
    }

    for(vector<string>::size_type i = 0; i != first_parts.size(); ++i){
        cout << setw(max_len_of_first);
        cout << first_parts[i];
        cout << '\t';
        cout << second_parts[i];
        cout << endl;
    }
}

bool compare(const Rotation& a, const Rotation& b){
    return a.words[0] < b.words[0];
}

// vector<string> cycle(const string& s){
//     vector<string> ret;
//     vector<string> words = split(s);
//     for(vector<string>::size_type i = 0; i != words.size(); ++i){
//         string line = words[i];
//         for(vector<string>::size_type j = i + 1; j != words.size(); ++j){
//             line += (" " + words[j]);
//         }
//         for(vector<string>::size_type k = 0; k != i; ++k){
//             line += (" ") + words[k];
//         }
//         ret.push_back(line);
//     }
//     return ret;
// }

// int main(){
//     string a = "to be or not to be";
//     vector<string> res = cycle(a);
//     for(vector<string>::size_type i = 0; i != res.size(); ++i){
//         cout << res[i] << endl;
//     }
//     return 0;
// }