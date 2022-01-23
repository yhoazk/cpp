#include <iostream>
#include <string>
#include <curl/curl.h>

static size_t write_callback(void *contents, size_t size, size_t nmemb, void* userp) {
    auto user{static_cast<std::string*>(userp)};
    user->append(static_cast<char*>(contents), size * nmemb);
    return size * nmemb;
}


int main() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        std::cout << readBuffer << std::endl;
    }
    return 0;
}
