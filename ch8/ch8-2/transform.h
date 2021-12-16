#pragma once

template <typename In, typename Out, typename Function>
Out transform(In beg, In end, Out dst, Function func){
    while (beg != end)
    {
        *dst = func(*beg);
        ++dst; ++beg;
    }
    return dst;
}