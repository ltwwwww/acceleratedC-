#pragma once

template <typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename Bi>
void reverse(Bi beg, Bi end){
    // --end;
    while (beg != end)
    {
        --end;
        if(beg != end)
            swap(*beg++, *end);
            // to swap it directly we need to know the 
            // type of the element the iterator is pointing at
    }
}