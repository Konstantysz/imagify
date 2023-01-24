#pragma once
#include <filesystem>

#include <opencv2\opencv.hpp>

namespace Core
{
	/*! Method used to load image from file.
		\param[in] filepath Path to image file.
		\returns Image loaded from file.
		\throws std::invalid_argument on incorrect file path.
	*/ 
	cv::Mat LoadImage(const std::filesystem::path& filepath);
} // namespace Core