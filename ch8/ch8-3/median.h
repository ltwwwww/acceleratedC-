#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>

template <typename T, typename In>
T median(In beg, In end){
    if(beg == end)
        throw std::runtime_error("meidan of an empty vector!");
    std::sort(beg, end);
    std::distance(beg, end);
    typename std::iterator_traits<In>::difference_type  mid = (end - beg) / 2;
    std::advance(beg, mid);
    return (end - beg) % 2 == 0 ? (*beg + *(beg - 1)) / 2 : *beg;
}

template <typename T>
T median_copy(std::vector<T> vec){
    typedef typename std::vector<T>::size_type vec_sz;
    vec_sz size = vec.size();
    if(size == 0)
        throw std::runtime_error("meidan of an empty vector!");
    std::sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}