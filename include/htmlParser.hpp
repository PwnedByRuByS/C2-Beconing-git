#ifndef HTMLPARSER_HPP
#define HTMLPARSER_HPP

#include <regex>
#include <string>
#include <iostream>
class Cmd;

class HtmlParser {
public:
    HtmlParser(Cmd& cmd);
    std::string extractContent(const std::string& html);
    void setcmd_number(int i);
    int getcmd_number();
private:
    std::regex pattern;
    Cmd& cmd;
    int cmd_number;
};

#endif
