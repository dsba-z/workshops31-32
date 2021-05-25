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

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    
    void deleteRow(int idx);
    
private:
    QList<QList<QString> > exampleData;
signals:
    void editCompleted(const QString &);
};

#endif // EXAMPLEMODEL_H
