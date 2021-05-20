#include "examplemodel.h"

ExampleModel::ExampleModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int ExampleModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    
    return exampleData.size();
}

int ExampleModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    
    if (exampleData.empty())
    {
        return 0;
    }
    return exampleData[0].size();
}

QVariant ExampleModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    
    if (role == Qt::DisplayRole)
    {
        int row = index.row();
        int column = index.column();
        
        return exampleData.at(row).at(column);
    }
    return QVariant();
}

void ExampleModel::appendRow(QList<QString> newRow)
{
    bool columnFlag = false;
    if (exampleData.isEmpty())
    {
        columnFlag = true;
        beginInsertColumns(QModelIndex(), 0, newRow.size());
    }
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    exampleData.append(newRow);
    endInsertRows();
    
    if (columnFlag)
    {
        endInsertColumns();
    }
    
}

