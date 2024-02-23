#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QWebEngineView;

class ContainerApi;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(ContainerApi *containerApi, QWidget *parent = nullptr);
    ~MainWindow();

private:
    ContainerApi *containerApi_{};

    Ui::MainWindow *ui{};

    QWebEngineView *webView_{};
};

#endif // MAINWINDOW_H
