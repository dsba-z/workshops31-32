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
    
}

MainWindow::~MainWindow()
{
    delete ui;
    delete titanicModel;
}

