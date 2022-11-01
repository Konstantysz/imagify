#include "ImageUtils.h"
#include "Constants.h"

#include <filesystem>
#include <gtest/gtest.h>
#include <opencv2/highgui.hpp>


class TestCore : public ::testing::Test
{
protected:
	void SetUp() override
	{
	}

	void TearDown() override
	{
	}

	const std::filesystem::path testDataDirectory = Imagify::Core::Constants::dataDirectory / "TestCore";
};

TEST_F(TestCore, TestDetectFaces) 
{
	const std::filesystem::path testImagePath = testDataDirectory / "lena.jpg";
	cv::Mat testImage = cv::imread(testImagePath.string(), cv::IMREAD_COLOR);

	ASSERT_EQ(Imagify::Core::DetectFaces(testImage, ""), std::vector<cv::Rect>());
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	int ret = RUN_ALL_TESTS();
	return ret;
}