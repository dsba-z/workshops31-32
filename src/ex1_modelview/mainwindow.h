#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTransposeProxyModel>
#include <QSortFilterProxyModel>

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
    void onDeleteButtonClicked();
    void on_actionAbout_triggered();
    
    void on_tableView_clicked(const QModelIndex &index);
    void onTableViewCurrentChanged(QModelIndex prev, QModelIndex next);
    
    void on_pushButton_3_clicked();
    
private:
    Ui::MainWindow *ui;
    ExampleModel *titanicModel;
    QTransposeProxyModel *tmodel;
    QSortFilterProxyModel *sortModel;
};

#endif // MAINWINDOW_H
