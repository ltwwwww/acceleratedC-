#include <fstream>
#include <string>
using namespace std;

int main(){
    string file = "in.txt";
    ifstream infile(file);
    ofstream outfile("out.txt");
    string s;
    while (getline(infile, s))
    {
        outfile << s << endl;
    }
    return 0;
}