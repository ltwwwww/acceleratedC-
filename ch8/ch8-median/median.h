#include <vector>
#include <stdexcept>
#include <algorithm>
template <typename T> T median(std::vector<T>);

template <typename T>
T median(std::vector<T> vec){
    typedef typename std::vector<T>::size_type vec_sz;
    vec_sz size = vec.size();
    if(size == 0)
        throw std::runtime_error("meidan of an empty vector!");
    std::sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}