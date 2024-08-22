#ifndef CHECKABLEITEMVIEW_H
#define CHECKABLEITEMVIEW_H

#include <QAbstractItemModel>
#include <QItemSelection>

class CheckableItemModel: public QAbstractItemModel
{
    Q_OBJECT
public:
    CheckableItemModel(QAbstractItemModel *parent = 0);
    ~CheckableItemModel();

    void setHorHeaderData(const QList<QString> &headers);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

protected:
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    void setSize(const int row, const int column);

    bool setData(const QModelIndex &index, const QVariant &value, int role /* = Qt::EditRole */) Q_DECL_OVERRIDE;
    bool setData(const int row, const int colunm, const QVariant& data);
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;

public slots:
    void checkAll(Qt::CheckState);
    void onItemSelected(const QItemSelection &selected, const QItemSelection &deselected);

private:
    QVector<QVector<QString>> m_stringList;
    QMap<int, Qt::CheckState> m_checkStatus;
    QStringList m_horHeaderData;
    int m_columnCount;
};

#endif // CHECKABLEITEMVIEW_H
