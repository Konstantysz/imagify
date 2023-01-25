#include "ImagifyMainWindow.h"
#include "ui_ImagifyMainWindow.h"

#include <QFIleDialog>

ImagifyMainWindow::ImagifyMainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::ImagifyMainWindow),
    status(new QLabel("Waiting for input..."))
{
    ui->setupUi(this);

    ui->statusBar->addWidget(status);

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
        QPixmap imagePixelMap = QPixmap::fromImage(image);
        ui->inputImage->setPixmap(
            imagePixelMap.scaled(ui->inputImage->width(), ui->inputImage->height(), Qt::KeepAspectRatio));
        ui->inputImage->adjustSize();
        ui->inputImage->setScaledContents(true);
        ui->inputImage->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        ui->inputImage->show();
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
        QFileDialog::getOpenFileName(this, "Select file...", QDir::homePath(), "Images (*.jpg, *.png)"));
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