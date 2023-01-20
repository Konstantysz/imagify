#pragma once
#include <QLabel>
#include <QMainWindow>

namespace Ui {
    class ImagifyMainWindow;
}

class ImagifyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImagifyMainWindow(QWidget* parent = 0);
    ~ImagifyMainWindow();

// private slots:

private:
    Ui::ImagifyMainWindow* ui;
    QLabel* status;
};
