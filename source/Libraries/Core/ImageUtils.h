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
    */
    cv::Mat ConvertBGRToGray(const cv::Mat& image);

    /*! Method used to equalize image histogram.
        \param[in] image Image to equalize.
        \returns Image with equalized histogram.
    */
    cv::Mat EqualizeHistogram(const cv::Mat& image);

    /*! Method used to detect faces using Haar Feature-based Cascade Classifier.
        \param[in] image Image on which detect faces.
        \returns Vector of found faces.
    */
    std::vector<cv::Rect> DetectFaces(const cv::Mat& image, const std::filesystem::path& pathToClassifier = Constants::faceClassifierPath);
}