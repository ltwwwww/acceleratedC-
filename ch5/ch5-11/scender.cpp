#include <iostream>
#include <vector>
#include <string>
using namespace std;

const string ascenders = "bdfhklt";
const string descenders = "gjpqy";

bool has_chars(const string& word, const string& chars){
    for(string::size_type i = 0; i != word.size(); ++i){
        for(string::size_type j = 0; j != chars.size(); ++j){
            if(word[i] == chars[j]) return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]){
    vector<string> words;
    cout << "Please enter a series of words: ";
    string word;
    while (cin >> word)
    {
        if(!has_chars(word, ascenders) && !has_chars(word, descenders)) 
            words.push_back(word);
    }
    string maxlen;
    for(vector<string>::const_iterator it = words.begin(); it != words.end(); ++it){
        if(maxlen.size() < it->size()) maxlen = (*it);
    }
    cout << "the longest word not containing ascenders or descenders is: " << maxlen <<  endl;

    return 0;
}

