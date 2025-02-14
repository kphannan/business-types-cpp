

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

    //   --- Copy constructor ---
    TEST_F(CardVerificationValueTest, CopyConstructor)
    {
        CardVerificationValue cvv1("123");
        CardVerificationValue cvv2(cvv1);

        EXPECT_TRUE(cvv1 == cvv2);
    }

    // ----- Operator -----

    //   --- type conversion ---
    TEST_F(CardVerificationValueTest, ConvertToString)
    {
        CardVerificationValue cvv{"321"};
        std::string val = cvv;

        EXPECT_EQ("321", (std::string)val);
    }

    TEST_F(CardVerificationValueTest, ConvertToInt)
    {
        CardVerificationValue cvv{"456"};
        int val = cvv;

        EXPECT_EQ(456, val);
    }

    //   --- comparison ---
    TEST_F(CardVerificationValueTest, CompareSameIsTrue)
    {
        CardVerificationValue cvv1{"456"};
        CardVerificationValue cvv2{"456"};

        EXPECT_TRUE(cvv1 == cvv2);
    }

    TEST_F(CardVerificationValueTest, CompareDifferentIsFalse)
    {
        CardVerificationValue cvv1{"456"};
        CardVerificationValue cvv2{"999"};

        EXPECT_FALSE(cvv1 == cvv2);
    }

}
