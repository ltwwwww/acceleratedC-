#pragma once

template <typename In, typename Out, typename Function>
Out remove_copy_if(In beg, In end, Out dst, Function func){
    while (beg != end)
    {
        if(!func(*beg)) {
            *dst = *beg;
            dst++;
        }
        beg++;
    }
    return dst;
}