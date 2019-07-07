#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class AbstractCompleter;
struct DictionaryItem;

class Widget : public QWidget {
  Q_OBJECT

public:
  explicit Widget(QWidget *parent = nullptr);
  ~Widget();

private:
  void showSelectedItem(const DictionaryItem &item);

  Ui::Widget *ui;
  AbstractCompleter *completer;
};

#endif // WIDGET_H
