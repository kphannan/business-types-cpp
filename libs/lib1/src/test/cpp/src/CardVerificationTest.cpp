

#include <gtest/gtest.h>

#include "creditcard/CardVerification.hpp"

namespace card
{
    class CardVerificationValueTest : public testing::Test
    {
    public:
    protected:
    };

    // ----- Constructor -----
    //   --- valid CVV ---
    TEST_F(CardVerificationValueTest, ConstructWith3DigitsString)
    {
        CardVerificationValue *cvv = new CardVerificationValue(std::string("123"));

        EXPECT_TRUE(nullptr != cvv);
    }

    TEST_F(CardVerificationValueTest, ConstructWith3Digits)
    {
        CardVerificationValue *cvv = new CardVerificationValue("123");

        EXPECT_TRUE(nullptr != cvv);
    }

    TEST_F(CardVerificationValueTest, ConstructWith4Digits)
    {
        CardVerificationValue *cvv = new CardVerificationValue("1234");

        EXPECT_TRUE(nullptr != cvv);
    }

    //  --- Invalid CVV ---
    TEST_F(CardVerificationValueTest, ConstructWithNullThrows)
    {
        EXPECT_THROW(CardVerificationValue{nullptr}, std::invalid_argument);
    }

    TEST_F(CardVerificationValueTest, ConstructWith2DigitsThrows)
    {
        EXPECT_THROW(CardVerificationValue{"12"}, std::domain_error);
    }

    TEST_F(CardVerificationValueTest, ConstructWith0DigitsThrows)
    {
        EXPECT_THROW(CardVerificationValue{""}, std::domain_error);
    }

    TEST_F(CardVerificationValueTest, ConstructWithAlphaThrows)
    {
        EXPECT_THROW(CardVerificationValue{"text"}, std::domain_error);
    }

    TEST_F(CardVerificationValueTest, ConstructWithAlphaThrowMessage)
    {
        try
        {
            CardVerificationValue("text");
        }
        catch (const std::exception &e)
        {
            EXPECT_STREQ("Not a valid cvv 'text'", e.what());
        }
    }

    TEST_F(CardVerificationValueTest, ConstructWithNullThrowMessage)
    {
        try
        {
            CardVerificationValue(nullptr);
        }
        catch (const std::exception &e)
        {
            EXPECT_STREQ("CVV is required", e.what());
        }
    }

}
