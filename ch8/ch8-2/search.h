#pragma once

#include <algorithm>
template <typename In>
In search(In beg, In end, In b2, In e2){
    while (beg != end)
    {
        if(std::equal(b2, e2, beg)) return beg;
        beg++;
    }
    return end;
}

// stl implement:
template<class ForwardIterator1, class ForwardIterator2>
  ForwardIterator1 search ( ForwardIterator1 first1, ForwardIterator1 last1,
                            ForwardIterator2 first2, ForwardIterator2 last2)
{
  if (first2==last2) return first1;  // specified in C++11
  
  while (first1!=last1)
  {
    ForwardIterator1 it1 = first1;
    ForwardIterator2 it2 = first2;
    while (*it1==*it2) {    // or: while (pred(*it1,*it2)) for version 2
        ++it1; ++it2;
        if (it2==last2) return first1;
        if (it1==last1) return last1;
    }
    ++first1;
  }
  return last1;
}