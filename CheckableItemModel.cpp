#include "CheckableItemModel.h"
#include <QFont>
#include <QBrush>

CheckableItemModel::CheckableItemModel(QAbstractItemModel *parent)
    : QAbstractItemModel(parent)
{

}



CheckableItemModel::~CheckableItemModel()
{
}


void CheckableItemModel::setHorHeaderData(const QList<QString> &headers)
{
    m_horHeaderData = headers;
    emit headerDataChanged(Qt::Horizontal, 0, headers.count() - 1);
}


QVariant CheckableItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal){
        //这里我们只设置居中对齐和文本
        if (role == Qt::DisplayRole){
            //这里把横项列表头的文本设计为可以设置的
            if(section >= 0 && section < m_horHeaderData.count())
                return m_horHeaderData.at(section);
            return QString("Col %1").arg(section + 1);
        }else if(role == Qt::TextAlignmentRole){
            return Qt::AlignCenter;
        }
    }else{
        if (role == Qt::DisplayRole)
            return QString(section + 1);
        else if(role == Qt::TextAlignmentRole)
            return Qt::AlignCenter;
    }
    return QVariant();
}

bool CheckableItemModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    //设计为横项列表头可以设置
    if (orientation == Qt::Horizontal && section>=0 && section<m_horHeaderData.count()) {
        if(role == Qt::EditRole)
            m_horHeaderData[section] = value.toString();
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

QVariant CheckableItemModel::data(const QModelIndex &index, int role /*= Qt::DisplayRole*/) const
{
    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        return m_stringList.at(index.row()).at(index.column());
    case Qt::FontRole:
        return QFont("consolas", 9, 9);
    case Qt::TextAlignmentRole:
        return Qt::AlignCenter;
    case Qt::ForegroundRole:
        return QBrush(Qt::blue);
     case Qt::CheckStateRole:
        if (index.column() == 0)
            return m_checkStatus.value(index.row());
    }
    return QVariant();
}

int CheckableItemModel::rowCount(const QModelIndex &parent /*= QModelIndex()*/) const
{
    return m_stringList.count();
}

int CheckableItemModel::columnCount(const QModelIndex &parent /*= QModelIndex()*/) const
{
    return m_columnCount;
}

void CheckableItemModel::setSize(const int row, const int column)
{
    if(row > rowCount())
    {
        m_stringList.resize(row);
    }
    if(column > columnCount())
    {

    }
}

bool CheckableItemModel::setData(const QModelIndex &index, const QVariant &value, int role /* = Qt::EditRole */)
{
    if (index.isValid() && role == Qt::EditRole) {
        m_stringList[index.row()].replace(index.column(), value.toString());
        emit dataChanged(index, index, {role});
        return true;
    }
    else if (index.isValid() && role == Qt::CheckStateRole) {
        if(index.column() == 0)
            m_checkStatus.insert(index.row(), static_cast<Qt::CheckState>(value.toInt()));
        emit dataChanged(index, index, {role});
    }
    return QAbstractItemModel::setData(index, value, role);
}

bool CheckableItemModel::setData(const int row, const int colunm, const QVariant& data)
{
    return true;
}


Qt::ItemFlags CheckableItemModel::flags(const QModelIndex &index) const
{
    if (index.column() == 0)
        return QAbstractItemModel::flags(index) | Qt::ItemIsUserCheckable;
        //return QAbstractItemModel::flags(index);
    else
        return QAbstractItemModel::flags(index);
}

void CheckableItemModel::checkAll(Qt::CheckState state)
{
    for (int i = 0; i < rowCount(); ++i) {
        m_checkStatus.insert(i, state);
    }
}

void CheckableItemModel::onItemSelected(const QItemSelection &selected, const QItemSelection &deselected)
{
    QModelIndexList selectedModels = selected.indexes();
    QModelIndexList deselectedModels = deselected.indexes();

    foreach(auto &model, selectedModels) {
        m_checkStatus.insert(model.row(), Qt::Checked);
    }

    foreach(auto &model, deselectedModels) {
        m_checkStatus.insert(model.row(), Qt::Unchecked);
    }
}
