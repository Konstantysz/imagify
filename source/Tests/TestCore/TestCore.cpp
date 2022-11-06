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
		testImage = cv::imread(testImagePath.string(), cv::IMREAD_COLOR);
	}

	void TearDown() override
	{
	}

	const std::filesystem::path testDataDirectory = Imagify::Core::Constants::dataDirectory / "TestCore";
	const std::filesystem::path testImagePath = testDataDirectory / "lena.jpg";
	cv::Mat testImage;
};

TEST_F(TestCore, TestConvertBGRToGray)
{
	ASSERT_TRUE(1);
}

TEST_F(TestCore, TestEqualizeHistogram)
{
	ASSERT_TRUE(1);
}

TEST_F(TestCore, TestDetectFaces) 
{
	ASSERT_EQ(Imagify::Core::DetectFaces(testImage, ""), std::vector<cv::Rect>());

	const auto detectedFaces = Imagify::Core::DetectFaces(testImage);
	ASSERT_EQ(detectedFaces.size(), 1ULL);
	ASSERT_EQ(detectedFaces, std::vector<cv::Rect>({ cv::Rect(218, 203, 170, 170) }));
	ASSERT_EQ(detectedFaces, Imagify::Core::DetectFaces(testImage, Imagify::Core::Constants::faceClassifierPath));
}

TEST_F(TestCore, TestPixalateImage)
{
	const auto pixalatedTestImage = Imagify::Core::PixalateImage(testImage);

	ASSERT_TRUE(1);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	int ret = RUN_ALL_TESTS();
	return ret;
}