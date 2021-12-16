#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    vector<string> names;
    vector<double> grades;
    cout << "Pleast enter the chart: " << endl;
    string name;
    while (cin >> name)
    {
        names.push_back(name);
        double midterm, final;
        cin >> midterm >> final;
        vector<double> homework;
        double hw;
        for(int i = 0; i < 3; ++i){
            cin >> hw;
            homework.push_back(hw);
        }
        sort(homework.begin(), homework.end());
        vector<double>::size_type size = homework.size();
        vector<double>::size_type mid = size / 2;
        double median;
        median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];
        double grade = 0.4 * final + 0.2 * midterm + 0.4 * median;
        grades.push_back(grade);
    }
    for(vector<string>::size_type i = 0; i < names.size(); ++i){
        cout << names[i] << " " << grades[i] << endl;
    }
    return 0;
}