#include "complementer.h"

Complementer::Complementer(const std::set<std::string>& data)
    : data(data)
{
}

Complementer::Complementer(std::set<std::string>&& data)
    : data(data)
{
}

void Complementer::setInput(const std::string& input)
{
    hints.clear();

    auto inputSize = input.size();

    for (const std::string& dataStr : data) {
        if (dataStr.substr(0, inputSize) == input)
            hints.push_back(std::reference_wrapper<std::string const>(dataStr));
    }

    if (hints.size() < 1 || inputSize < 1)
        hint = "";
    else {
        hint = hints.front();
        for (const std::string& str : hints) {
            int commonSymbols = 0;

            for (std::string::const_iterator it1 = hint.begin(), it2 = str.begin();
                 it1 != hint.end() && it2 != str.end();
                 it1++, it2++) {
                if (*it1 != *it2)
                    break;
                commonSymbols++;
            }

            hint = hint.substr(0, commonSymbols);
        }
    }
}

const std::vector<std::reference_wrapper<const std::string> >& Complementer::getHints() const
{
    return hints;
}

const std::__cxx11::string& Complementer::getHint(const std::string& ifNotFound) const
{
    return hint.size() > 0 ? hint : ifNotFound;
}
