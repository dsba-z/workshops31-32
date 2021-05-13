#include "examplemodel.h"

ExampleModel::ExampleModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    exampleData[0][0] = QString("Top left");
}

int ExampleModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return ROWS;
}

int ExampleModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    
    return COLUMNS;
}

QVariant ExampleModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    
    if (role == Qt::DisplayRole)
    {
        int row = index.row();
        int column = index.column();
        
        return exampleData[row][column];
    }
    return QVariant();
}
