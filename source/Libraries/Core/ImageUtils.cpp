#include "ImageUtils.h"

namespace Imagify::Core
{
    cv::Mat ConvertBGRToGray(const cv::Mat& image)
    {
        if (image.channels() == 1)
        {
            return image;
        }

        if (image.channels() != 3)
        {
            throw std::invalid_argument("Number of channels has to be equal three to convert from BGR to Grayscale.");
        }

        cv::Mat output;
        cv::cvtColor(image, output, cv::COLOR_BGR2GRAY);

        return output;
    }

    cv::Mat EqualizeHistogram(const cv::Mat& image)
    {
        if (image.channels() != 1)
        {
            throw std::invalid_argument("Number of channels for histogram equalization has to be equal one.");
        }

        cv::Mat output;
        equalizeHist(image, output);

        return output;
    }

    std::vector<cv::Rect> DetectFaces(const cv::Mat& image, const std::filesystem::path& pathToClassifier)
    {
        if (image.channels() != 1)
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
    
    cv::Mat PixalateImage(const cv::Mat& image, const cv::Size& targetPixelWidth)
    {
        // Resize input to "pixelated" size
        cv::Mat tempImage;
        cv::resize(image, tempImage, targetPixelWidth, 0.0, 0.0, cv::INTER_LINEAR);
        
        // Initialize output image
        cv::Mat outputImage;
        cv::resize(tempImage, outputImage, image.size(), 0.0, 0.0, cv::INTER_NEAREST);

        return outputImage;
    }

    cv::Mat PixalateImageFragment(const cv::Mat& image, const cv::Rect& imageFragmentToPixalate, const cv::Size& targetPixelWidth)
    {
        const auto imageFragment = image(
            cv::Range(imageFragmentToPixalate.x, imageFragmentToPixalate.x + imageFragmentToPixalate.width), 
            cv::Range(imageFragmentToPixalate.y, imageFragmentToPixalate.y + imageFragmentToPixalate.height));

        const auto pixalatedImageFragment = PixalateImage(imageFragment);

        cv::Mat outputImage = image.clone();
        cv::Mat outputImageFragment = cv::Mat(outputImage, imageFragmentToPixalate);
        pixalatedImageFragment.copyTo(outputImageFragment);
   
        return outputImage;
    }
}