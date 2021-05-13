#ifndef EXAMPLEMODEL_H
#define EXAMPLEMODEL_H

#include <QAbstractTableModel>

const int ROWS = 3;
const int COLUMNS = 2;

class ExampleModel : public QAbstractTableModel
{
    Q_OBJECT
    
public:
    explicit ExampleModel(QObject *parent = nullptr);
    
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    
private:
    QString exampleData[ROWS][COLUMNS];
};

#endif // EXAMPLEMODEL_H
