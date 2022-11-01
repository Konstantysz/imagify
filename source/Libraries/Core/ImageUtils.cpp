#include "ImageUtils.h"

namespace Imagify::Core
{
    cv::Mat ConvertBGRToGray(const cv::Mat& image)
    {
        cv::Mat output;
        cv::cvtColor(image, output, cv::COLOR_BGR2GRAY);

        return output;
    }

    cv::Mat EqualizeHistogram(const cv::Mat& image)
    {
        cv::Mat output;
        equalizeHist(image, output);

        return output;
    }

    std::vector<cv::Rect> DetectFaces(const cv::Mat& image, const std::filesystem::path& pathToClassifier)
    {
        if (image.channels() == 3)
        {
            return DetectFaces(ConvertBGRToGray(image), pathToClassifier);
        }

        if (!std::filesystem::is_regular_file(pathToClassifier))
        {
            return std::vector<cv::Rect>();
        }

        auto faceCascade = cv::CascadeClassifier();
        if (!faceCascade.load(pathToClassifier.string()))
        {
            return std::vector<cv::Rect>();
        }

        const auto equalizedHistogramImage = EqualizeHistogram(image);
        auto faces = std::vector<cv::Rect>();
        faceCascade.detectMultiScale(equalizedHistogramImage, faces);

        return faces;
    }
}