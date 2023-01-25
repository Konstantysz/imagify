#include "ImagifyMainWindow.h"
#include "ui_ImagifyMainWindow.h"

#include <QFIleDialog>

ImagifyMainWindow::ImagifyMainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::ImagifyMainWindow),
    status(new QLabel("Waiting for input...")),
    inputImagePixelMap(),
    outputImagePixelMap()
{
    ui->setupUi(this);

    ui->statusBar->addWidget(status);

    ui->inputImage->setPixmap(inputImagePixelMap);
    ui->inputImage->adjustSize();
    
    ui->outputImage->setPixmap(outputImagePixelMap);
    ui->outputImage->adjustSize();

    connect(ui->loadPushButton, &QPushButton::released, this, &ImagifyMainWindow::OnLoadButtonClicked);
    connect(ui->browsePushButton, &QPushButton::released, this, &ImagifyMainWindow::OnBrowseButtonClicked);
}

ImagifyMainWindow::~ImagifyMainWindow()
{
    delete ui;
    delete status;
}

void ImagifyMainWindow::OnLoadButtonClicked()
{
    try
    {
        const auto image = CvMatToQImage(Core::LoadImage(ui->fileLineEdit->text().toStdString()));
        inputImagePixelMap = QPixmap::fromImage(image);
        outputImagePixelMap = QPixmap::fromImage(image);

        ui->inputImage->setPixmap(
            inputImagePixelMap.scaled(ui->inputImage->width(), ui->inputImage->height(), Qt::KeepAspectRatio));
        ui->inputImage->adjustSize();

        ui->outputImage->setPixmap(
            outputImagePixelMap.scaled(ui->outputImage->width(), ui->outputImage->height(), Qt::KeepAspectRatio));
        ui->outputImage->adjustSize();
    }
    catch (const std::invalid_argument& exception)
    {
        DisplayStatus(exception.what());
        return;
    }
}

void ImagifyMainWindow::OnBrowseButtonClicked()
{
    ui->fileLineEdit->setText(
        QFileDialog::getOpenFileName(
            this, 
            "Select file...", 
            QDir::homePath(), 
            tr("All files (*.*);;JPEG (*.jpg *.jpeg);;PNG (*.png)")));
}

void ImagifyMainWindow::resizeEvent(QResizeEvent* resizeEvent)
{
    QMainWindow::resizeEvent(resizeEvent);

    ui->inputImage->setPixmap(
        inputImagePixelMap.scaled(ui->inputImage->width(), ui->inputImage->height(), Qt::KeepAspectRatio));
    ui->inputImage->adjustSize();

    ui->outputImage->setPixmap(
        outputImagePixelMap.scaled(ui->outputImage->width(), ui->outputImage->height(), Qt::KeepAspectRatio));
    ui->outputImage->adjustSize();
}

void ImagifyMainWindow::DisplayStatus(const QString& statusMessage)
{
    ui->statusBar->removeWidget(status);
    status = new QLabel(statusMessage);
    ui->statusBar->addWidget(status);
}

QImage ImagifyMainWindow::CvMatToQImage(const cv::Mat& cvMatImage)
{
    // according to: https://asmaloney.com/2013/11/code/converting-between-cvmat-and-qimage-or-qpixmap/
    switch (cvMatImage.type())
    {
    // 8-bit, 4 channel
    case CV_8UC4:
    {
        QImage image(cvMatImage.data,
            cvMatImage.cols, cvMatImage.rows,
            static_cast<int>(cvMatImage.step),
            QImage::Format_ARGB32);
        return image.copy();
    }
    // 8-bit, 3 channel
    case CV_8UC3:
    {
        QImage image(cvMatImage.data,
            cvMatImage.cols, cvMatImage.rows,
            static_cast<int>(cvMatImage.step),
            QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    // 8-bit, 1 channel
    case CV_8UC1:
    {
        QImage image(cvMatImage.data,
            cvMatImage.cols, cvMatImage.rows,
            static_cast<int>(cvMatImage.step),
            QImage::Format_Grayscale8);
        return image.copy();
    }
    default:
        std::invalid_argument(std::to_string(cvMatImage.type()) + " cv::Mat image type not handled in CvMatToQImage");
        break;
    }

    return QImage();
}