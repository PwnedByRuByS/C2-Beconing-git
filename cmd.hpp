#ifndef CMD_HPP
#define CMD_HPP

#include <vector>
#include <string>
#include "htmlParser.hpp"

class Cmd {
public:
    Cmd();
    void addContent(const std::string& content);
    const std::vector<std::string>& getAllContent() const;
    const std::string& getLastContent() const;
    bool addContentIfChanged(const std::string& content);
    
private:
    std::string lastContent;
    HtmlParser htmlParser;
    std::vector<std::string> allContent;
};

#endif
