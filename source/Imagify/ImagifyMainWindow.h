#pragma once
#include "FileIO.h"

#include <QLabel>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>

/*! \file ImagifyMainWindow.h
    Contains main window of the Imagify app.
*/
namespace Ui {
    class ImagifyMainWindow;
}

/*! \class ImagifyMainWindow
	Class that handles logic of the Imagify main window.
*/
class ImagifyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*! Class constructor.
        \param[in] parent Widget that is parent to this window. Default root.
    */
    explicit ImagifyMainWindow(QWidget* parent = 0);

    //! Class destructor.
    ~ImagifyMainWindow();

private slots:
    //! Method that handles event when load button is clicked.
    void OnLoadButtonClicked();

private:
    /*! Method that displays status message in window.
        \param[in] statusMessage Message to be displayed.
    */
    void DisplayStatus(const QString& statusMessage);

    /*! Method for converting cv::Mat to QImage.
        \param[in] cvMatImage cv mat image.
        \returns Converted image.
    */
    QImage CvMatToQImage(const cv::Mat& cvMatImage);

    Ui::ImagifyMainWindow* ui;  //!< Main window UI.
    QLabel* status;             //!< Status of the program.
};
