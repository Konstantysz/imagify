#pragma once
#include <QLabel>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
    class ImagifyMainWindow;
}

class ImagifyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImagifyMainWindow(QWidget* parent = 0);

    ~ImagifyMainWindow();

private slots:
    void OnLoadButtonClicked();

private:
    void DisplayStatus(const QString& statusMessage);

    Ui::ImagifyMainWindow* ui;
    QLabel* status;
    QLineEdit* file;
    QPushButton* loadButton;
};
