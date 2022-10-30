#include "Utils.h"

#include <gtest/gtest.h>

// Example test
TEST(HelloTest, BasicAssertions) 
{
  EXPECT_EQ(Imagify::ImageProcessing::IntToDouble(2), 2.0);
}