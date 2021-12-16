#pragma once

template <typename In, typename Function>
In find_if(In beg, In end, Function func){
    while (beg != end)  
    {
        if(func(*beg)) return beg;
        ++beg;
    }
    return end;
}