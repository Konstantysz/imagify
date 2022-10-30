#include "Utils.h"

#include <gtest/gtest.h>


class TestImageProcessing : public ::testing::Test
{
protected:
	void SetUp() override
	{
	}

	void TearDown() override
	{
	}
};

TEST_F(TestImageProcessing, TestIntToDouble) 
{
  EXPECT_EQ(Imagify::ImageProcessing::IntToDouble(2), 2.0);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	int ret = RUN_ALL_TESTS();
	return ret;
}