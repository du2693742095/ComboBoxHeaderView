#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "CustomHeadView.h"
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initTable()
{
    QStandardItemModel *pModel = new QStandardItemModel(ui->tableView);
    ui->tableView->setModel(pModel);

    CustomHeader *pHeader = new CustomHeader(Qt::Orientation::Horizontal, ui->tableView);
    ui->tableView->setHorizontalHeader(pHeader);

    QStringList headerList;
    headerList << "第一列" << "第二列" << "第三列";
    pModel->setHorizontalHeaderLabels(headerList);
    pModel->setItem(0, 0, new QStandardItem("A"));
    pModel->setItem(0, 1, new QStandardItem("1"));
    pModel->setItem(1, 0, new QStandardItem("A"));
    pModel->setItem(1, 1, new QStandardItem("2"));
}
