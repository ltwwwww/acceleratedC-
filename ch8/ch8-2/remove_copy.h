#pragma once

template <typename In, typename Out, typename X>
Out remove_copy(In beg, In end, Out dst, const X& x){
    while (beg != end)
    {
        if(*beg != x) {
            *dst = *beg;
            dst++;
        }
        beg++;
    }
    return dst;
}