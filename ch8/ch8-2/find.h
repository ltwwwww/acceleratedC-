#pragma once

template <typename In, typename X>
In find(In beg, In end, const X& x){
    while (beg != end)
    {
        if(*beg == x) return beg;
        ++beg;
    }
    return end;
}