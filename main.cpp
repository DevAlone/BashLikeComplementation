#include "complementer.h"

#include <conio.h>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Complementer complementer({ "test", "tea", "teapot", "linux", "bash", "qtcreator", "qt" });
    std::string str;
    int symbol;
    while (symbol = getch()) {
        if (symbol == '\t') {
            complementer.setInput(str);
            cout << endl;
            for (const std::string& hint : complementer.getHints())
                cout << "\t" << hint << endl;
            str = complementer.getHint();
            cout << str;
        } else if (symbol == '\n') {
            str.clear();
            cout << (char)symbol;
        } else if (symbol == '\b' || symbol == 127) {
            if (str.length() > 0) {
                str.pop_back();
                cout << '\b' << ' ' << '\b';
            }
        } else if (symbol >= 'a' && symbol <= 'z' || symbol >= 'A' && symbol <= 'Z') {
            str += symbol;
            cout << (char)symbol;
        }
    }
    return 0;
}
