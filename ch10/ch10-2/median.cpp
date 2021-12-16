// #include <vector>
// #include <stdexcept>
// #include "median.h"
// using namespace std;


// template <typename T>
// T median(vector<T> vec){
//     typedef typename vector<T>::size_type vec_sz;
//     vec_sz size = vec.size();
//     if(size == 0)
//         throw std::runtime_error("meidan of an empty vector!");
//     sort(vec.begin(), vec.end());
//     vec_sz mid = size / 2;
//     return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
// }