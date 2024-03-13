#include "execCmd.hpp"
#include <cstdlib>
#include <iostream>

ExecCmd::ExecCmd(const std::string& command) : command(command) {}

void ExecCmd::executeCommand() const {
    if (!command.empty()) {
        std::cout << "Executing command: " << command << std::endl;
        int result = std::system(command.c_str());

        if (result == 0) {
            std::cout << "Command executed successfully." << std::endl;
        } else {
            std::cerr << "Error executing command." << std::endl;
        }
    } else {
        std::cout << "No command to execute." << std::endl;
    }
}
