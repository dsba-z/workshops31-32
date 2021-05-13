#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QWidget>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QList>

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    titanicModel = new QStandardItemModel(this);
    
    ui->listView->setModel(titanicModel);
    ui->tableView->setModel(titanicModel);
    
    
    QFile inputFile("../../data/titanic.csv");
    if(!inputFile.open(QFile::ReadOnly | QFile::Text))
    {
        std::cerr << "Cannot open file\n";
    }
    // QFileDialog
    QTextStream inputStream(&inputFile);
    
    QString firstline = inputStream.readLine();
    titanicModel->setHorizontalHeaderLabels(firstline.split(","));
    
    while(!inputStream.atEnd())
    {
        QString line = inputStream.readLine();
        
        QList<QStandardItem*> row;
        for (QString& word : line.split(","))
        {
            row.append(new QStandardItem(word));
        }
        titanicModel->appendRow(row);
    }
    ui->listView->setModelColumn(3);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete titanicModel;
}

