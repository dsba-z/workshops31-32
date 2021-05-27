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

void saveModelAsFile(ExampleModel* m, QString path)
{
    QFile outFile(path);
    outFile.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&outFile);
    
    for (int i = 0; i < m->rowCount(); ++i)
    {
        for (int j = 0; j < m->columnCount(); ++j)
        {
            QModelIndex idx = m->index(i, j);
            out << m->data(idx).toString();
            if (j != m->columnCount() - 1)
            {
                out << ",";
            }
        }
        out << "\n";
    }
    outFile.close();
}


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
    fillModelWithData(titanicModel, path);
}

void MainWindow::setListViewColumn(int value)
{
    ui->listView->setModelColumn(value);
}

void MainWindow::onDeleteButtonClicked()
{
    if (ui->spinBox_2->value() > 0)
    {
        titanicModel->deleteRow(ui->spinBox_2->value() - 1);
    }
}
