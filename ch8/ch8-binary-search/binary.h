#pragma once

template <typename Ran, typename X>
bool binary_search(Ran beg, Ran end, const X& x){
    while (beg <= end)
    {
        Ran mid = beg + (end - beg) / 2;

        if(*mid < x)
            beg = mid + 1;
        else if(*mid > x)
            end = mid - 1;
        else return true;
    }
    return false;
}