#ifndef COMPLEMENTER_H
#define COMPLEMENTER_H

#include <algorithm>
#include <functional>
#include <list>
#include <set>
#include <string>
#include <vector>

class Complementer {
public:
    Complementer(const std::set<std::string>& data);
    Complementer(std::set<std::string>&& data);

    void setInput(const std::string& input);
    const std::vector<std::reference_wrapper<std::string const>>& getHints() const;
    const std::string& getHint(const std::string& ifNotFound) const;

private:
    std::set<std::string> data;
    //    std::list<std::string> hints;
    std::vector<std::reference_wrapper<std::string const>> hints;
    std::string hint;
};

#endif // COMPLEMENTER_H
