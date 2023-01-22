#include "ImagifyMainWindow.h"
#include "ui_ImagifyMainWindow.h"

#include <filesystem>

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
}

void ImagifyMainWindow::OnLoadButtonClicked()
{
    const auto fileLineEditText = ui->fileLineEdit->text();
    if (!std::filesystem::is_regular_file(fileLineEditText.toStdString()))
    {
        DisplayStatus("File " + fileLineEditText + " does not exist.");
        return;
    }
}

void ImagifyMainWindow::DisplayStatus(const QString& statusMessage)
{
    ui->statusBar->removeWidget(status);
    status = new QLabel(statusMessage);
    ui->statusBar->addWidget(status);
}
