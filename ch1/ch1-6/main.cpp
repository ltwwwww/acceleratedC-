#include <iostream>
#include <string>

int main(){
    std::cout << "what is your name?";
    std::string name;
    std::cin >> name;
    std::cout << "hello, " << name << std::endl << "And what is yours? ";
    std::cin >> name;
    std::cout << "hello, " << name << "; nice to meet you too!" << std::endl;
    return 0;
}