#pragma once

template <typename Forward, typename X>
Forward remove(Forward beg, Forward end, const X& x){
    Forward current = beg;
    while (beg != end)  
    {
        while (*beg == x && beg != end)
        {
            beg++;
        }
        if(beg != end){
            *current = *beg;
            ++current;
        }   
    }
    return current;
}

//STL implement
template <class ForwardIterator, class T>
  ForwardIterator remove (ForwardIterator first, ForwardIterator last, const T& val)
{
  ForwardIterator result = first;
  while (first!=last) {
    if (!(*first == val)) {
      if (result!=first)
        *result = *first;
      ++result;
    }
    ++first;
  }
  return result;
}