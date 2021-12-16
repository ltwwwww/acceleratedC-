#pragma once

#include <algorithm>

template <typename Bi, typename Function>
Bi partition(Bi beg, Bi end, Function func){
    --end;
    while (beg != end)
    {
        while (func(beg))
        {
            ++beg;
        }
        while (!func(beg) && end >= beg)
        {
            --end;
        }
        std::swap(*beg, *end);
        if(end == beg){
            if(func(beg)) return ++beg;
            else return beg;
        }
    }
}
//stl:
template <class BidirectionalIterator, class UnaryPredicate>
  BidirectionalIterator partition (BidirectionalIterator first,
                                   BidirectionalIterator last, UnaryPredicate pred)
{
  while (first!=last) {
    while (pred(*first)) {
      ++first;
      if (first==last) return first;
    }
    do {
      --last;
      if (first==last) return first;
    } while (!pred(*last));
    swap (*first,*last);
    ++first;
  }
  return first;
}