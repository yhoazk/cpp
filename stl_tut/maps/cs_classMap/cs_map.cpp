#include <bits/stdc++.h>

class test {
    public:
    enum class ErrorType: uint8_t { kSucc = 0, kMeh, kOknt};
    static std::map<ErrorType, const std::string>  decode_err ;
};

std::map<test::ErrorType, const std::string>   test::decode_err={
    {ErrorType::kSucc, "AOk"},
    {ErrorType::kMeh, "Meh"},
    {ErrorType::kOknt, "Okn't"}
};

int main() {
    std::cout << test::decode_err[test::ErrorType::kSucc] << std::endl;
    return 0;
}