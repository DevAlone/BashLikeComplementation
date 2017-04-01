#ifndef COMPLEMENTER_H
#define COMPLEMENTER_H

#include <set>
#include <string>
#include <list>
#include <algorithm>

class Complementer
{
public:
    Complementer(std::set<std::string> data);

    void setInput(const std::string &input);
    const std::list<std::string>& getHints() const;
    const std::string &getHint() const;

private:
    std::set<std::string> data;
    std::list<std::string> hints;
    std::string hint;
};

#endif // COMPLEMENTER_H
