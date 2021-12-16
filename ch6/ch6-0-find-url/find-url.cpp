#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

bool not_str_char(const char x){
    static const string leagel = "#@%&*./:";
    return !(isalnum(x) || find(leagel.begin(), leagel.end(), x) != leagel.end());
}

bool not_space(const char x){
    return !isspace(x);
}

string::const_iterator find_end(string::const_iterator b, string::const_iterator e){
    return find_if(b, e, not_str_char);
}

string::const_iterator find_begin(string::const_iterator b, string::const_iterator e){
    static const string sep = "://";
    typedef string::const_iterator iter;
    iter i = b;
    while ((i = search(i, e, sep.begin(), sep.end())) != e)
    {
        if( i != b && i + sep.size() != e){
            iter begin = i;
            while (!isspace(begin[-1]) && begin != b)
            {
                --begin;
            }
            if(i + sep.size() != e && i != begin && !not_str_char(i[sep.size()]))
                return begin;
        }
        if(i != e)
            i = i + sep.size();
    }
    return e;
}

vector<string> find_urls(const string& s){
    vector<string> urls;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();
    while (b != e)
    {
        b = find_begin(b, e);

        if(b != e){
            iter after = find_end(b, e);
            urls.push_back(string(b, after));
            b = after;
        }
    }
    return urls;
}

int main(int argc, char* argv[]){
    vector<string> urls = find_urls("http://baidu.com https://google.com ://ssss a://sdf");
    for(vector<string>::size_type i = 0; i != urls.size(); ++i){
        cout << urls[i] << endl;
    }
    return 0;
}
