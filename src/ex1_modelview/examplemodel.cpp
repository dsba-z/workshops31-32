#include "examplemodel.h"
#include <QBrush>
#include <QFile>
#include <QTextStream>

#include <iostream>

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
    headerList = firstline.split(",");

    while(!inputStream.atEnd())
    {
        QString line = inputStream.readLine();
        
        QList<QVariant> dataRow;
        for (QString& item : line.split(",")) {
            bool ok = false;
            QVariant itemnum = item.toInt(&ok);
            if (ok)
            {
                dataRow.append(itemnum);
                continue;
            }
            itemnum = item.toDouble(&ok);
            if (ok)
            {
                dataRow.append(itemnum);
                continue;
            }
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
    
    for (int j = 0; j < columnCount(); ++j)
    {
        out << headerList.at(j);
        if (j != columnCount() - 1)
        {
            out << ",";
        }
    }
    out << "\n";
    
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

QVariant ExampleModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Orientation::Horizontal)
    {
        std::cerr << section << "\n";
    }
    if (role == Qt::DisplayRole && !headerList.empty() && section >= 0)
    {
        if (orientation == Qt::Orientation::Horizontal && section < 12)
        {
            return headerList.at(section);
        }
        else
        {
            return section + 1;
        }
    }
    return QVariant();
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


void ExampleModel::appendRow(QList<QVariant> newRow)
{
    bool columnFlag = false;
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    if (exampleData.isEmpty())
    {
        columnFlag = true;
        std::cerr << newRow.size() << "\n";
        beginInsertColumns(QModelIndex(), 0, newRow.size() - 1);
    }
    exampleData.append(newRow);

    
    if (columnFlag)
    {
        endInsertColumns();
    }
    endInsertRows();
}


void ExampleModel::deleteRow(int idx)
{
    beginRemoveRows(QModelIndex(), idx, idx);
    exampleData.removeAt(idx);
    endRemoveRows();
}

