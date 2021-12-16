#pragma once

template <typename In, typename X>
X accumulate(In beg, In end, X& x){
    while (beg != end)
    {
        x += *beg++;
    }
    return x;
}