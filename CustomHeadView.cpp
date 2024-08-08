#include "CustomHeadView.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>

CustomHeader::CustomHeader(Qt::Orientation orientation, QWidget *parent)
    : QHeaderView(orientation, parent)
{
    // 创建一个QWidget
//    m_pFirstCol = new QWidget((QWidget*)this);

//    // 添加布局
//    QHBoxLayout *pLayout = new QHBoxLayout(m_pFirstCol);
//    pLayout->setContentsMargins(0, 0, 0, 0);
//    pLayout->setSpacing(0);

//    QHBoxLayout *pLayout = new QHBoxLayout(this);
//    m_pFirstCol = new QWidget(this);
//    pLayout->addWidget(m_pFirstCol);
//        pLayout->setContentsMargins(0, 0, 0, 0);
//        pLayout->setSpacing(0);

//    // QLabel 用于显示列名
//    QLabel *pName = new QLabel(m_pFirstCol);
//    pName->setText("LotID");
//    pLayout->addWidget(pName);

//    // 添加一个下拉框
//    QComboBox *pComboBox = new QComboBox(m_pFirstCol);
//    pLayout->addWidget(pComboBox);


//    pComboBox->addItem("A");
//    pComboBox->addItem("B");

    connect(this, &QHeaderView::headerDataChanged(), this, )
}

CustomHeader::~CustomHeader()
{

}

void CustomHeader::setHeaders(const QStringList& headers)
{
    for (auto& head: headers) {
        m_vHeads.push_back(new QLabel(head));
    }
}

void CustomHeader::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
{
    if (logicalIndex == 0)
    {
        m_pFirstCol->setGeometry(rect); // 第一列特殊处理
    }
    else
    {
        QHeaderView::paintSection(painter, rect, logicalIndex);
    }
}

