#pragma once 

template <typename In, typename Out>
Out copy(In beg, In end, Out des){
    while (beg != end)      
    {
        *des = *beg;
        ++des; ++beg;
    }
    return des;
}