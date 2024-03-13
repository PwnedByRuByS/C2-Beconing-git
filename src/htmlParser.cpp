#include "htmlParser.hpp"
#include "cmd.hpp"

HtmlParser::HtmlParser(Cmd& cmd) : pattern("<p dir=\"auto\">(.*?)</p>"), cmd(cmd) {}

std::string HtmlParser::extractContent(const std::string& html) {
    std::smatch matches;
    std::string extractedContent;

    auto words_begin = std::sregex_iterator(html.begin(), html.end(), pattern);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        extractedContent += match.str(1);
        cmd.addContent(match.str(1));
    }

    std::cout << "Number of matches: " << std::distance(words_begin, words_end) << std::endl;
    setcmd_number(std::distance(words_begin, words_end));
    return extractedContent;
}

void HtmlParser::setcmd_number(int i) {
    cmd_number = i;
}
    
int HtmlParser::getcmd_number() {
    return cmd_number;
}
