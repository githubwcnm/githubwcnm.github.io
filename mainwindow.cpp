#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ns4.h"

#include <QClipboard>

QString 复制 = QString::fromStdWString(L"复制");
QString 已复制 = QString::fromStdWString(L"已复制");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->copyLeft, &QPushButton::clicked, this, [this]{
        QApplication::clipboard()->setText(ui->left->toPlainText());
    });
    connect(ui->copyRight, &QPushButton::clicked, this, [this]{
        QApplication::clipboard()->setText(ui->right->toPlainText());
    });
    connect(ui->pasteLeft, &QPushButton::clicked, this, [this]{
        ui->left->selectAll();
        ui->left->paste();
    });
    connect(ui->pasteRight, &QPushButton::clicked, this, [this]{
        ui->right->selectAll();
        ui->right->paste();
    });
    connect(ui->clearLeft, &QPushButton::clicked, ui->left, &QPlainTextEdit::clear);
    connect(ui->clearRight, &QPushButton::clicked, ui->right, &QPlainTextEdit::clear);
    connectLeft();
    connectRight();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectLeft() {
    connect(ui->left, &QPlainTextEdit::textChanged, this, [this]{
        ui->right->disconnect();
        ui->right->setPlainText(QString::fromStdWString(ns4::encode(ui->left->toPlainText().toStdString())));
        connectRight();
    });
}

void MainWindow::connectRight() {
    connect(ui->right, &QPlainTextEdit::textChanged, this, [this]{
        ui->left->disconnect();
        ui->left->setPlainText(QString::fromStdString(ns4::decode(ui->right->toPlainText().toStdWString())));
        connectLeft();
    });
}
