#pragma once

#include "Constants.h"

#include <vector>
#include <filesystem>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

namespace Imagify::Core
{
    /*! Method used to convert BGR image to grayscale.
        \param[in] image Image to convert.
        \returns Grayscale version of image.
        \throws std::invalid_argument if number of channels different than three or one.
    */
    [[nodiscard]] cv::Mat ConvertBGRToGray(const cv::Mat& image);

    /*! Method used to equalize image histogram.
        \param[in] image Image to equalize.
        \returns Image with equalized histogram.
        \throws std::invalid_argument if number of channels different than one.
    */
    [[nodiscard]] cv::Mat EqualizeHistogram(const cv::Mat& image);

    /*! Method used to detect faces using Haar Feature-based Cascade Classifier.
        \param[in] image Image on which detect faces.
        \param[in] pathToClassifier Path to XML file with face classifier. Default is path to `data` directory file `haarcascade_frontalface_default.xml`.
        \returns Vector of found faces.
    */
    [[nodiscard]] std::vector<cv::Rect> DetectFaces(const cv::Mat& image, const std::filesystem::path& pathToClassifier = Constants::faceClassifierPath);

    /*! Method used to pixalate image.
        \param[in] image Image to pixalize.
        \param[in] targetPixelWidth target pixel width and height. Default value is 16x16.
        \returns Pixalated image.
    */
    [[nodiscard]] cv::Mat PixalateImage(const cv::Mat& image, const cv::Size& targetPixelWidth = cv::Size(16, 16));

    /*! Method used to pixalate image fragment.
        \param[in] image Image to pixalize.
        \param[in] imageFragmentToPixalate ROI of image to pixalate.
        \param[in] targetPixelWidth target pixel width and height. Default value is 16x16.
        \returns Pixalated image.
    */
    [[nodiscard]] cv::Mat PixalateImageFragment(
        const cv::Mat& image, 
        const cv::Rect& imageFragmentToPixalate, 
        const cv::Size& targetPixelWidth = cv::Size(8, 8));
}