#ifndef HTTPREQUEST_HPP
#define HTTPREQUEST_HPP

#include <curl/curl.h>
#include <string>
#include <iostream>
class HttpRequest {
public:
    HttpRequest();
    ~HttpRequest();

    std::string get(const std::string& url, const std::string& userAgent = "");

private:
    CURL* curl;
    static const char* defaultUserAgent;

    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);
};

#endif