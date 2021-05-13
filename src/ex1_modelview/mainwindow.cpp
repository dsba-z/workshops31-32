#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QWidget>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QList>

#include <iostream>

void MainWindow::setListViewColumn(int value)
{
    ui->listView->setModelColumn(value);
}

void fillModelWithData(QStandardItemModel* titanicModel)
{
    QFile inputFile("../../data/titanic.csv");
    inputFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream inputStream(&inputFile);

    
    
    QString firstline = inputStream.readLine();
    titanicModel->setHorizontalHeaderLabels(firstline.split(","));
    
    while(!inputStream.atEnd())
    {
        QString line = inputStream.readLine();
        
        QList<QStandardItem *> dataRow;
        for (QString& item : line.split(",")) {
            dataRow.append(new QStandardItem(item));
        }
        titanicModel->appendRow(dataRow);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    titanicModel = new QStandardItemModel(this);
    
    ui->listView->setModel(titanicModel);
    ui->tableView->setModel(titanicModel);

    fillModelWithData(titanicModel);

    ui->listView->setModelColumn(3);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete titanicModel;
}

