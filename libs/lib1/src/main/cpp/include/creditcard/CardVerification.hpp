

#pragma once

#include <string>
#include <regex>

namespace card
{
    class CardVerificationValue
    {
    private:
        /**
         * @brief A CVV may be 3 or 4 digits only.
         */
        static constexpr std::string pattern = "[0-9]{3,4}";

    public:
        CardVerificationValue(const char *value);
        CardVerificationValue(const std::string value);

        operator int() const { return cvv; }
        operator std::string() const { return std::to_string(cvv); }
        bool operator==(const CardVerificationValue &rhs) const { return cvv == rhs.cvv; }
        auto operator<=>(const CardVerificationValue &rhs) const = default;

    private:
        bool isValid(const char *value);
        bool isValid(const std::string value);

    private:
        int cvv;
    };
}