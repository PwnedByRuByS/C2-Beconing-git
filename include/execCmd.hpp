#ifndef EXEC_CMD_HPP
#define EXEC_CMD_HPP

#include <string>

class ExecCmd {
public:
    ExecCmd(const std::string& command);

    void executeCommand() const;

private:
    const std::string& command;
};

#endif
