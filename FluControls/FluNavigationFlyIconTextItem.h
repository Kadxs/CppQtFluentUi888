#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include "FluNavigationItem.h"
#include <vector>
#include "FluVScrollView.h"

#include <QPaintEvent>
#include <QStyleOption>
#include <QPainter>

class FluNavigationIconTextItem;
class FluNavigationFlyIconTextItem : public QWidget
{
    Q_OBJECT
  public:
      FluNavigationFlyIconTextItem(QWidget* parent = nullptr);

      void setIconTextItems(std::vector<FluNavigationIconTextItem*> items);

      void adjustItemSize();

      // to enable qss
      void paintEvent(QPaintEvent* event)
      {
          QStyleOption opt;
          opt.initFrom(this);
          QPainter painter(this);
          style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
      }

  protected:
      QVBoxLayout* m_vMainLayout;
      
      FluVScrollView* m_widget;
      //QVBoxLayout* m_vCenterLayout;
      std::vector<FluNavigationIconTextItem*> m_items;
};