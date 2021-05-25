#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTransposeProxyModel>

#include "examplemodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoadButtonPushed();
    void setListViewColumn(int value);

private:
    Ui::MainWindow *ui;
    ExampleModel *titanicModel;
    QTransposeProxyModel *tmodel;
};

#endif // MAINWINDOW_H
