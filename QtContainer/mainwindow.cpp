#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "containerapi.h"

#include <QAction>
#include <QWebEngineView>

MainWindow::MainWindow(ContainerApi *containerApi, QWidget *parent) :
    QMainWindow(parent),
    containerApi_(containerApi),
    ui(new Ui::MainWindow),
    webView_(new QWebEngineView(this))
{
    ui->setupUi(this);

    setCentralWidget(webView_);

    connect(ui->action_SendEvent, &QAction::triggered,
            containerApi_, &ContainerApi::triggerEvent);
    connect(ui->action_Reload, &QAction::triggered,
            webView_, &QWebEngineView::reload);
    connect(ui->action_Quit, &QAction::triggered,
            QApplication::instance(), &QApplication::quit);

    webView_->load(QUrl("qrc:///index.html"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
