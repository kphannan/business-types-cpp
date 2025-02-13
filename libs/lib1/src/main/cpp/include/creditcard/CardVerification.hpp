

#pragma once

#include <string>
#include <regex>

namespace card
{
    class CardVerificationValue
    {
    private:
        std::string pattern = "[0-9]{3,4}";
        // std::regex validation("[0-9]{3,4}");

    public:
        CardVerificationValue(const char *value);
        CardVerificationValue(const std::string value);

    private:
        bool isValid(const char *value);
        bool isValid(const std::string value);
    };
}