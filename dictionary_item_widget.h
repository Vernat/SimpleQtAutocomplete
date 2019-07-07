#ifndef DICTIONARY_ITEM_WIDGET_H
#define DICTIONARY_ITEM_WIDGET_H

#include "dictionary_item.h"
#include <QWidget>

namespace Ui {
class DictionaryItemWidget;
}

const int DICTIONARY_WIDGET_HEIGHT = 24;
const int DICTIONARY_WIDGET_WIDTH = 400;

class DictionaryItemWidget : public QWidget {
  Q_OBJECT

public:
  explicit DictionaryItemWidget(const DictionaryItem &item,
                                QWidget *parent = nullptr);
  ~DictionaryItemWidget();

  QString name() const;

protected:
  void enterEvent(QEvent *event);
  void leaveEvent(QEvent *event);

private:
  void changeTextColor(const Qt::GlobalColor color);

  Ui::DictionaryItemWidget *ui;
  DictionaryItem item;
};

#endif // DICTIONARY_ITEM_WIDGET_H
