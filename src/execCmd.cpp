// execCmd.cpp

#include "execCmd.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <sstream>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append((char*)contents, total_size);
    return total_size;
}

ExecCmd::ExecCmd(const std::string& command) : command(command) {}

std::string ExecCmd::executeCommand() const {
    if (!command.empty()) {
        std::cout << "Executing command: " << command << std::endl;

        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);

        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }

        std::ostringstream resultStream;
        char buffer[128];

        while (fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
            resultStream << buffer;
        }

        return resultStream.str();
    } else {
        std::cout << "No command to execute." << std::endl;
        return "";  
    }
}


void ExecCmd::sendToDiscordWebhook(const std::string& webhookURL, const std::string& message) const {
    CURL* curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        // Échapper le message pour les caractères spéciaux
        char* escapedMessage = curl_easy_escape(curl, message.c_str(), 0);

        std::string postData = "content=```" + std::string(escapedMessage) + "```";

        // Libérer la mémoire allouée par curl_easy_escape
        curl_free(escapedMessage);

        curl_easy_setopt(curl, CURLOPT_URL, webhookURL.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);  // Spécifier la méthode POST

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}