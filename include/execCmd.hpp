// execCmd.hpp

#ifndef EXEC_CMD_HPP
#define EXEC_CMD_HPP

#include <string>

class ExecCmd {
public:
    ExecCmd(const std::string& command);
    std::string executeCommand() const;
    void sendToDiscordWebhook(const std::string& webhookURL, const std::string& message) const;

private:
    std::string command;
};

#endif // EXEC_CMD_HPP
