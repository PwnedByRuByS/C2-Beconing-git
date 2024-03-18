#include "cmd.hpp"

Cmd::Cmd() : lastContent(""), htmlParser(*this) {}

void Cmd::addContent(const std::string& content) {
    allContent.push_back(content);
    lastContent = content;
}

const std::vector<std::string>& Cmd::getAllContent() const {
    return allContent;
}

const std::string& Cmd::getLastContent() const {
    return lastContent;
}

bool Cmd::addContentIfChanged(const std::string& content) {
    // La fonction ne fait pas ce qu'elle prétend faire.
    // On peut penser à isNewContent() par exemple.
    // Le code appellant pourra assez naturellement faire
    // if (cmd.isNewContent(content) {addContent();})
    return content != allContent.back();
}
