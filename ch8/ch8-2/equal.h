#pragma once

template <typename In>
bool equal(In beg, In end, In dst){
    while (beg != end)
    {
        if(*beg++ != *dst++) return false; 
    }
    return true;
}