#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QWidget>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QFileDialog>

#include <iostream>

void fillModelWithData(ExampleModel* titanicModel, QString path)
{
    QFile inputFile(path);
    inputFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream inputStream(&inputFile);

    QString firstline = inputStream.readLine();

    while(!inputStream.atEnd())
    {
        QString line = inputStream.readLine();
        
        QList<QString> dataRow;
        for (QString& item : line.split(",")) {
            dataRow.append(item);
        }
        titanicModel->appendRow(dataRow);
    }
    inputFile.close();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    titanicModel = new ExampleModel(this);
    
//    fillModelWithData(titanicModel, "../../data/titanic.csv");
    ui->listView->setModel(titanicModel);
    ui->tableView->setModel(titanicModel);

    ui->listView->setModelColumn(0);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete titanicModel;
}

void MainWindow::onLoadButtonPushed()
{
    QString path = QFileDialog::getOpenFileName(this);
    fillModelWithData(titanicModel, path);
    update();
}

void MainWindow::setListViewColumn(int value)
{
    ui->listView->setModelColumn(value);
}


