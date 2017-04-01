#include "complementer.h"

Complementer::Complementer(std::set<std::__cxx11::string> data)
    : data(data)
{

}

void Complementer::setInput(const std::__cxx11::string &input)
{
    hints.clear();
    std::copy_if(data.begin(), data.end(), std::back_inserter(hints), [&input](const std::string &value) {
        return value.substr(0, input.size()) == input;
    });

//    if(hints.size() > 0)
//        hint = hints.front();
    if(hints.size() < 1)
        hint = "";
    else {
        hint = hints.front();
        for(auto str : hints) {
            int common_symbols = 0;
            for(auto it1 = hint.begin(), it2 = str.begin(); it1 != hint.end() && it2 != str.end(); it1++, it2++) {
                if(*it1 != *it2)
                    break;
                common_symbols++;
            }
            hint = hint.substr(0, common_symbols);
        }
    }

}

const std::list<std::string> &Complementer::getHints() const
{
    return hints;
}

const std::__cxx11::string &Complementer::getHint() const
{
    return hint;
}

