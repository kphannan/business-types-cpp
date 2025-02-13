#include <gtest/gtest.h>

#include "baz.hpp"

// Demonstrate some basic assertions.
TEST(BazBase, BasicAssertions)
{
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

TEST(BazBase, CallFunction)
{
    EXPECT_FALSE(lib2::bazFN());
}
