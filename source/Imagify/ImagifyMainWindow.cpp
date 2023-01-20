#include "ImagifyMainWindow.h"
#include "ui_ImagifyMainWindow.h"

static const char* status_waiting = "Waiting for input...";

ImagifyMainWindow::ImagifyMainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::ImagifyMainWindow)
{
    ui->setupUi(this);

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
    ui->statusBar->removeWidget(status);
    status = new QLabel(ui->fileLineEdit->text());
    ui->statusBar->addWidget(status);
}
