#include "examplemodel.h"
#include <QBrush>
#include <QFile>
#include <QTextStream>

ExampleModel::ExampleModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

void ExampleModel::fillModelWithData(QString path)
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
        appendRow(dataRow);
    }
    inputFile.close();
}

void ExampleModel::saveModelAsFile(QString path)
{
    QFile outFile(path);
    outFile.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&outFile);
    
    for (int i = 0; i < rowCount(); ++i)
    {
        for (int j = 0; j < columnCount(); ++j)
        {
            QModelIndex idx = index(i, j);
            out << data(idx).toString();
            if (j != columnCount() - 1)
            {
                out << ",";
            }
        }
        out << "\n";
    }
    outFile.close();
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
    int row = index.row();
    int column = index.column();
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        return exampleData.at(row).at(column);
    }
    else if (role == Qt::BackgroundRole)
    {
        
        return QBrush(Qt::gray);
    }
    return QVariant();
}



bool ExampleModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        
        exampleData[index.row()][index.column()] = value.toString();
        return true;
    }
    return false;
}

Qt::ItemFlags ExampleModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}


void ExampleModel::appendRow(QList<QString> newRow)
{
    bool columnFlag = false;
    if (exampleData.isEmpty())
    {
        columnFlag = true;
        beginInsertColumns(QModelIndex(), 0, newRow.size() - 1);
    }
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    exampleData.append(newRow);
    endInsertRows();
    
    if (columnFlag)
    {
        endInsertColumns();
    }
}


void ExampleModel::deleteRow(int idx)
{
    beginRemoveRows(QModelIndex(), idx, idx);
    exampleData.removeAt(idx);
    endRemoveRows();
}

