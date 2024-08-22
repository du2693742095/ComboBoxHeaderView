#ifndef CUSTOMHEADVIEW_H
#define CUSTOMHEADVIEW_H

#include <QHeaderView>
#include <QCheckBox>

class CustomHeader: public QHeaderView
{
public:
    CustomHeader(Qt::Orientation orientation, QWidget *parent);
    ~CustomHeader();

protected:
    void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const override;

signals:
    void checked(bool isChecked);

private:
    QCheckBox* m_checkBox;
};

#endif // CUSTOMHEADVIEW_H
