
#include "string_list.h"

#include <string>
using namespace std;

String_list::String_list(const String_list& src)
{
    *this = src;
    l = new string[max];

    for(size_t i = 0; i < size; ++i){
        l[i] = src.l[i];
    }
}

String_list::~String_list()
{
    delete[] l;
}


void String_list::resize(){
    max *= 2;
    string* copy = new string[max];

    for(size_t i = 0; i < size; ++i){
        copy[i] = l[i];
    }
    delete[] l;
    l = copy;
}
    

void String_list::push_back(const std::string& str){
    if(size == max) resize();
    l[size++] = str;
}