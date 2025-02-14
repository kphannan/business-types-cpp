

#include <string>
#include <stdexcept>
#include <format>

#include "creditcard/CardVerification.hpp"

namespace card
{
    CardVerificationValue::CardVerificationValue(const char *value)
    {
        if (!isValid(value))
            throw std::domain_error(std::format("Not a valid cvv '{}'", value));

        cvv = std::stoi(value);
    }

    CardVerificationValue::CardVerificationValue(const std::string value)
    {
        if (!isValid(value))
            throw std::domain_error(std::format("Not a valid cvv '{}'", value));

        cvv = std::stoi(value);
    }

    bool CardVerificationValue::isValid(const char *value)
    {
        if (nullptr == value)
            throw std::invalid_argument("CVV is required");

        std::regex validator(pattern);

        return std::regex_match(value, validator);
    }

    bool CardVerificationValue::isValid(const std::string value)
    {
        std::regex validator(pattern);

        return std::regex_match(value, validator);
    }
}