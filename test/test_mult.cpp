#include <gtest/gtest.h>
#include "mult.h"

TEST(MultTest, HandlesPositiveInput)
{
    int result = mult(4, 5);

    EXPECT_EQ(result, 20);
}