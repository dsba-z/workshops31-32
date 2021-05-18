#ifndef EXAMPLEMODEL_H
#define EXAMPLEMODEL_H

#include <QAbstractTableModel>
#include <QList>


class ExampleModel : public QAbstractTableModel
{
    Q_OBJECT
    
public:
    explicit ExampleModel(QObject *parent = nullptr);
    
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void appendRow(QList<QString> newRow);

private:
    QList<QList<QString> > exampleData;
};

#endif // EXAMPLEMODEL_H
