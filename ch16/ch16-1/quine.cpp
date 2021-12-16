#include <iostream>
#include <string>
using namespace std;
int main()
{
    char aDoubleQuot = 34;
    string str[] = {
        "#include <iostream>",
        "#include <string>",
        "using namespace std;",
        "int main()",
        "{",
        "   char a = 34;",
        "   string str[] = {",
        "       ",
        "   };",
        "   for (int i = 0; i <= 6;i++) cout << str[i] << endl;",
        "   for (int i = 0; i <= 13; i++) cout << str[7] + aDoubleQuot + str[i] + aDoubleQuot + ',' << endl;",
        "   for (int i = 8; i <= 13; i++) cout << str[i] << endl;",
        "   return 0",
        "}"
    };
    for (int i = 0; i <= 6;i++) cout << str[i] << endl;
    for (int i = 0; i <= 13; i++) cout << str[7] + aDoubleQuot + str[i] + aDoubleQuot + ',' << endl;
    for (int i = 8; i <= 13; i++) cout << str[i] << endl;
    return 0;
}