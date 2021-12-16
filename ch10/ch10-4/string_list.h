#pragma once
#include <string>

class String_list
{
private:
    std::string* l;
    size_t size;
    size_t max;

    void resize();
    
public:
    typedef std::string* iterator;
    String_list() : l(new std::string[1]), size(0), max(1){};
    String_list(const String_list&);
    ~String_list();

    void push_back(const std::string&);
    std::string* begin(){return l;}
    std::string* end(){return l + size;}
};

