#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main(int argc, char* argv[]){
    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), back_inserter(v));
    return 0;
}