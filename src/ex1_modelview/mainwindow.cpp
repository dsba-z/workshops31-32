#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "aboutdialog.h"

#include <QWidget>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QFileDialog>

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    titanicModel = new ExampleModel(this);
    
//    fillModelWithData(titanicModel, "../../data/titanic.csv");

    ui->listView->setModelColumn(0);
    
    tmodel = new QTransposeProxyModel(this);
    tmodel->setSourceModel(titanicModel);
    
    ui->listView->setModel(tmodel);
    
    ui->tableView->setModel(titanicModel);
    
    
    connect(ui->tableView->selectionModel(),
            SIGNAL(currentChanged(QModelIndex,QModelIndex)),
            this,
            SLOT(onTableViewCurrentChanged(QModelIndex,QModelIndex)));
}


void MainWindow::onTableViewCurrentChanged(QModelIndex next, QModelIndex prev)
{
    int row = next.row();
    ui->listView->setModelColumn(row);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete titanicModel;
    delete tmodel;
}

void MainWindow::onLoadButtonPushed()
{
    QString path = QFileDialog::getOpenFileName(this);
    titanicModel->fillModelWithData(path);
}

void MainWindow::setListViewColumn(int value)
{
    ui->listView->setModelColumn(value);
}

void MainWindow::onDeleteButtonClicked()
{
    QModelIndex idx = ui->tableView->currentIndex();
    int row = idx.row();
    titanicModel->deleteRow(row);
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog dialog;
    dialog.exec();
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int row = index.row();
    ui->listView->setModelColumn(row);
}

