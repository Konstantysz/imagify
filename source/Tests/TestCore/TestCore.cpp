#include <gtest/gtest.h>

class TestCore : public ::testing::Test
{
protected:
	void SetUp() override
	{	
	}

	void TearDown() override
	{
	}
};

// Tests FileIO
TEST_F(TestCore, FileIO) 
{
	ASSERT_TRUE(1);
}