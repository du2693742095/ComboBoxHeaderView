#ifndef CUSTOMHEADVIEW_H
#define CUSTOMHEADVIEW_H

#include <QHeaderView>
#include <QVector>
#include <QLabel>

class QComboBox;
class CustomHeader: public QHeaderView
{
public:
    CustomHeader(Qt::Orientation orientation, QWidget *parent);
    ~CustomHeader();

    void setHeaders(const QStringList& headers);

protected:
    void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const override;

private:
    void drawColCombo();

private slots:


private:
    QVector<QWidget*> m_vFirstCol;
    //QWidget* m_pFirstCol;
    QVector<QLabel*> m_vHeads;
    QVector<QComboBox*> m_vComboBoxs;
};

#endif // CUSTOMHEADVIEW_H
