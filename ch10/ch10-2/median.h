#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>
using namespace std;

template <typename X, typename T>
X median(T beg, T end){
    if(beg == end)
        throw std::runtime_error("meidan of an empty vector!");
    vector<X> v;
    copy(beg, end, back_inserter(v));
    std::sort(v.begin(), v.end());
    typename vector<X>::size_type size = v.size();
    typename vector<X>::size_type mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}