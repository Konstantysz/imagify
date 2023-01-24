#include "ImagifyMainWindow.h"
#include "ui_ImagifyMainWindow.h"
#include "FileIO.h"

ImagifyMainWindow::ImagifyMainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::ImagifyMainWindow)
{
    ui->setupUi(this);

    static const char* status_waiting = "Waiting for input...";
    status = new QLabel(status_waiting);
    ui->statusBar->addWidget(status);

    connect(ui->loadPushButton, &QPushButton::released, this, &ImagifyMainWindow::OnLoadButtonClicked);
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
        const auto image = Core::LoadImage(ui->fileLineEdit->text().toStdString());
    }
    catch (const std::invalid_argument& exception)
    {
        DisplayStatus(exception.what());
        return;
    }
}

void ImagifyMainWindow::DisplayStatus(const QString& statusMessage)
{
    ui->statusBar->removeWidget(status);
    status = new QLabel(statusMessage);
    ui->statusBar->addWidget(status);
}
