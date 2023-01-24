#include "FileIO.h"

namespace Core
{
	cv::Mat LoadImage(const std::filesystem::path& filepath)
	{
		if (!std::filesystem::is_regular_file(filepath))
		{
			throw std::invalid_argument("Failef to load image. File at given path is not regular file.");
		}

		return cv::imread(filepath.string());
	}
} // namespace Core