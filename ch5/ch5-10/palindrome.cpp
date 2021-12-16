#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool is_palindrome(const string& str){
    string reverse;
    reverse_copy(str.begin(), str.end(), back_inserter(reverse));
    return (str == reverse);
}

int main(int argc, char* argv[]){
    vector<string> words;
    cout << "Please enter a series of words: ";
    string word;
    while (cin >> word)
    {
        if(is_palindrome(word)) words.push_back(word);
    }
    string maxlen;
    for(vector<string>::const_iterator it = words.begin(); it != words.end(); ++it){
        if(maxlen.size() < it->size()) maxlen = (*it);
    }
    
    cout << "the longest palindrome is " << maxlen <<  endl;
    return 0;
}