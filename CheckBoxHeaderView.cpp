#include "CheckBoxHeaderView.h"

CheckBoxHeaderView::CheckBoxHeaderView(Qt::Orientation orientation, QWidget *parent)
    : QHeaderView(orientation, parent),
      m_checkBox(new QCheckBox(this))
{
    m_checkBox->setVisible(true);
    connect(m_checkBox, &QAbstractButton::clicked, this, &CheckBoxHeaderView::checked);
}

CheckBoxHeaderView::~CheckBoxHeaderView()
{
}

void CheckBoxHeaderView::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
{
    m_checkBox->move(sectionPosition(0) + 3, 6);
}

